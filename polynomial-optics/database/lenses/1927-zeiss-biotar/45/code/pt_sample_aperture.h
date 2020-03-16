case zeiss__biotar__1927__45mm:
{
double pred_x;
double pred_y;
double pred_dx;
double pred_dy;
double sqr_err = FLT_MAX;
for(int k=0;k<5&&sqr_err > 1e-4f;k++)
{
  const double begin_x = x + dist * dx;
  const double begin_y = y + dist * dy;
  const double begin_dx = dx;
  const double begin_dy = dy;
  const double begin_lambda = lambda;
  pred_x =  + 28.6047 *begin_dx + 0.467239 *begin_x + 1.14365 *begin_dx*begin_lambda + 0.0371139 *begin_x*begin_lambda + -17.5745 *begin_dx*lens_ipow(begin_dy, 2) + -17.5355 *lens_ipow(begin_dx, 3) + -0.194251 *begin_x*lens_ipow(begin_dy, 2) + -0.406714 *begin_x*lens_ipow(begin_dx, 2) + -0.000173671 *begin_x*lens_ipow(begin_y, 2) + -0.00715064 *lens_ipow(begin_x, 2)*begin_dx + -0.000179487 *lens_ipow(begin_x, 3) + -0.335571 *begin_y*begin_dx*begin_dy*begin_lambda + -0.00775566 *begin_x*begin_y*begin_dy*begin_lambda + 0.0210202 *lens_ipow(begin_y, 2)*begin_dx*lens_ipow(begin_dy, 2) + 0.0518338 *begin_x*begin_y*lens_ipow(begin_dx, 2)*begin_dy + -2.86047e-05 *begin_x*lens_ipow(begin_y, 3)*begin_dy + -8.8463e-07 *begin_x*lens_ipow(begin_y, 4) + -4.24333e-05 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 2)*begin_dx + -2.6356e-05 *lens_ipow(begin_x, 3)*begin_y*begin_dy + -1.50714e-06 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 2) + -8.0149e-07 *lens_ipow(begin_x, 5) + -1.63866e-05 *lens_ipow(begin_y, 4)*begin_dx*begin_lambda + 0.0369267 *lens_ipow(begin_x, 2)*lens_ipow(begin_dx, 3)*begin_lambda + -0.0348545 *lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 5) + -2.76212e-07 *lens_ipow(begin_x, 6)*begin_dx*begin_lambda + 0.105319 *begin_x*begin_y*lens_ipow(begin_dy, 3)*lens_ipow(begin_lambda, 6) + -2.34493e-14 *lens_ipow(begin_x, 7)*lens_ipow(begin_y, 4) + 6.95643e-10 *lens_ipow(begin_x, 8)*begin_dx*lens_ipow(begin_lambda, 2);
  pred_y =  + 28.4706 *begin_dy + 0.467672 *begin_y + 1.23103 *begin_dy*begin_lambda + 0.0416275 *begin_y*begin_lambda + -16.8339 *lens_ipow(begin_dy, 3) + -15.35 *lens_ipow(begin_dx, 2)*begin_dy + -0.419807 *begin_y*lens_ipow(begin_dy, 2) + -0.00642829 *lens_ipow(begin_y, 2)*begin_dy + -0.000269039 *lens_ipow(begin_y, 3) + -0.000196919 *lens_ipow(begin_x, 2)*begin_y + -0.341036 *begin_y*lens_ipow(begin_dx, 2)*begin_lambda + -0.302272 *begin_x*begin_dx*begin_dy*begin_lambda + -0.00744506 *begin_x*begin_y*begin_dx*begin_lambda + 0.0401756 *begin_x*begin_y*begin_dx*lens_ipow(begin_dy, 2) + -2.54482e-05 *begin_x*lens_ipow(begin_y, 3)*begin_dx + -4.26211e-05 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 2)*begin_dy + -1.40259e-06 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 3) + -6.36972e-07 *lens_ipow(begin_x, 4)*begin_y + -3.36196e-05 *lens_ipow(begin_x, 3)*begin_y*begin_dx*begin_lambda + -0.00111466 *lens_ipow(begin_y, 3)*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 2) + -2.14855e-09 *lens_ipow(begin_y, 7) + -14.415 *begin_x*lens_ipow(begin_dx, 3)*lens_ipow(begin_dy, 3) + -0.000106831 *lens_ipow(begin_x, 4)*lens_ipow(begin_dy, 3) + -2.86041e-07 *lens_ipow(begin_y, 6)*begin_dy*begin_lambda + -1131.33 *lens_ipow(begin_dx, 4)*lens_ipow(begin_dy, 3)*lens_ipow(begin_lambda, 2) + -2.59299e-08 *lens_ipow(begin_y, 7)*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 2) + -3.16998e-14 *lens_ipow(begin_x, 4)*lens_ipow(begin_y, 7) + -6.77921e-08 *lens_ipow(begin_x, 6)*begin_y*lens_ipow(begin_dy, 4);
  pred_dx =  + 0.459939 *begin_dx + -0.0300371 *begin_x + 0.0124931 *begin_x*begin_lambda + -0.160754 *begin_dx*lens_ipow(begin_dy, 2) + -0.202157 *lens_ipow(begin_dx, 3) + -0.0208008 *begin_y*begin_dx*begin_dy + -0.0100829 *begin_x*lens_ipow(begin_lambda, 2) + -0.0112328 *begin_x*lens_ipow(begin_dy, 2) + -0.0286454 *begin_x*lens_ipow(begin_dx, 2) + -2.12163e-05 *begin_x*lens_ipow(begin_y, 2) + -2.44465e-05 *lens_ipow(begin_x, 3) + -0.000374271 *lens_ipow(begin_y, 2)*begin_dx*begin_lambda + -0.000338572 *begin_x*begin_y*begin_dy*begin_lambda + -0.000918477 *lens_ipow(begin_x, 2)*begin_dx*begin_lambda + -5.11606e-08 *begin_x*lens_ipow(begin_y, 4) + -0.0792312 *begin_x*lens_ipow(begin_dx, 4)*begin_lambda + -3.64441e-06 *begin_x*lens_ipow(begin_y, 3)*begin_dy*begin_lambda + -0.119164 *begin_x*lens_ipow(begin_dx, 2)*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 2) + -0.000100698 *begin_x*lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 2) + -3.53991e-10 *lens_ipow(begin_x, 5)*lens_ipow(begin_y, 2) + -8.2615e-11 *lens_ipow(begin_x, 7) + -1.1138e-06 *begin_x*lens_ipow(begin_y, 4)*lens_ipow(begin_dx, 4) + 5.05298e-09 *lens_ipow(begin_x, 6)*begin_y*begin_dx*begin_dy*begin_lambda + -0.00972194 *lens_ipow(begin_y, 3)*lens_ipow(begin_dx, 3)*lens_ipow(begin_dy, 3)*lens_ipow(begin_lambda, 2) + -3.18087e-15 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 8) + 2.16463e-07 *lens_ipow(begin_x, 5)*begin_y*lens_ipow(begin_dx, 2)*begin_dy*lens_ipow(begin_lambda, 2) + -3.79504e-15 *lens_ipow(begin_x, 7)*lens_ipow(begin_y, 4) + -1.70414e-12 *lens_ipow(begin_x, 9)*lens_ipow(begin_dy, 2);
  pred_dy =  + 0.458036 *begin_dy + -0.0302526 *begin_y + 0.0126122 *begin_y*begin_lambda + -0.185902 *lens_ipow(begin_dy, 3) + -0.0100008 *begin_y*lens_ipow(begin_lambda, 2) + -0.0305904 *begin_y*lens_ipow(begin_dy, 2) + -0.0083834 *begin_y*lens_ipow(begin_dx, 2) + -2.21994e-05 *lens_ipow(begin_y, 3) + -0.0170505 *begin_x*begin_dx*begin_dy + -1.963e-05 *lens_ipow(begin_x, 2)*begin_y + -0.388933 *lens_ipow(begin_dx, 2)*begin_dy*begin_lambda + -0.000669968 *lens_ipow(begin_y, 2)*begin_dy*begin_lambda + -0.0003175 *lens_ipow(begin_x, 2)*begin_dy*begin_lambda + -6.91563e-07 *lens_ipow(begin_y, 4)*begin_dy + -3.73981e-08 *lens_ipow(begin_x, 4)*begin_y + -8.77736e-05 *lens_ipow(begin_y, 3)*lens_ipow(begin_dx, 2)*begin_lambda + -4.57703e-06 *begin_x*lens_ipow(begin_y, 3)*begin_dx*begin_lambda + -1.84463e-06 *lens_ipow(begin_x, 3)*begin_y*begin_dx*begin_lambda + 10.2163 *lens_ipow(begin_dx, 2)*lens_ipow(begin_dy, 5) + -1.13247e-10 *lens_ipow(begin_y, 7) + -0.155801 *begin_x*lens_ipow(begin_dx, 3)*begin_dy*lens_ipow(begin_lambda, 2) + -6.25276e-10 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 5) + 0.00946412 *lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 5)*begin_lambda + -1.04817e-06 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 3)*lens_ipow(begin_dy, 2)*begin_lambda + -3.52057e-08 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 4)*begin_dy*begin_lambda + -1.31661e-12 *lens_ipow(begin_x, 6)*lens_ipow(begin_y, 3) + 0.0131491 *begin_x*begin_y*begin_dx*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 5) + 3.77028e-11 *lens_ipow(begin_x, 8)*lens_ipow(begin_dy, 3);
  Eigen::Matrix2d dx1_domega0;
  dx1_domega0(0, 0) =  + 28.6047  + 1.14365 *begin_lambda + -17.5745 *lens_ipow(begin_dy, 2) + -52.6066 *lens_ipow(begin_dx, 2) + -0.813427 *begin_x*begin_dx + -0.00715064 *lens_ipow(begin_x, 2) + -0.335571 *begin_y*begin_dy*begin_lambda + 0.0210202 *lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 2) + 0.103668 *begin_x*begin_y*begin_dx*begin_dy + -4.24333e-05 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 2) + -1.63866e-05 *lens_ipow(begin_y, 4)*begin_lambda + 0.11078 *lens_ipow(begin_x, 2)*lens_ipow(begin_dx, 2)*begin_lambda + -0.174272 *lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 4) + -2.76212e-07 *lens_ipow(begin_x, 6)*begin_lambda + 6.95643e-10 *lens_ipow(begin_x, 8)*lens_ipow(begin_lambda, 2)+0.0f;
  dx1_domega0(0, 1) =  + -35.1491 *begin_dx*begin_dy + -0.388502 *begin_x*begin_dy + -0.335571 *begin_y*begin_dx*begin_lambda + -0.00775566 *begin_x*begin_y*begin_lambda + 0.0420404 *lens_ipow(begin_y, 2)*begin_dx*begin_dy + 0.0518338 *begin_x*begin_y*lens_ipow(begin_dx, 2) + -2.86047e-05 *begin_x*lens_ipow(begin_y, 3) + -2.6356e-05 *lens_ipow(begin_x, 3)*begin_y + 0.315958 *begin_x*begin_y*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 6)+0.0f;
  dx1_domega0(1, 0) =  + -30.7001 *begin_dx*begin_dy + -0.682071 *begin_y*begin_dx*begin_lambda + -0.302272 *begin_x*begin_dy*begin_lambda + -0.00744506 *begin_x*begin_y*begin_lambda + 0.0401756 *begin_x*begin_y*lens_ipow(begin_dy, 2) + -2.54482e-05 *begin_x*lens_ipow(begin_y, 3) + -3.36196e-05 *lens_ipow(begin_x, 3)*begin_y*begin_lambda + -43.245 *begin_x*lens_ipow(begin_dx, 2)*lens_ipow(begin_dy, 3) + -4525.31 *lens_ipow(begin_dx, 3)*lens_ipow(begin_dy, 3)*lens_ipow(begin_lambda, 2)+0.0f;
  dx1_domega0(1, 1) =  + 28.4706  + 1.23103 *begin_lambda + -50.5016 *lens_ipow(begin_dy, 2) + -15.35 *lens_ipow(begin_dx, 2) + -0.839615 *begin_y*begin_dy + -0.00642829 *lens_ipow(begin_y, 2) + -0.302272 *begin_x*begin_dx*begin_lambda + 0.0803511 *begin_x*begin_y*begin_dx*begin_dy + -4.26211e-05 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 2) + -0.00222931 *lens_ipow(begin_y, 3)*begin_dy*lens_ipow(begin_lambda, 2) + -43.245 *begin_x*lens_ipow(begin_dx, 3)*lens_ipow(begin_dy, 2) + -0.000320494 *lens_ipow(begin_x, 4)*lens_ipow(begin_dy, 2) + -2.86041e-07 *lens_ipow(begin_y, 6)*begin_lambda + -3393.98 *lens_ipow(begin_dx, 4)*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 2) + -5.18598e-08 *lens_ipow(begin_y, 7)*begin_dy*lens_ipow(begin_lambda, 2) + -2.71168e-07 *lens_ipow(begin_x, 6)*begin_y*lens_ipow(begin_dy, 3)+0.0f;
  Eigen::Matrix2d invJ;
  const double invdet = 1.0f/(dx1_domega0(0, 0)*dx1_domega0(1, 1) - dx1_domega0(0, 1)*dx1_domega0(1, 0));
  invJ(0, 0) =  dx1_domega0(1, 1)*invdet;
  invJ(1, 1) =  dx1_domega0(0, 0)*invdet;
  invJ(0, 1) = -dx1_domega0(0, 1)*invdet;
  invJ(1, 0) = -dx1_domega0(1, 0)*invdet;
  const Eigen::Vector2d dx1(out_x - pred_x, out_y - pred_y);
  for(int i=0;i<2;i++)
  {
    dx += invJ(0, i)*dx1(i);
    dy += invJ(1, i)*dx1(i);
  }
  sqr_err = dx1(0)*dx1(0) + dx1(1)*dx1(1);
}
out_dx = pred_dx;
out_dy = pred_dy;
} break;
