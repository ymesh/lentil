#pragma once

#include "spectrum.h"
#include "lenssystem.h"
#include <stdio.h>
#include <strings.h>
#include <vector>

#define max(a, b) ((a)>(b)?(a):(b))

#define INTENSITY_EPS 1e-5

static inline float raytrace_dot(const float *u, const float *v)
{
  return ((u)[0]*(v)[0] + (u)[1]*(v)[1] + (u)[2]*(v)[2]);
}

static inline void raytrace_cross(float *r, const float *u, const float *v)
{
  r[0] = u[1]*v[2]-u[2]*v[1];
  r[1] = u[2]*v[0]-u[0]*v[2];
  r[2] = u[0]*v[1]-u[1]*v[0];
}

static inline void raytrace_normalise(float *v)
{
  const float ilen = 1.0f/sqrtf(raytrace_dot(v,v));
  for(int k=0;k<3;k++) v[k] *= ilen;
}

//u = u - v
static inline void raytrace_substract(float *u, const float *v)
{
  for(int k = 0; k < 3; k++) u[k] -= v[k];
}

//v = s * v
static inline void raytrace_multiply(float *v, const float s)
{
  for(int k = 0; k < 3; k++) v[k] *= s;
}

static inline void propagate(float *pos, const float *dir, const float dist)
{
  for(int i=0;i<3;i++) pos[i] += dir[i] * dist;
}


static inline int spherical(float *pos, float *dir, float *dist, float R, float center, float housing_rad, float *normal)
{
  const float scv[3] = {pos[0], pos[1], pos[2] - center};
  const float a = raytrace_dot(dir, dir);
  const float b = 2 * raytrace_dot(dir, scv);
  const float c = raytrace_dot(scv, scv) - R*R;
  const float discr = b*b-4*a*c;
  if(discr < 0.0f) return 4;
  int error = 0;
  float t = 0.0f;
  const float t0 = (-b-sqrtf(discr))/(2*a);
  const float t1 = (-b+sqrtf(discr))/(2*a);
  if(t0 < -1e-4f) t = t1;
  else t = fminf(t0, t1);
  if(t < -1e-4f) return 16;

  propagate(pos, dir, t);
  error |= (int)(pos[0]*pos[0] + pos[1]*pos[1] > housing_rad*housing_rad)<<4;

  normal[0] = pos[0]/R;
  normal[1] = pos[1]/R;
  normal[2] = (pos[2] - center)/R;

  *dist = t;
  return error;
}

static inline float evaluate_aspherical(const float *pos, const float R, const int k, const float *correction)
{
  float h = sqrtf(pos[0]*pos[0]+pos[1]*pos[1]);
  float hr = h / R;
  float h2 = h*h;
  float h4 = h2*h2;
  float h6 = h4*h2;
  float h8 = h4*h4;
  float h10 = h8*h2;
  float z = h*hr/(1+sqrtf(max(0.0,1-(1+k)*hr*hr)))+correction[0]*h4+correction[1]*h6+correction[2]*h8+correction[3]*h10;
  return z;
}

static inline float evaluate_aspherical_derivative(const float *pos, const float R, const int k, const float *correction)
{
  float h = sqrtf(pos[0]*pos[0]+pos[1]*pos[1]);
  float hr = h / R;
  float h2 = h*h;
  float h3 = h2*h;
  float h5 = h3*h2;
  float h7 = h5*h2;
  float h9 = h7*h2;
  float z = 2*hr/(1+sqrtf(max(0.0,1-(1+k)*hr*hr)))+
    hr*hr*hr*(k+1)/(sqrtf(max(0.0,1-(1+k)*hr*hr))*powf(sqrtf(max(0.0,1-(1+k)*hr*hr))+1, 2))+
    4*correction[0]*h3+6*correction[1]*h5+8*correction[2]*h7+10*correction[3]*h9;
  return z;
}

static inline int aspherical(float *pos, float *dir, float *dist, const float R, const float center, const int k, const float *correction, const float housing_rad, float *normal)
{
  //first intersect sphere, then do correction iteratively
  float t = 0;
  int error = spherical(pos, dir, &t, R, center, housing_rad, normal);

  float rad = R;
  float corr[4] = {correction[0], correction[1], correction[2], correction[3]};
  if(fabs(center+R-pos[2]) > fabs(center-R-pos[2]))
  {
    rad = -R;
    for(int i = 0; i < 4; i++) corr[i] = -corr[i];
  }

  float position_error = 1e7;


  for(int i = 0; i < 100; i++)
  {
    position_error = rad+center-pos[2]-evaluate_aspherical(pos, rad, k, correction);
    float tErr = position_error/dir[2];
    t += tErr;
    propagate(pos, dir, tErr);
    if(fabs(position_error) < 1e-4) break;
  }


  float dz = evaluate_aspherical_derivative(pos, rad, k, correction);
  const float r = sqrt(pos[0]*pos[0]+pos[1]*pos[1]);

  if(normal[2] < 0) dz = -dz;
  normal[0] = pos[0]/r*dz;
  normal[1] = pos[1]/r*dz;
  normal[2] /= fabs(normal[2]);

  raytrace_normalise(normal);

  *dist = t;
  return error;
}


static inline int cylindrical(float *pos, float *dir, float *dist, float R, float center, float housing_rad, float *normal, bool cyl_y)
{
  float scv[3] = {0.0, 0.0, 0.0};

  if (cyl_y){
    scv[0] = pos[0];
    scv[1] = 0.0f;
    scv[2] = pos[2] - center;
  } else {
    scv[0] = 0.0f;
    scv[1] = pos[1];
    scv[2] = pos[2] - center;
  }

  const float a = raytrace_dot(dir, dir);
  const float b = 2 * raytrace_dot(dir, scv);
  const float c = raytrace_dot(scv, scv) - R*R;
  
  const float discr = b*b-4*a*c;
  if(discr < 0.0f) return 4;
  int error = 0;

  float t = 0.0f;
  if(R > 0.0f)      t = (-b-sqrtf(discr))/(2*a);
  else if(R < 0.0f) t = (-b+sqrtf(discr))/(2*a);

  propagate(pos, dir, t);
  error |= (int)(pos[0]*pos[0] + pos[1]*pos[1] > housing_rad*housing_rad)<<4;

  if (cyl_y){
    normal[0] = pos[0]/R;
    normal[1] = 0.0f;
    normal[2] = (pos[2] - center)/R;
  } else {
    normal[0] = 0.0f;
    normal[1] = pos[1]/R;
    normal[2] = (pos[2] - center)/R;
  }

  *dist = t;
  return error;
}


static inline float fresnel(const float n1, const float n2, const float cosr, const float cost)
{
  if(cost <= 0.0f) return 1.0f; // total inner reflection
  // fresnel for unpolarized light:
  const float Rs = (n1*cosr - n2*cost)/(n1*cosr + n2*cost);
  const float Rp = (n1*cost - n2*cosr)/(n1*cost + n2*cosr);
  return fminf(1.0f, (Rs*Rs + Rp*Rp)*.5f);
}

static inline float refract(const float n1, const float n2, const float *n, float *dir)
{
  if(n1 == n2)
    return 1;
  const float eta = n1/n2;

  const float norm = sqrtf(raytrace_dot(dir,dir));
  const float cos1 = - raytrace_dot(n, dir)/norm;
  const float cos2_2 = 1.0f-eta*eta*(1.0f-cos1*cos1);
  // total (inner) reflection?
  if(cos2_2 < 0.0f)
    return 0;
  const float cos2 = sqrtf(cos2_2);

  for(int i=0;i<3;i++) dir[i] = dir[i]*eta/norm + (eta*cos1-cos2)*n[i];

  return 1.0f-fresnel(n1, n2, cos1, cos2);
}

static inline void planeToCs(const float *inpos, const float *indir, float *outpos, float *outdir, const float planepos)
{
  outpos[0] = inpos[0];
  outpos[1] = inpos[1];
  outpos[2] = planepos;

  outdir[0] = indir[0];
  outdir[1] = indir[1];
  outdir[2] = 1;

  raytrace_normalise(outdir);
}

static inline void csToPlane(const float *inpos, const float *indir, float *outpos, float *outdir, const float planepos)
{
  //intersection with plane at z = planepos
  const double t = (planepos - inpos[2]) / indir[2];

  outpos[0] = inpos[0] + t * indir[0];
  outpos[1] = inpos[1] + t * indir[1];

  outdir[0] = indir[0] / fabsf(indir[2]);
  outdir[1] = indir[1] / fabsf(indir[2]);
}

static inline void sphereToCs(const float *inpos, const float *indir, float *outpos, float *outdir, const float sphereCenter, const float sphereRad)
{
  const float normal[3] =
  {
    inpos[0]/sphereRad,
    inpos[1]/sphereRad,
    sqrtf(max(0, sphereRad*sphereRad-inpos[0]*inpos[0]-inpos[1]*inpos[1]))/fabsf(sphereRad)
  };
  const float tempDir[3] = {indir[0], indir[1], sqrtf(max(0.0, 1.0f-indir[0]*indir[0]-indir[1]*indir[1]))};

  float ex[3] = {normal[2], 0, -normal[0]};
  raytrace_normalise(ex);
  float ey[3];
  raytrace_cross(ey, normal, ex);

  outdir[0] = tempDir[0] * ex[0] + tempDir[1] * ey[0] + tempDir[2] * normal[0];
  outdir[1] = tempDir[0] * ex[1] + tempDir[1] * ey[1] + tempDir[2] * normal[1];
  outdir[2] = tempDir[0] * ex[2] + tempDir[1] * ey[2] + tempDir[2] * normal[2];
  outpos[0] = inpos[0];
  outpos[1] = inpos[1];
  outpos[2] = normal[2] * sphereRad + sphereCenter;
}

static inline void csToSphere(const float *inpos, const float *indir, float *outpos, float *outdir, const float sphereCenter, const float sphereRad)
{
  const float normal[3] =
  {
    inpos[0]/sphereRad,
    inpos[1]/sphereRad,
    fabsf((inpos[2]-sphereCenter)/sphereRad)
  };
  float tempDir[3] = {indir[0], indir[1], indir[2]};
  raytrace_normalise(tempDir);

  // tangent
  float ex[3] = {normal[2], 0, -normal[0]};
  raytrace_normalise(ex);
  
  // bitangent
  float ey[3];
  raytrace_cross(ey, normal, ex);
  
  // store ray direction as projected position on unit disk perpendicular to the normal
  outdir[0] = raytrace_dot(tempDir, ex);
  outdir[1] = raytrace_dot(tempDir, ey);
  outpos[0] = inpos[0];
  outpos[1] = inpos[1];
}

// untested and probably wrong
static inline void csToCylinder(const float *inpos, const float *indir, float *outpos, float *outdir, const float center, const float R, bool cyl_y)
{
  float normal[3] = {0.0f};
  if (cyl_y){
    normal[0] = inpos[0]/R;
    normal[1] = 0.0f;
    normal[2] = fabsf((inpos[2] - center)/R);
  } else {
    normal[0] = 0.0f;
    normal[1] = inpos[1]/R;
    normal[2] = fabsf((inpos[2] - center)/R);
  }
  float tempDir[3] = {indir[0], indir[1], indir[2]};
  raytrace_normalise(tempDir);

  // tangent
  float ex[3] = {normal[2], 0, -normal[0]};
  raytrace_normalise(ex);
  
  // bitangent
  float ey[3];
  raytrace_cross(ey, normal, ex);
  
  // store ray direction as projected position on unit disk perpendicular to the normal
  outdir[0] = raytrace_dot(tempDir, ex);
  outdir[1] = raytrace_dot(tempDir, ey);
  outpos[0] = inpos[0];
  outpos[1] = inpos[1];
}

// untested and probably wrong
static inline void cylinderToCs(const float *inpos, const float *indir, float *outpos, float *outdir, const float center, const float R, bool cyl_y)
{
  float normal[3] = {0.0f};
  if (cyl_y){
    normal[0] = inpos[0]/R;
    normal[1] = 0.0f;
    normal[2] = sqrtf(max(0, R*R-inpos[0]*inpos[0]-inpos[1]*inpos[1]))/fabsf(R);
  } else {
    normal[0] = 0.0f;
    normal[1] = inpos[1]/R;
    normal[2] = sqrtf(max(0, R*R-inpos[0]*inpos[0]-inpos[1]*inpos[1]))/fabsf(R);
  }

  const float tempDir[3] = {indir[0], indir[1], sqrtf(max(0.0, 1.0f-indir[0]*indir[0]-indir[1]*indir[1]))};

  float ex[3] = {normal[2], 0, -normal[0]};
  raytrace_normalise(ex);
  float ey[3];
  raytrace_cross(ey, normal, ex);

  outdir[0] = tempDir[0] * ex[0] + tempDir[1] * ey[0] + tempDir[2] * normal[0];
  outdir[1] = tempDir[0] * ex[1] + tempDir[1] * ey[1] + tempDir[2] * normal[1];
  outdir[2] = tempDir[0] * ex[2] + tempDir[1] * ey[2] + tempDir[2] * normal[2];
  outpos[0] = inpos[0];
  outpos[1] = inpos[1];
  outpos[2] = normal[2] * R + center;
}


// evalute sensor to outer pupil acounting for fresnel:
static inline int evaluate(const lens_element_t *lenses, const int lenses_cnt, const float zoom, const float *in, float *out, int aspheric)
{
  int error = 0;
  float n1 = spectrum_eta_from_abbe_um(lenses[lenses_cnt-1].ior, lenses[lenses_cnt-1].vno, in[4]);
  float pos[3], dir[3];
  float intensity = 1.0f;

  planeToCs(in, in + 2, pos, dir, 0);

  float distsum = 0;

  for(int k=lenses_cnt-1;k>=0;k--)
  {
    // propagate the ray reverse to the plane of intersection optical axis/lens element:
    const float R = -lenses[k].lens_radius; // negative, evaluate() is the adjoint case
    float t = 0.0f;
    const float dist = lens_get_thickness(lenses+k, zoom);
    distsum += dist;

    //normal at intersection
    float n[3] = {0.0f};

    if(strcmp(lenses[k].geometry, "cyl-y") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, true);
    }
    else if (strcmp(lenses[k].geometry, "cyl-x") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, false);
    }
    else if(strcmp(lenses[k].geometry, "aspherical") == 0){
      error |= aspherical(pos, dir, &t, R, distsum + R, lenses[k].aspheric, lenses[k].aspheric_correction_coefficients, lenses[k].housing_radius, n);
    }
    else {
      error |= spherical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n);
    }

    // index of refraction and ratio current/next:
    const float n2 = k ? spectrum_eta_from_abbe_um(lenses[k-1].ior, lenses[k-1].vno, in[4]) : 1.0f; // outside the lens there is vacuum

    intensity *= refract(n1, n2, n, dir);
    if(intensity < INTENSITY_EPS) error |= 8;
    if(error) return error;

    raytrace_normalise(dir);

    n1 = n2;
  }
  // return [x,y,dx,dy,lambda]
  if (strcmp(lenses[0].geometry, "cyl-y") == 0) csToCylinder(pos, dir, out, out + 2, distsum-fabs(lenses[0].lens_radius), lenses[0].lens_radius, true);
  else if (strcmp(lenses[0].geometry, "cyl-x") == 0) csToCylinder(pos, dir, out, out + 2, distsum-fabs(lenses[0].lens_radius), lenses[0].lens_radius, false);
  else csToSphere(pos, dir, out, out + 2, distsum-fabs(lenses[0].lens_radius), lenses[0].lens_radius);
  out[4] = intensity;
  return error;
}


// evalute sensor to outer pupil acounting for fresnel:
static inline int evaluate_for_pos_dir(const lens_element_t *lenses, const int lenses_cnt, const float zoom, const float *in, float *out, int aspheric, float *pos, float *dir)
{
  int error = 0;
  float n1 = spectrum_eta_from_abbe_um(lenses[lenses_cnt-1].ior, lenses[lenses_cnt-1].vno, in[4]);
  float intensity = 1.0f;

  planeToCs(in, in + 2, pos, dir, 0);

  float distsum = 0;

  for(int k=lenses_cnt-1;k>=0;k--)
  {
    // propagate the ray reverse to the plane of intersection optical axis/lens element:
    const float R = -lenses[k].lens_radius; // negative, evaluate() is the adjoint case
    float t = 0.0f;
    const float dist = lens_get_thickness(lenses+k, zoom);
    distsum += dist;

    //normal at intersection
    float n[3] = {0.0f};

    if(strcmp(lenses[k].geometry, "cyl-y") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, true);
    }
    else if (strcmp(lenses[k].geometry, "cyl-x") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, false);
    }
    else if(strcmp(lenses[k].geometry, "aspherical") == 0){
      error |= aspherical(pos, dir, &t, R, distsum + R, lenses[k].aspheric, lenses[k].aspheric_correction_coefficients, lenses[k].housing_radius, n);
    }
    else {
      error |= spherical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n);
    }

    // index of refraction and ratio current/next:
    const float n2 = k ? spectrum_eta_from_abbe_um(lenses[k-1].ior, lenses[k-1].vno, in[4]) : 1.0f; // outside the lens there is vacuum

    intensity *= refract(n1, n2, n, dir);
    if(intensity < INTENSITY_EPS) error |= 8;
    if(error) return error;

    raytrace_normalise(dir);

    n1 = n2;
  }

  /*
  // return [x,y,dx,dy,lambda]
  if (strcmp(lenses[0].geometry, "cyl-y") == 0) csToCylinder(pos, dir, out, out + 2, distsum-fabs(lenses[0].lens_radius), lenses[0].lens_radius, true);
  else if (strcmp(lenses[0].geometry, "cyl-x") == 0) csToCylinder(pos, dir, out, out + 2, distsum-fabs(lenses[0].lens_radius), lenses[0].lens_radius, false);
  else csToSphere(pos, dir, out, out + 2, distsum-fabs(lenses[0].lens_radius), lenses[0].lens_radius);
  */
 
  out[4] = intensity;
  return error;
}


// evaluate scene to sensor:
static inline int evaluate_reverse(const lens_element_t *lenses, const int lenses_cnt, const float zoom, const float *in, float *out, int aspheric)
{
  int error = 0;
  float n1 = 1.0f;
  float pos[3], dir[3];
  float intensity = 1.0f;

  if (strcmp(lenses[0].geometry, "cyl-y") == 0) cylinderToCs(in, in + 2, pos, dir, 0, lenses[0].lens_radius, true);
  else if (strcmp(lenses[0].geometry, "cyl-x") == 0) cylinderToCs(in, in + 2, pos, dir, 0, lenses[0].lens_radius, false);
  else sphereToCs(in, in + 2, pos, dir, 0, lenses[0].lens_radius);

  for(int i = 0; i < 2; i++) dir[i] = -dir[i];

  float distsum = 0;

  for(int k=0;k<lenses_cnt;k++)
  {
    const float R = lenses[k].lens_radius;
    float t = 0.0f;
    const float dist = lens_get_thickness(lenses+k, zoom);

    //normal at intersection
    float n[3] = {0.0};

    if (strcmp(lenses[k].geometry, "cyl-y") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, true);
    }
    else if (strcmp(lenses[k].geometry, "cyl-x") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, false);
    }
    else if (aspheric){
      error |= aspherical(pos, dir, &t, R, distsum + R, lenses[k].aspheric, lenses[k].aspheric_correction_coefficients, lenses[k].housing_radius, n);
    }
    else {
      error |= spherical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n);
    }

    // index of refraction and ratio current/next:
    const float n2 = spectrum_eta_from_abbe_um(lenses[k].ior, lenses[k].vno, in[4]);
    intensity *= refract(n1, n2, n, dir);
    if(intensity < INTENSITY_EPS) error |= 8;

    if(error)
      return error;

    // and renormalise:
    raytrace_normalise(dir);

    distsum += dist;
    n1 = n2;
  }
  // return [x,y,dx,dy,lambda]
  csToPlane(pos, dir, out, out + 2, distsum);
  out[4] = intensity;
  return error;
}

static inline int evaluate_aperture(const lens_element_t *lenses, const int lenses_cnt, const float zoom, const float *in, float *out, int aspheric)
{
  int error = 0;
  float n1 = spectrum_eta_from_abbe_um(lenses[lenses_cnt-1].ior, lenses[lenses_cnt-1].vno, in[4]);
  float pos[3], dir[3];
  float intensity = 1.0f;

  planeToCs(in, in + 2, pos, dir, 0);

  float distsum = 0;

  for(int k=lenses_cnt-1;k>=0;k--)
  {
    // propagate the ray reverse to the plane of intersection optical axis/lens element:
    const float R = -lenses[k].lens_radius; // negative, evaluate() is the adjoint case
    float t = 0.0f;
    const float dist = lens_get_thickness(lenses+k, zoom);
    distsum += dist;

    // stop after moving to aperture.
    if(!strcasecmp(lenses[k].material, "iris")) break;

    //normal at intersection
    float n[3] = {0.0f};

    if (strcmp(lenses[k].geometry, "cyl-y") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, true);
    }
    else if (strcmp(lenses[k].geometry, "cyl-x") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, false);
    }
    else if(aspheric) {
      error |= aspherical(pos, dir, &t, R, distsum + R, lenses[k].aspheric, lenses[k].aspheric_correction_coefficients, lenses[k].housing_radius, n);
    }
    else {
      error |= spherical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n);
    }

    // index of refraction and ratio current/next:
    const float n2 = k ? spectrum_eta_from_abbe_um(lenses[k-1].ior, lenses[k-1].vno, in[4]) : 1.0f; // outside the lens there is vacuum
    intensity *= refract(n1, n2, n, dir);
    if(intensity < INTENSITY_EPS) error |= 8;
    if(error)
      return error;

    // mark this ray as theoretically dead:
    //if(dir[2] <= 0.0f) return error |= 2;
    // and renormalise:
    raytrace_normalise(dir);

    n1 = n2;
  }
  // return [x,y,dx,dy,lambda]
  csToPlane(pos, dir, out, out + 2, distsum);
  out[4] = intensity;
  return error;
}

// evaluate scene to sensor:
static inline int evaluate_aperture_reverse(const lens_element_t *lenses, const int lenses_cnt, const float zoom, const float *in, float *out, int aspheric)
{
  int error = 0;
  float n1 = 1.0f;
  float pos[3], dir[3];
  float intensity = 1.0f;

  if (strcmp(lenses[0].geometry, "cyl-y") == 0) cylinderToCs(in, in + 2, pos, dir, 0, lenses[0].lens_radius, true);
  else if (strcmp(lenses[0].geometry, "cyl-x") == 0) cylinderToCs(in, in + 2, pos, dir, 0, lenses[0].lens_radius, false);
  else sphereToCs(in, in + 2, pos, dir, 0, lenses[0].lens_radius);

  for(int i = 0; i < 2; i++) dir[i] = -dir[i];

  float distsum = 0;
  for(int k=0;k<lenses_cnt;k++)
  {
    const float R = lenses[k].lens_radius;
    float t = 0.0f;
    const float dist = lens_get_thickness(lenses+k, zoom);

    //normal at intersection
    float n[3];

    if (strcmp(lenses[k].geometry, "cyl-y") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, true);
    }
    else if (strcmp(lenses[k].geometry, "cyl-x") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, false);
    }
    else if (aspheric){
      error |= aspherical(pos, dir, &t, R, distsum + R, lenses[k].aspheric, lenses[k].aspheric_correction_coefficients, lenses[k].housing_radius, n);
    }
    else {
      error |= spherical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n);
    }

    // index of refraction and ratio current/next:
    const float n2 = spectrum_eta_from_abbe_um(lenses[k].ior, lenses[k].vno, in[4]);
    intensity *= refract(n1, n2, n, dir);
    if(intensity < INTENSITY_EPS) error |= 8;
    if(error)
      return error;

    // and renormalise:
    raytrace_normalise(dir);

    // move to next interface:
    distsum += dist;

    // stop after processing aperture but before moving to next element
    if(k < lenses_cnt-1 && !strcasecmp(lenses[k+1].material, "iris")) break;

    n1 = n2;
  }
  // return [x,y,dx,dy,lambda]
  csToPlane(pos, dir, out, out + 2, distsum);
  out[4] = intensity;
  return error;
}



// line line intersection for finding the principle plane
float lineLineIntersection_x(float line1_origin[3], float line1_direction[3], float line2_origin[3], float line2_direction[3], int dim_up){
    float A1 = line1_direction[dim_up] - line1_origin[dim_up];
    float B1 = line1_origin[2] - line1_direction[2];
    float C1 = A1 * line1_origin[2] + B1 * line1_origin[dim_up];
    float A2 = line2_direction[dim_up] - line2_origin[dim_up];
    float B2 = line2_origin[2] - line2_direction[2];
    float C2 = A2 * line2_origin[2] + B2 * line2_origin[dim_up];
    float delta = A1 * B2 - A2 * B1;
    
    /*
    Eigen::Vector2d rv((B2 * C1 - B1 * C2) / delta, (A1 * C2 - A2 * C1) / delta);
    return rv;
    */

    return (B2 * C1 - B1 * C2) / delta;
}



// evalute sensor to outer pupil:
float calculate_focal_length(const lens_element_t *lenses, const int lenses_cnt, const float zoom, const float *in, float *out, int dim_up, bool draw_aspherical)
{
  int error = 0;
  float n1 = spectrum_eta_from_abbe_um(lenses[lenses_cnt-1].ior, lenses[lenses_cnt-1].vno, in[4]);
  float pos[3], dir[3];
  float intensity = 1.0f;

  planeToCs(in, in + 2, pos, dir, 0);

  float distsum = 0;

  for(int k=lenses_cnt-1;k>=0;k--)
  {
    // propagate the ray reverse to the plane of intersection optical axis/lens element:
    const float R = -lenses[k].lens_radius; // negative, evaluate() is the adjoint case
    float t = 0.0f;
    const float dist = lens_get_thickness(lenses+k, zoom);
    distsum += dist;

    //normal at intersection
    float n[3];
    
    if (strcmp(lenses[k].geometry, "cyl-y") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, true);
    }
    else if (strcmp(lenses[k].geometry, "cyl-x") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n, false);
    }
    else if (draw_aspherical){
      error |= aspherical(pos, dir, &t, R, distsum + R, lenses[k].aspheric, lenses[k].aspheric_correction_coefficients, lenses[k].housing_radius, n);
    }
    else {
      error |= spherical(pos, dir, &t, R, distsum + R, lenses[k].housing_radius, n);
    }

    // index of refraction and ratio current/next:
    const float n2 = k ? spectrum_eta_from_abbe_um(lenses[k-1].ior, lenses[k-1].vno, in[4]) : 1.0f; // outside the lens there is vacuum

    intensity *= refract(n1, n2, n, dir);
    if(intensity < INTENSITY_EPS) error |= 8;

    if(error) return error;

    raytrace_normalise(dir);

    n1 = n2;
  }
  
  // calculate focal length using principal planes
  float pp_line1start[3] = {0.0};
  float pp_line1end[3] = {0.0, 0.0, 99999.0};
  float pp_line2end[3] = {0.0, 0.0, static_cast<float>(pos[2] + (dir[2] * 1000.0))};
  pp_line1start[dim_up] = in[dim_up];
  pp_line1end[dim_up] = in[dim_up];
  pp_line2end[dim_up] = pos[dim_up] + (dir[dim_up] * 1000.0);
  float principlePlaneDistance = lineLineIntersection_x(pp_line1start, pp_line1end, pos, pp_line2end, dim_up);

  float focalPointLineStart[3] = {0.0};
  float focalPointLineEnd[3] = {0.0, 0.0, 99999.0};
  float focalPointDistance = lineLineIntersection_x(focalPointLineStart, focalPointLineEnd, pos, pp_line2end, dim_up);

  return focalPointDistance - principlePlaneDistance;
}



static inline float evaluate_reverse_intersection_y0(const lens_element_t *lenses, const int lenses_cnt, const float zoom, const float *in, float *out, int dim_up, int draw_aspherical)
{
  int error = 0;
  float n1 = 1.0f;
  float pos[3] = {0.0f}, dir[3] = {0.0f};
  float intensity = 1.0f;

  float lens_length = 0;
  for(int i=0;i<lenses_cnt;i++) lens_length += lens_get_thickness(lenses+i, zoom);

  if (strcmp(lenses[0].geometry, "cyl-y") == 0) cylinderToCs(in, in + 2, pos, dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, true);
  else if (strcmp(lenses[0].geometry, "cyl-x") == 0) cylinderToCs(in, in + 2, pos, dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, false);
  else sphereToCs(in, in + 2, pos, dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius);


  // sphere param only knows about directions facing /away/ from outer pupil, so
  // need to flip this if we're tracing into the lens towards the sensor:
  for(int i = 0; i < 3; i++) dir[i] = -dir[i];

  float distsum = lens_length;

  for(int k=0;k<lenses_cnt;k++)
  {
    const float R = lenses[k].lens_radius;
    float t = 0.0f;
    const float dist = lens_get_thickness(lenses+k, zoom);

    //normal at intersection
    float n[3] = {0.0f};
    
    if (strcmp(lenses[k].geometry, "cyl-y") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum - R, lenses[k].housing_radius, n, true);
    }
    else if (strcmp(lenses[k].geometry, "cyl-x") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum - R, lenses[k].housing_radius, n, false);
    }
    else if (draw_aspherical){
      error |= aspherical(pos, dir, &t, R, distsum - R, lenses[k].aspheric, lenses[k].aspheric_correction_coefficients, lenses[k].housing_radius, n);
    }
    else {
      error |= spherical(pos, dir, &t, R, distsum - R, lenses[k].housing_radius, n);
    }

    if(n[2] < 0.0) error |= 16;

    // index of refraction and ratio current/next:
    const float n2 = spectrum_eta_from_abbe_um(lenses[k].ior, lenses[k].vno, in[4]);
    intensity *= refract(n1, n2, n, dir);
    if(intensity < INTENSITY_EPS) error |= 8;

    //if(error) return error;

    // and renormalise:
    raytrace_normalise(dir);

    distsum -= dist;
    n1 = n2;
  }
  
  // y=0 intersection
  return pos[dim_up] - pos[2]*dir[dim_up]/dir[2];
}


static inline bool evaluate_reverse_fstop(const lens_element_t *lenses, const int lenses_cnt, const float zoom, const float *in, float *out, int dim_up, int draw_aspherical, std::vector<float> &positiondata)
{
  int error = 0;
  float n1 = 1.0f;
  float pos[3] = {0.0f}, dir[3] = {0.0f};
  float intensity = 1.0f;

  float lens_length = 0;
  for(int i=0;i<lenses_cnt;i++) lens_length += lens_get_thickness(lenses+i, zoom);

  if (strcmp(lenses[0].geometry, "cyl-y") == 0) cylinderToCs(in, in + 2, pos, dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, true);
  else if (strcmp(lenses[0].geometry, "cyl-x") == 0) cylinderToCs(in, in + 2, pos, dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius, false);
  else sphereToCs(in, in + 2, pos, dir, lens_length - lenses[0].lens_radius, lenses[0].lens_radius);


  // sphere param only knows about directions facing /away/ from outer pupil, so
  // need to flip this if we're tracing into the lens towards the sensor:
  for(int i = 0; i < 3; i++) dir[i] = -dir[i];

  float distsum = lens_length;

  for(int k=0;k<lenses_cnt;k++)
  {
    const float R = lenses[k].lens_radius;
    float t = 0.0f;
    const float dist = lens_get_thickness(lenses+k, zoom);

    //normal at intersection
    float n[3] = {0.0f};
    
    if (strcmp(lenses[k].geometry, "cyl-y") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum - R, lenses[k].housing_radius, n, true);
    }
    else if (strcmp(lenses[k].geometry, "cyl-x") == 0){
      error |= cylindrical(pos, dir, &t, R, distsum - R, lenses[k].housing_radius, n, false);
    }
    else if (draw_aspherical){
      error |= aspherical(pos, dir, &t, R, distsum - R, lenses[k].aspheric, lenses[k].aspheric_correction_coefficients, lenses[k].housing_radius, n);
    }
    else {
      error |= spherical(pos, dir, &t, R, distsum - R, lenses[k].housing_radius, n);
    }

    if(n[2] < 0.0) error |= 16;

    // index of refraction and ratio current/next:
    const float n2 = spectrum_eta_from_abbe_um(lenses[k].ior, lenses[k].vno, in[4]);
    intensity *= refract(n1, n2, n, dir);
    if(intensity < INTENSITY_EPS) error |= 8;

    if(error) return false;

    // and renormalise:
    raytrace_normalise(dir);

    distsum -= dist;
    n1 = n2;
  }

  // [xdistance between last lens intersection and y0 intersection, ydistance last lens intersection]
  positiondata[0] = pos[2] - (pos[dim_up] - pos[2]*dir[dim_up]/dir[2]);
  positiondata[1] = pos[dim_up];

  return true;
}