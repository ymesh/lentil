case asahi__takumar__1969__45mm:
{
//input: scene_[x,y,z] - point in scene, ap_[x,y] - point on aperture
//output: [x,y,dx,dy] point and direction on sensor
Eigen::Vector3d view(
  scene_x,
  scene_y,
  scene_z + camera->lens_outer_pupil_curvature_radius
);
raytrace_normalise(view);
int error = 0;
if(1 || view(2) >= camera->lens_field_of_view)
{
  const double eps = 1e-8;
  double sqr_err = 1e30, sqr_ap_err = 1e30;
  double prev_sqr_err = 1e32, prev_sqr_ap_err = 1e32;
  for(int k=0;k<100&&(sqr_err>eps||sqr_ap_err>eps)&&error==0;k++)
  {
    prev_sqr_err = sqr_err, prev_sqr_ap_err = sqr_ap_err;
    const double begin_x = x;
    const double begin_y = y;
    const double begin_dx = dx;
    const double begin_dy = dy;
    const double begin_lambda = lambda;
    const Eigen::Vector2d pred_ap(
       + 27.2982 *begin_dx + 0.325195 *begin_x + 5.74527 *begin_dx*begin_lambda + 0.219698 *begin_x*begin_lambda + -3.94359 *begin_dx*lens_ipow(begin_lambda, 2) + -15.6996 *begin_dx*lens_ipow(begin_dy, 2) + -15.5426 *lens_ipow(begin_dx, 3) + -0.138007 *begin_y*begin_dx*begin_dy + 0.00227197 *lens_ipow(begin_y, 2)*begin_dx + -0.15608 *begin_x*lens_ipow(begin_lambda, 2) + -0.269509 *begin_x*lens_ipow(begin_dx, 2) + 0.00478297 *begin_x*begin_y*begin_dy + -0.000166685 *begin_x*lens_ipow(begin_y, 2) + 0.00424008 *lens_ipow(begin_x, 2)*begin_dx + -0.000199545 *lens_ipow(begin_x, 3) + -0.282869 *begin_x*lens_ipow(begin_dy, 2)*begin_lambda + -0.00541369 *begin_x*begin_y*begin_dy*begin_lambda + 3.47114e-05 *lens_ipow(begin_x, 3)*begin_lambda + -0.00966002 *lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 3) + -2.23761e-07 *begin_x*lens_ipow(begin_y, 4) + 0.0390163 *begin_x*begin_y*lens_ipow(begin_dx, 2)*begin_dy*begin_lambda + -0.0414476 *lens_ipow(begin_x, 2)*begin_dx*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 2) + -3.23815e-09 *lens_ipow(begin_x, 5)*lens_ipow(begin_y, 2) + -5.95383e-10 *lens_ipow(begin_x, 7) + 1.1269 *begin_x*lens_ipow(begin_dy, 4)*lens_ipow(begin_lambda, 3) + -38.2504 *begin_y*lens_ipow(begin_dx, 3)*lens_ipow(begin_dy, 5) + -4.29881e-12 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 6) + 7.45448e-12 *lens_ipow(begin_x, 7)*lens_ipow(begin_y, 2)*begin_lambda,
       + 27.3668 *begin_dy + 0.333001 *begin_y + 5.53942 *begin_dy*begin_lambda + 0.196075 *begin_y*begin_lambda + -3.78333 *begin_dy*lens_ipow(begin_lambda, 2) + -15.599 *lens_ipow(begin_dy, 3) + -15.7564 *lens_ipow(begin_dx, 2)*begin_dy + -0.144811 *begin_y*lens_ipow(begin_lambda, 2) + -0.272971 *begin_y*lens_ipow(begin_dy, 2) + -0.162163 *begin_y*lens_ipow(begin_dx, 2) + 0.0042293 *lens_ipow(begin_y, 2)*begin_dy + -0.000176834 *lens_ipow(begin_y, 3) + -0.101926 *begin_x*begin_dx*begin_dy + 0.00171584 *begin_x*begin_y*begin_dx + 0.00235656 *lens_ipow(begin_x, 2)*begin_dy + -0.000173262 *lens_ipow(begin_x, 2)*begin_y + 8.03454e-05 *lens_ipow(begin_y, 3)*begin_lambda + 8.20706e-05 *lens_ipow(begin_x, 2)*begin_y*begin_lambda + 0.22715 *begin_y*lens_ipow(begin_dx, 4) + -0.0147187 *lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 2)*begin_dy + -3.17621e-07 *lens_ipow(begin_y, 5) + -0.338812 *begin_x*begin_dx*lens_ipow(begin_dy, 3) + -0.380277 *begin_x*lens_ipow(begin_dx, 3)*begin_dy + 0.0178232 *begin_x*begin_y*begin_dx*lens_ipow(begin_dy, 2) + -0.0107041 *lens_ipow(begin_x, 2)*lens_ipow(begin_dy, 3) + -6.5136e-07 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 3) + -3.43279e-07 *lens_ipow(begin_x, 4)*begin_y + -6.94755e-11 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 6)*begin_dx*begin_dy
    );
    const Eigen::Vector2d delta_ap(ap_x - pred_ap[0], ap_y - pred_ap[1]);
    sqr_ap_err = delta_ap[0]*delta_ap[0]+delta_ap[1]*delta_ap[1];
    Eigen::Matrix2d dx1_domega0;
    dx1_domega0(0, 0) =  + 27.2982  + 5.74527 *begin_lambda + -3.94359 *lens_ipow(begin_lambda, 2) + -15.6996 *lens_ipow(begin_dy, 2) + -46.6277 *lens_ipow(begin_dx, 2) + -0.138007 *begin_y*begin_dy + 0.00227197 *lens_ipow(begin_y, 2) + -0.539018 *begin_x*begin_dx + 0.00424008 *lens_ipow(begin_x, 2) + -0.0289801 *lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 2) + 0.0780327 *begin_x*begin_y*begin_dx*begin_dy*begin_lambda + -0.0414476 *lens_ipow(begin_x, 2)*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 2) + -114.751 *begin_y*lens_ipow(begin_dx, 2)*lens_ipow(begin_dy, 5)+0.0f;
    dx1_domega0(0, 1) =  + -31.3992 *begin_dx*begin_dy + -0.138007 *begin_y*begin_dx + 0.00478297 *begin_x*begin_y + -0.565738 *begin_x*begin_dy*begin_lambda + -0.00541369 *begin_x*begin_y*begin_lambda + 0.0390163 *begin_x*begin_y*lens_ipow(begin_dx, 2)*begin_lambda + -0.0828952 *lens_ipow(begin_x, 2)*begin_dx*begin_dy*lens_ipow(begin_lambda, 2) + 4.50761 *begin_x*lens_ipow(begin_dy, 3)*lens_ipow(begin_lambda, 3) + -191.252 *begin_y*lens_ipow(begin_dx, 3)*lens_ipow(begin_dy, 4)+0.0f;
    dx1_domega0(1, 0) =  + -31.5128 *begin_dx*begin_dy + -0.324325 *begin_y*begin_dx + -0.101926 *begin_x*begin_dy + 0.00171584 *begin_x*begin_y + 0.908599 *begin_y*lens_ipow(begin_dx, 3) + -0.0294375 *lens_ipow(begin_y, 2)*begin_dx*begin_dy + -0.338812 *begin_x*lens_ipow(begin_dy, 3) + -1.14083 *begin_x*lens_ipow(begin_dx, 2)*begin_dy + 0.0178232 *begin_x*begin_y*lens_ipow(begin_dy, 2) + -6.94755e-11 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 6)*begin_dy+0.0f;
    dx1_domega0(1, 1) =  + 27.3668  + 5.53942 *begin_lambda + -3.78333 *lens_ipow(begin_lambda, 2) + -46.7971 *lens_ipow(begin_dy, 2) + -15.7564 *lens_ipow(begin_dx, 2) + -0.545941 *begin_y*begin_dy + 0.0042293 *lens_ipow(begin_y, 2) + -0.101926 *begin_x*begin_dx + 0.00235656 *lens_ipow(begin_x, 2) + -0.0147187 *lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 2) + -1.01643 *begin_x*begin_dx*lens_ipow(begin_dy, 2) + -0.380277 *begin_x*lens_ipow(begin_dx, 3) + 0.0356464 *begin_x*begin_y*begin_dx*begin_dy + -0.0321124 *lens_ipow(begin_x, 2)*lens_ipow(begin_dy, 2) + -6.94755e-11 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 6)*begin_dx+0.0f;
    Eigen::Matrix2d invApJ;
    const double invdetap = 1.0f/(dx1_domega0(0, 0)*dx1_domega0(1, 1) - dx1_domega0(0, 1)*dx1_domega0(1, 0));
    invApJ(0, 0) =  dx1_domega0(1, 1)*invdetap;
    invApJ(1, 1) =  dx1_domega0(0, 0)*invdetap;
    invApJ(0, 1) = -dx1_domega0(0, 1)*invdetap;
    invApJ(1, 0) = -dx1_domega0(1, 0)*invdetap;
    for(int i=0;i<2;i++)
    {
      dx += invApJ(0, i)*delta_ap[i];
      dy += invApJ(1, i)*delta_ap[i];
    }
    out(0) =  + 44.7297 *begin_dx + -0.122102 *begin_x + 0.476743 *begin_dx*begin_lambda + 0.364636 *begin_x*begin_lambda + -19.0984 *begin_dx*lens_ipow(begin_dy, 2) + -18.4086 *lens_ipow(begin_dx, 3) + 0.00754839 *lens_ipow(begin_y, 2)*begin_dx + -0.274463 *begin_x*lens_ipow(begin_lambda, 2) + 0.578237 *begin_x*lens_ipow(begin_dx, 2) + 0.0171559 *begin_x*begin_y*begin_dy + -0.000435656 *begin_x*lens_ipow(begin_y, 2) + 0.0267976 *lens_ipow(begin_x, 2)*begin_dx + -0.000412487 *lens_ipow(begin_x, 3) + 1.67338 *begin_x*lens_ipow(begin_dy, 2)*begin_lambda + 0.000239245 *begin_x*lens_ipow(begin_y, 2)*begin_lambda + 0.000212946 *lens_ipow(begin_x, 3)*begin_lambda + -0.862595 *begin_x*lens_ipow(begin_dx, 2)*lens_ipow(begin_dy, 2) + -2.14301e-05 *begin_x*lens_ipow(begin_y, 3)*begin_dy + -8.60866e-07 *begin_x*lens_ipow(begin_y, 4) + 0.000550173 *lens_ipow(begin_x, 3)*lens_ipow(begin_dy, 2) + -1.12547e-06 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 2) + -1.68281e-05 *lens_ipow(begin_x, 4)*begin_dx + -8.00304e-07 *lens_ipow(begin_x, 5) + -3.99083 *begin_x*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 3) + -1.15035e-06 *lens_ipow(begin_y, 5)*begin_dx*begin_dy + 0.0978213 *lens_ipow(begin_x, 2)*lens_ipow(begin_dx, 5) + 3.89272 *begin_x*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 5) + -3.583e-14 *lens_ipow(begin_x, 7)*lens_ipow(begin_y, 4);
    out(1) =  + 44.7372 *begin_dy + -0.0405255 *begin_y + 0.433101 *begin_dy*begin_lambda + 0.0641527 *begin_y*begin_lambda + -18.3284 *lens_ipow(begin_dy, 3) + -19.0668 *lens_ipow(begin_dx, 2)*begin_dy + 0.579352 *begin_y*lens_ipow(begin_dy, 2) + 0.450261 *begin_y*lens_ipow(begin_dx, 2) + 0.0280273 *lens_ipow(begin_y, 2)*begin_dy + -0.00138654 *lens_ipow(begin_y, 3) + 0.0170665 *begin_x*begin_y*begin_dx + 0.00756858 *lens_ipow(begin_x, 2)*begin_dy + -0.000442972 *lens_ipow(begin_x, 2)*begin_y + 0.00381013 *lens_ipow(begin_y, 3)*begin_lambda + 0.000236723 *lens_ipow(begin_x, 2)*begin_y*begin_lambda + -0.00333069 *lens_ipow(begin_y, 3)*lens_ipow(begin_lambda, 2) + 0.000566073 *lens_ipow(begin_y, 3)*lens_ipow(begin_dx, 2) + -3.39464e-05 *lens_ipow(begin_y, 4)*begin_dy + -1.07671e-06 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 3) + -2.1131e-05 *lens_ipow(begin_x, 3)*begin_y*begin_dx + -8.30784e-07 *lens_ipow(begin_x, 4)*begin_y + -1.53731 *begin_y*lens_ipow(begin_dx, 2)*lens_ipow(begin_dy, 2)*begin_lambda + 0.0954173 *lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 5) + -7.79725e-06 *lens_ipow(begin_y, 5)*lens_ipow(begin_lambda, 2) + 5.43445e-08 *lens_ipow(begin_y, 6)*begin_dy + -1.12949e-06 *lens_ipow(begin_x, 5)*begin_dx*begin_dy + 9.63211e-06 *lens_ipow(begin_y, 5)*lens_ipow(begin_lambda, 3) + -4.14921e-14 *lens_ipow(begin_x, 4)*lens_ipow(begin_y, 7);
    out(2) =  + -0.907818 *begin_dx + -0.0199554 *begin_x + -0.00714196 *begin_x*begin_lambda + 0.093412 *begin_dx*lens_ipow(begin_dy, 2) + 0.00571261 *begin_x*lens_ipow(begin_lambda, 2) + -0.00884666 *begin_x*lens_ipow(begin_dy, 2) + -0.000293443 *begin_x*begin_y*begin_dy + 1.44832e-05 *begin_x*lens_ipow(begin_y, 2) + -0.000221876 *lens_ipow(begin_x, 2)*begin_dx + 1.51611e-05 *lens_ipow(begin_x, 3) + 2.17706 *lens_ipow(begin_dx, 3)*begin_lambda + 6.99001e-05 *lens_ipow(begin_y, 2)*begin_dx*begin_lambda + -5.22992e-06 *begin_x*lens_ipow(begin_y, 2)*begin_lambda + -5.85006e-06 *lens_ipow(begin_x, 3)*begin_lambda + -3.83809 *lens_ipow(begin_dx, 3)*lens_ipow(begin_lambda, 2) + 0.000440773 *lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 3) + -0.000261292 *begin_x*begin_y*lens_ipow(begin_dy, 3) + 3.31116e-05 *lens_ipow(begin_x, 2)*begin_y*begin_dx*begin_dy + 1.39195e-08 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 2) + -2.76073e-07 *lens_ipow(begin_x, 4)*begin_dx + 2.25837 *lens_ipow(begin_dx, 3)*lens_ipow(begin_lambda, 3) + -5.6162e-06 *begin_x*lens_ipow(begin_y, 3)*lens_ipow(begin_dx, 2)*begin_dy + 2.78124e-11 *begin_x*lens_ipow(begin_y, 6) + -3.96122e-05 *lens_ipow(begin_x, 3)*lens_ipow(begin_dy, 4) + 2.24757e-11 *lens_ipow(begin_x, 7) + -1.07832e-08 *lens_ipow(begin_y, 6)*begin_dx*lens_ipow(begin_dy, 2) + 3.39992e-13 *lens_ipow(begin_x, 5)*lens_ipow(begin_y, 4) + -4.95443e-12 *lens_ipow(begin_x, 6)*lens_ipow(begin_y, 2)*begin_dx;
    out(3) =  + -0.903407 *begin_dy + -0.021574 *begin_y + -0.000776584 *begin_y*begin_lambda + 0.385776 *lens_ipow(begin_dy, 3) + 0.700282 *lens_ipow(begin_dx, 2)*begin_dy + -0.0091774 *begin_y*lens_ipow(begin_dx, 2) + -0.000283608 *lens_ipow(begin_y, 2)*begin_dy + 2.16948e-05 *lens_ipow(begin_y, 3) + 0.017003 *begin_x*begin_dx*begin_dy + -0.000320428 *begin_x*begin_y*begin_dx + 2.0644e-05 *lens_ipow(begin_x, 2)*begin_y + -0.00192694 *begin_y*lens_ipow(begin_dy, 2)*begin_lambda + -3.79909e-05 *lens_ipow(begin_y, 3)*begin_lambda + -3.62523e-05 *lens_ipow(begin_x, 2)*begin_y*begin_lambda + 2.93028e-05 *lens_ipow(begin_y, 3)*lens_ipow(begin_lambda, 2) + 1.11145e-08 *lens_ipow(begin_y, 5) + -0.000754928 *begin_x*begin_y*begin_dx*lens_ipow(begin_dy, 2) + 0.000873307 *lens_ipow(begin_x, 2)*lens_ipow(begin_dx, 2)*begin_dy + 2.79014e-05 *lens_ipow(begin_x, 2)*begin_y*lens_ipow(begin_lambda, 2) + 2.91067e-08 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 3) + 1.49411e-08 *lens_ipow(begin_x, 4)*begin_y + 0.0009747 *lens_ipow(begin_x, 2)*lens_ipow(begin_dy, 3)*begin_lambda + 5.08822e-06 *lens_ipow(begin_y, 4)*lens_ipow(begin_dx, 2)*begin_dy + -8.69069e-10 *lens_ipow(begin_y, 6)*begin_dy + -7.71177e-08 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 3)*lens_ipow(begin_dx, 2) + 3.60817e-08 *lens_ipow(begin_x, 5)*begin_dx*begin_dy + -1.28732e-11 *lens_ipow(begin_x, 4)*lens_ipow(begin_y, 4)*begin_dy + 3.25634e-12 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 6)*begin_dx*begin_dy;
    Eigen::Vector3d pred_out_cs_pos(0,0,0);
    Eigen::Vector3d pred_out_cs_dir(0,0,0);
    Eigen::Vector2d outpos(out(0), out(1));
    Eigen::Vector2d outdir(out(2), out(3));
    if (camera->lens_outer_pupil_geometry == "cyl-y") cylinderToCs(outpos, outdir, pred_out_cs_pos, pred_out_cs_dir, - camera->lens_outer_pupil_curvature_radius, camera->lens_outer_pupil_curvature_radius, true);
    else if (camera->lens_outer_pupil_geometry == "cyl-x") cylinderToCs(outpos, outdir, pred_out_cs_pos, pred_out_cs_dir, - camera->lens_outer_pupil_curvature_radius, camera->lens_outer_pupil_curvature_radius, false);
    else sphereToCs(outpos, outdir, pred_out_cs_pos, pred_out_cs_dir, - camera->lens_outer_pupil_curvature_radius, camera->lens_outer_pupil_curvature_radius);
    Eigen::Vector3d view(
      scene_x - pred_out_cs_pos(0),
      scene_y - pred_out_cs_pos(1),
      scene_z - pred_out_cs_pos(2)
    );
    raytrace_normalise(view);
    Eigen::VectorXd out_new(5); out_new.setZero();
    Eigen::Vector2d out_new_pos(0,0);
    Eigen::Vector2d out_new_dir(0,0);
    if (camera->lens_outer_pupil_geometry == "cyl-y") csToCylinder(pred_out_cs_pos, view, out_new_pos, out_new_dir, - camera->lens_outer_pupil_curvature_radius, camera->lens_outer_pupil_curvature_radius, true);
    else if (camera->lens_outer_pupil_geometry == "cyl-x") csToCylinder(pred_out_cs_pos, view, out_new_pos, out_new_dir, - camera->lens_outer_pupil_curvature_radius, camera->lens_outer_pupil_curvature_radius, false);
    else csToSphere(pred_out_cs_pos, view, out_new_pos, out_new_dir, - camera->lens_outer_pupil_curvature_radius, camera->lens_outer_pupil_curvature_radius);
    out_new(0) = out_new_pos(0);
    out_new(1) = out_new_pos(1);
    out_new(2) = out_new_dir(0);
    out_new(3) = out_new_dir(1);
    const Eigen::Vector2d delta_out(out_new[2] - out[2], out_new[3] - out[3]);
    sqr_err = delta_out[0]*delta_out[0]+delta_out[1]*delta_out[1];
    Eigen::Matrix2d domega2_dx0;
    domega2_dx0(0, 0) =  + -0.0199554  + -0.00714196 *begin_lambda + 0.00571261 *lens_ipow(begin_lambda, 2) + -0.00884666 *lens_ipow(begin_dy, 2) + -0.000293443 *begin_y*begin_dy + 1.44832e-05 *lens_ipow(begin_y, 2) + -0.000443752 *begin_x*begin_dx + 4.54832e-05 *lens_ipow(begin_x, 2) + -5.22992e-06 *lens_ipow(begin_y, 2)*begin_lambda + -1.75502e-05 *lens_ipow(begin_x, 2)*begin_lambda + -0.000261292 *begin_y*lens_ipow(begin_dy, 3) + 6.62232e-05 *begin_x*begin_y*begin_dx*begin_dy + 4.17586e-08 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 2) + -1.10429e-06 *lens_ipow(begin_x, 3)*begin_dx + -5.6162e-06 *lens_ipow(begin_y, 3)*lens_ipow(begin_dx, 2)*begin_dy + 2.78124e-11 *lens_ipow(begin_y, 6) + -0.000118837 *lens_ipow(begin_x, 2)*lens_ipow(begin_dy, 4) + 1.5733e-10 *lens_ipow(begin_x, 6) + 1.69996e-12 *lens_ipow(begin_x, 4)*lens_ipow(begin_y, 4) + -2.97266e-11 *lens_ipow(begin_x, 5)*lens_ipow(begin_y, 2)*begin_dx+0.0f;
    domega2_dx0(0, 1) =  + -0.000293443 *begin_x*begin_dy + 2.89663e-05 *begin_x*begin_y + 0.0001398 *begin_y*begin_dx*begin_lambda + -1.04598e-05 *begin_x*begin_y*begin_lambda + 0.000881546 *begin_y*lens_ipow(begin_dx, 3) + -0.000261292 *begin_x*lens_ipow(begin_dy, 3) + 3.31116e-05 *lens_ipow(begin_x, 2)*begin_dx*begin_dy + 2.78391e-08 *lens_ipow(begin_x, 3)*begin_y + -1.68486e-05 *begin_x*lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 2)*begin_dy + 1.66874e-10 *begin_x*lens_ipow(begin_y, 5) + -6.46993e-08 *lens_ipow(begin_y, 5)*begin_dx*lens_ipow(begin_dy, 2) + 1.35997e-12 *lens_ipow(begin_x, 5)*lens_ipow(begin_y, 3) + -9.90885e-12 *lens_ipow(begin_x, 6)*begin_y*begin_dx+0.0f;
    domega2_dx0(1, 0) =  + 0.017003 *begin_dx*begin_dy + -0.000320428 *begin_y*begin_dx + 4.1288e-05 *begin_x*begin_y + -7.25047e-05 *begin_x*begin_y*begin_lambda + -0.000754928 *begin_y*begin_dx*lens_ipow(begin_dy, 2) + 0.00174661 *begin_x*lens_ipow(begin_dx, 2)*begin_dy + 5.58028e-05 *begin_x*begin_y*lens_ipow(begin_lambda, 2) + 5.82134e-08 *begin_x*lens_ipow(begin_y, 3) + 5.97645e-08 *lens_ipow(begin_x, 3)*begin_y + 0.0019494 *begin_x*lens_ipow(begin_dy, 3)*begin_lambda + -1.54235e-07 *begin_x*lens_ipow(begin_y, 3)*lens_ipow(begin_dx, 2) + 1.80409e-07 *lens_ipow(begin_x, 4)*begin_dx*begin_dy + -5.14927e-11 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 4)*begin_dy + 9.76902e-12 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 6)*begin_dx*begin_dy+0.0f;
    domega2_dx0(1, 1) =  + -0.021574  + -0.000776584 *begin_lambda + -0.0091774 *lens_ipow(begin_dx, 2) + -0.000567216 *begin_y*begin_dy + 6.50845e-05 *lens_ipow(begin_y, 2) + -0.000320428 *begin_x*begin_dx + 2.0644e-05 *lens_ipow(begin_x, 2) + -0.00192694 *lens_ipow(begin_dy, 2)*begin_lambda + -0.000113973 *lens_ipow(begin_y, 2)*begin_lambda + -3.62523e-05 *lens_ipow(begin_x, 2)*begin_lambda + 8.79083e-05 *lens_ipow(begin_y, 2)*lens_ipow(begin_lambda, 2) + 5.55727e-08 *lens_ipow(begin_y, 4) + -0.000754928 *begin_x*begin_dx*lens_ipow(begin_dy, 2) + 2.79014e-05 *lens_ipow(begin_x, 2)*lens_ipow(begin_lambda, 2) + 8.73202e-08 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 2) + 1.49411e-08 *lens_ipow(begin_x, 4) + 2.03529e-05 *lens_ipow(begin_y, 3)*lens_ipow(begin_dx, 2)*begin_dy + -5.21441e-09 *lens_ipow(begin_y, 5)*begin_dy + -2.31353e-07 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 2) + -5.14927e-11 *lens_ipow(begin_x, 4)*lens_ipow(begin_y, 3)*begin_dy + 1.9538e-11 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 5)*begin_dx*begin_dy+0.0f;
    Eigen::Matrix2d invJ;
    const double invdet = 1.0f/(domega2_dx0(0, 0)*domega2_dx0(1, 1) - domega2_dx0(0, 1)*domega2_dx0(1, 0));
    invJ(0, 0) =  domega2_dx0(1, 1)*invdet;
    invJ(1, 1) =  domega2_dx0(0, 0)*invdet;
    invJ(0, 1) = -domega2_dx0(0, 1)*invdet;
    invJ(1, 0) = -domega2_dx0(1, 0)*invdet;
    for(int i=0;i<2;i++)
    {
      x += 0.72 * invJ(0, i) * delta_out[i];
      y += 0.72 * invJ(1, i) * delta_out[i];
    }
    if(sqr_err>prev_sqr_err) error |= 1;
    if(sqr_ap_err>prev_sqr_ap_err) error |= 2;
    if(out[0]!=out[0]) error |= 4;
    if(out[1]!=out[1]) error |= 8;
    // reset error code for first few iterations.
    if(k<10) error = 0;
  }
}
else
  error = 128;
if(out[0]*out[0]+out[1]*out[1] > camera->lens_outer_pupil_radius*camera->lens_outer_pupil_radius) error |= 16;
const double begin_x = x;
const double begin_y = y;
const double begin_dx = dx;
const double begin_dy = dy;
const double begin_lambda = lambda;
if(error==0)
  out[4] =  + 2.12968 *begin_lambda + -4.69513 *lens_ipow(begin_lambda, 2) + -5.43933e-06 *lens_ipow(begin_y, 2) + -8.49587e-06 *lens_ipow(begin_x, 2) + 4.85463 *lens_ipow(begin_lambda, 3) + -0.00110447 *begin_y*begin_dy*begin_lambda + -0.00114798 *begin_x*begin_dx*begin_lambda + -1.93767 *lens_ipow(begin_lambda, 4) + -0.899767 *lens_ipow(begin_dx, 2)*lens_ipow(begin_dy, 2) + -0.361311 *lens_ipow(begin_dx, 4) + -0.0213568 *begin_y*lens_ipow(begin_dx, 2)*begin_dy + -0.000227167 *lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 2) + -0.0209078 *begin_x*begin_dx*lens_ipow(begin_dy, 2) + -0.0213342 *begin_x*lens_ipow(begin_dx, 3) + -0.000804315 *begin_x*begin_y*begin_dx*begin_dy + -0.000202878 *lens_ipow(begin_x, 2)*lens_ipow(begin_dy, 2) + -0.000620196 *lens_ipow(begin_x, 2)*lens_ipow(begin_dx, 2) + -1.36295 *lens_ipow(begin_dy, 4)*begin_lambda + -0.171581 *lens_ipow(begin_dx, 4)*begin_lambda + -0.0420681 *begin_y*lens_ipow(begin_dy, 3)*begin_lambda + -0.00132576 *lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 2)*begin_lambda + 0.942924 *lens_ipow(begin_dy, 4)*lens_ipow(begin_lambda, 2) + -1.93337e-10 *lens_ipow(begin_y, 6) + -2.14302e-05 *lens_ipow(begin_y, 3)*begin_dy*lens_ipow(begin_lambda, 3) + 0.00594203 *begin_y*begin_dy*lens_ipow(begin_lambda, 6) + 4.96195e-13 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 7)*begin_dy + -2.39163e-14 *lens_ipow(begin_x, 6)*lens_ipow(begin_y, 4) + -1.18925e-15 *lens_ipow(begin_x, 10);
else
  out[4] = 0.0f;
} break;