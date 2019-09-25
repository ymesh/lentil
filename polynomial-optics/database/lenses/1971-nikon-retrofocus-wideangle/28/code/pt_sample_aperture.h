case nikon__retrofocus_wideangle__1971__28mm:
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
  pred_x =  + 36.8509 *begin_dx + 0.761108 *begin_x + -0.00662178 *begin_x*begin_lambda + 1.25266 *begin_y*begin_dx*begin_dy + 8.91949 *begin_dx*lens_ipow(begin_dy, 2) + 0.0239075 *lens_ipow(begin_y, 2)*begin_dx + 4.63029 *begin_x*lens_ipow(begin_dx, 2)*begin_lambda + 0.0023141 *lens_ipow(begin_x, 3)*begin_lambda + 0.196747 *lens_ipow(begin_x, 2)*begin_dx*begin_lambda + 0.00265689 *lens_ipow(begin_x, 2)*lens_ipow(begin_dx, 3) + 41.365 *lens_ipow(begin_dx, 3)*lens_ipow(begin_lambda, 2) + 0.0173568 *begin_x*lens_ipow(begin_y, 2)*lens_ipow(begin_lambda, 2) + 17.0056 *begin_x*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 2) + 1.16157 *begin_x*begin_y*begin_dy*lens_ipow(begin_lambda, 2) + -41.7386 *begin_x*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 3) + -0.0422162 *begin_x*lens_ipow(begin_y, 2)*lens_ipow(begin_lambda, 3) + -2.82755 *begin_x*begin_y*begin_dy*lens_ipow(begin_lambda, 3) + -0.00250568 *lens_ipow(begin_x, 3)*lens_ipow(begin_lambda, 3) + 1.90426 *begin_x*begin_y*begin_dy*lens_ipow(begin_lambda, 4) + -0.279842 *lens_ipow(begin_x, 2)*begin_dx*lens_ipow(begin_lambda, 4) + 0.0284157 *begin_x*lens_ipow(begin_y, 2)*lens_ipow(begin_lambda, 4) + 28.3181 *begin_x*lens_ipow(begin_dy, 2)*lens_ipow(begin_lambda, 4) + -1.7097e-08 *lens_ipow(begin_x, 4)*lens_ipow(begin_y, 3)*begin_dx*begin_dy + -13.0236 *begin_x*lens_ipow(begin_dx, 2)*lens_ipow(begin_lambda, 6) + 4.9701e-12 *lens_ipow(begin_x, 5)*lens_ipow(begin_y, 4) + -277.123 *lens_ipow(begin_dx, 3)*lens_ipow(begin_lambda, 8) + 1.6843e-08 *begin_x*lens_ipow(begin_y, 6)*lens_ipow(begin_dx, 4) + 1.67843e-08 *lens_ipow(begin_x, 7)*lens_ipow(begin_dy, 4);
  pred_y =  + 0.768353 *begin_y + 36.8421 *begin_dy + -0.034862 *begin_y*begin_lambda + 0.0798566 *lens_ipow(begin_y, 2)*begin_dy + 2.09584 *begin_y*lens_ipow(begin_dy, 2) + 0.0257873 *begin_y*lens_ipow(begin_lambda, 2) + 0.000832891 *lens_ipow(begin_y, 3) + 9.38293 *lens_ipow(begin_dy, 3) + 3.15117 *begin_y*lens_ipow(begin_dx, 2)*begin_lambda + 41.2127 *lens_ipow(begin_dx, 2)*begin_dy*begin_lambda + 0.0925706 *lens_ipow(begin_x, 2)*begin_dy*begin_lambda + 0.213198 *begin_x*begin_y*begin_dx*begin_lambda + 4.99446 *begin_x*begin_dx*begin_dy*begin_lambda + 0.00317324 *lens_ipow(begin_x, 2)*begin_y*begin_lambda + -4.72596 *begin_x*begin_dx*begin_dy*lens_ipow(begin_lambda, 2) + -0.00294993 *lens_ipow(begin_x, 2)*begin_y*lens_ipow(begin_lambda, 2) + -0.000158278 *begin_x*lens_ipow(begin_y, 2)*begin_dx*begin_dy + 0.00291481 *lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 3) + -3.00936 *begin_y*lens_ipow(begin_dx, 2)*lens_ipow(begin_lambda, 2) + -0.199349 *begin_x*begin_y*begin_dx*lens_ipow(begin_lambda, 2) + -0.0860934 *lens_ipow(begin_x, 2)*begin_dy*lens_ipow(begin_lambda, 2) + -43.0671 *lens_ipow(begin_dx, 2)*begin_dy*lens_ipow(begin_lambda, 2) + 1.8383e-10 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 5) + -0.0592202 *lens_ipow(begin_x, 3)*lens_ipow(begin_dx, 5)*lens_ipow(begin_dy, 3) + 1.9848e-08 *lens_ipow(begin_y, 7)*lens_ipow(begin_dx, 4) + -5.44052e-11 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 6)*begin_dx*begin_dy + -4.67959e-10 *lens_ipow(begin_x, 6)*lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 3) + 1.4365e-14 *lens_ipow(begin_x, 4)*lens_ipow(begin_y, 7);
  pred_dx =  + 1.42311 *begin_dx + 0.00253777 *begin_x + -0.0249451 *begin_x*begin_lambda + -1.16717 *begin_dx*begin_lambda + 0.180383 *begin_y*begin_dx*begin_dy + 0.00529829 *begin_x*begin_y*begin_dy + 0.00796153 *lens_ipow(begin_x, 2)*begin_dx + 3.2725 *lens_ipow(begin_dx, 3) + 0.0170704 *begin_x*lens_ipow(begin_lambda, 2) + 3.41453 *begin_dx*lens_ipow(begin_dy, 2) + 7.83965e-05 *begin_x*lens_ipow(begin_y, 2) + 7.89457e-05 *lens_ipow(begin_x, 3) + 0.0866079 *begin_x*lens_ipow(begin_dy, 2) + 0.258693 *begin_x*lens_ipow(begin_dx, 2) + 0.00275754 *lens_ipow(begin_y, 2)*begin_dx + 0.799455 *begin_dx*lens_ipow(begin_lambda, 2) + 4.5278e-08 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 2) + -0.0090868 *begin_x*begin_y*lens_ipow(begin_dx, 2)*begin_dy + 9.57825e-07 *lens_ipow(begin_x, 4)*begin_dx + -0.0141608 *begin_x*lens_ipow(begin_dx, 4) + -0.148411 *begin_y*lens_ipow(begin_dx, 3)*begin_dy + 4.31347e-05 *lens_ipow(begin_x, 3)*lens_ipow(begin_dy, 2) + 2.2658e-08 *lens_ipow(begin_x, 5) + 4.74154e-08 *begin_x*lens_ipow(begin_y, 4) + 3.48807e-06 *begin_x*lens_ipow(begin_y, 3)*begin_dy + -0.0333878 *begin_y*begin_dx*lens_ipow(begin_dy, 3) + -0.000270866 *lens_ipow(begin_x, 2)*begin_y*begin_dx*begin_dy + 7.36848e-05 *begin_x*lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 2);
  pred_dy =  + 0.00230352 *begin_y + 1.41271 *begin_dy + -1.1501 *begin_dy*begin_lambda + -0.0246487 *begin_y*begin_lambda + 0.0876473 *begin_y*lens_ipow(begin_dx, 2) + 0.00817553 *lens_ipow(begin_y, 2)*begin_dy + 0.268628 *begin_y*lens_ipow(begin_dy, 2) + 0.176258 *begin_x*begin_dx*begin_dy + 0.00538262 *begin_x*begin_y*begin_dx + 3.37543 *lens_ipow(begin_dx, 2)*begin_dy + 0.0169958 *begin_y*lens_ipow(begin_lambda, 2) + 8.23366e-05 *lens_ipow(begin_x, 2)*begin_y + 0.791858 *begin_dy*lens_ipow(begin_lambda, 2) + 8.04817e-05 *lens_ipow(begin_y, 3) + 0.00279415 *lens_ipow(begin_x, 2)*begin_dy + 3.41984 *lens_ipow(begin_dy, 3) + 9.26518e-07 *lens_ipow(begin_y, 4)*begin_dy + 2.87459e-06 *begin_x*lens_ipow(begin_y, 3)*begin_dx + 0.00455595 *lens_ipow(begin_y, 2)*lens_ipow(begin_dx, 2)*begin_dy + 6.04446e-08 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 3) + -0.0154199 *begin_y*lens_ipow(begin_dy, 4) + 0.000110151 *lens_ipow(begin_y, 3)*lens_ipow(begin_dx, 2) + 2.2257e-08 *lens_ipow(begin_y, 5) + 0.000463255 *lens_ipow(begin_x, 2)*lens_ipow(begin_dy, 3) + 0.0936823 *begin_y*lens_ipow(begin_dx, 2)*lens_ipow(begin_dy, 2)*begin_lambda + -2.23986e-08 *lens_ipow(begin_x, 2)*lens_ipow(begin_y, 3)*begin_lambda + -3.50511e-07 *lens_ipow(begin_x, 5)*begin_dx*begin_dy*begin_lambda + -6.99685e-09 *lens_ipow(begin_x, 6)*begin_dy*begin_lambda;
  Eigen::Matrix2d dx1_domega0;
  dx1_domega0(0, 0) =  + 36.8509  + 1.25266 *begin_y*begin_dy + 8.91949 *lens_ipow(begin_dy, 2) + 0.0239075 *lens_ipow(begin_y, 2) + 9.26058 *begin_x*begin_dx*begin_lambda + 0.196747 *lens_ipow(begin_x, 2)*begin_lambda + 0.00797067 *lens_ipow(begin_x, 2)*lens_ipow(begin_dx, 2) + 124.095 *lens_ipow(begin_dx, 2)*lens_ipow(begin_lambda, 2) + -0.279842 *lens_ipow(begin_x, 2)*lens_ipow(begin_lambda, 4) + -1.7097e-08 *lens_ipow(begin_x, 4)*lens_ipow(begin_y, 3)*begin_dy + -26.0471 *begin_x*begin_dx*lens_ipow(begin_lambda, 6) + -831.369 *lens_ipow(begin_dx, 2)*lens_ipow(begin_lambda, 8) + 6.73719e-08 *begin_x*lens_ipow(begin_y, 6)*lens_ipow(begin_dx, 3)+0.0f;
  dx1_domega0(0, 1) =  + 1.25266 *begin_y*begin_dx + 17.839 *begin_dx*begin_dy + 34.0113 *begin_x*begin_dy*lens_ipow(begin_lambda, 2) + 1.16157 *begin_x*begin_y*lens_ipow(begin_lambda, 2) + -83.4772 *begin_x*begin_dy*lens_ipow(begin_lambda, 3) + -2.82755 *begin_x*begin_y*lens_ipow(begin_lambda, 3) + 1.90426 *begin_x*begin_y*lens_ipow(begin_lambda, 4) + 56.6363 *begin_x*begin_dy*lens_ipow(begin_lambda, 4) + -1.7097e-08 *lens_ipow(begin_x, 4)*lens_ipow(begin_y, 3)*begin_dx + 6.71371e-08 *lens_ipow(begin_x, 7)*lens_ipow(begin_dy, 3)+0.0f;
  dx1_domega0(1, 0) =  + 6.30234 *begin_y*begin_dx*begin_lambda + 82.4255 *begin_dx*begin_dy*begin_lambda + 0.213198 *begin_x*begin_y*begin_lambda + 4.99446 *begin_x*begin_dy*begin_lambda + -4.72596 *begin_x*begin_dy*lens_ipow(begin_lambda, 2) + -0.000158278 *begin_x*lens_ipow(begin_y, 2)*begin_dy + -6.01873 *begin_y*begin_dx*lens_ipow(begin_lambda, 2) + -0.199349 *begin_x*begin_y*lens_ipow(begin_lambda, 2) + -86.1341 *begin_dx*begin_dy*lens_ipow(begin_lambda, 2) + -0.296101 *lens_ipow(begin_x, 3)*lens_ipow(begin_dx, 4)*lens_ipow(begin_dy, 3) + 7.9392e-08 *lens_ipow(begin_y, 7)*lens_ipow(begin_dx, 3) + -5.44052e-11 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 6)*begin_dy+0.0f;
  dx1_domega0(1, 1) =  + 36.8421  + 0.0798566 *lens_ipow(begin_y, 2) + 4.19167 *begin_y*begin_dy + 28.1488 *lens_ipow(begin_dy, 2) + 41.2127 *lens_ipow(begin_dx, 2)*begin_lambda + 0.0925706 *lens_ipow(begin_x, 2)*begin_lambda + 4.99446 *begin_x*begin_dx*begin_lambda + -4.72596 *begin_x*begin_dx*lens_ipow(begin_lambda, 2) + -0.000158278 *begin_x*lens_ipow(begin_y, 2)*begin_dx + 0.00874442 *lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 2) + -0.0860934 *lens_ipow(begin_x, 2)*lens_ipow(begin_lambda, 2) + -43.0671 *lens_ipow(begin_dx, 2)*lens_ipow(begin_lambda, 2) + -0.17766 *lens_ipow(begin_x, 3)*lens_ipow(begin_dx, 5)*lens_ipow(begin_dy, 2) + -5.44052e-11 *lens_ipow(begin_x, 3)*lens_ipow(begin_y, 6)*begin_dx + -1.40388e-09 *lens_ipow(begin_x, 6)*lens_ipow(begin_y, 2)*lens_ipow(begin_dy, 2)+0.0f;
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