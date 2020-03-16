case kodak__petzval__1948__58mm:
{
out[0] =  + 57.929 *dx + 0.556916 *x + -0.0329632 *x*lambda + -25.9559 *dx*lens_ipow(dy, 2) + -27.7084 *lens_ipow(dx, 3) + 0.407077 *y*dx*dy + 0.0140892 *lens_ipow(y, 2)*dx + 0.0222124 *x*lens_ipow(lambda, 2) + 0.535032 *x*lens_ipow(dy, 2) + 0.758416 *x*lens_ipow(dx, 2) + 0.0352314 *x*y*dy + 0.00039312 *x*lens_ipow(y, 2) + 0.0421927 *lens_ipow(x, 2)*dx + 0.000308262 *lens_ipow(x, 3) + 0.106561 *lens_ipow(x, 2)*lens_ipow(dx, 3) + 0.0073804 *lens_ipow(x, 3)*lens_ipow(dx, 2) + 0.000170508 *lens_ipow(x, 4)*dx + 1.28331e-06 *lens_ipow(x, 5) + -1.86118e-06 *lens_ipow(x, 2)*lens_ipow(y, 3)*dx*dy + -3.12295e-10 *lens_ipow(x, 5)*lens_ipow(y, 2) + -0.276811 *x*y*lens_ipow(dx, 2)*lens_ipow(dy, 3)*lambda + 9.14768e-09 *x*lens_ipow(y, 5)*dy*lambda;
out[1] =  + 57.9212 *dy + 0.556841 *y + -0.0323802 *y*lambda + -27.4589 *lens_ipow(dy, 3) + -26.1764 *lens_ipow(dx, 2)*dy + 0.0216661 *y*lens_ipow(lambda, 2) + 0.759258 *y*lens_ipow(dy, 2) + 0.488764 *y*lens_ipow(dx, 2) + 0.0421223 *lens_ipow(y, 2)*dy + 0.000307966 *lens_ipow(y, 3) + 0.398698 *x*dx*dy + 0.033311 *x*y*dx + 0.0141201 *lens_ipow(x, 2)*dy + 0.000388187 *lens_ipow(x, 2)*y + 0.10207 *lens_ipow(y, 2)*lens_ipow(dy, 3) + 0.00721062 *lens_ipow(y, 3)*lens_ipow(dy, 2) + 0.000376859 *lens_ipow(y, 3)*lens_ipow(dx, 2) + 0.000168652 *lens_ipow(y, 4)*dy + 1.27145e-06 *lens_ipow(y, 5) + 1.46993e-05 *x*lens_ipow(y, 3)*dx + -7.28989e-08 *lens_ipow(x, 4)*y + 0.447231 *x*dx*lens_ipow(dy, 3)*lens_ipow(lambda, 2);
out[2] =  + -1.40845 *dx + -0.0306545 *x + 0.00023907 *x*lambda + -0.737734 *dx*lens_ipow(dy, 2) + 0.806049 *lens_ipow(dx, 3) + -0.0348391 *y*dx*dy + -0.000314392 *lens_ipow(y, 2)*dx + -0.0248234 *x*lens_ipow(dy, 2) + -0.000964257 *x*y*dy + -4.99464e-06 *x*lens_ipow(y, 2) + -0.000539385 *lens_ipow(x, 2)*dx + -2.16149e-06 *lens_ipow(x, 3) + -0.239651 *lens_ipow(dx, 3)*lambda + 0.976033 *dx*lens_ipow(dy, 4) + 1.82526 *lens_ipow(dx, 3)*lens_ipow(dy, 2) + -0.00357274 *x*lens_ipow(dx, 2)*lens_ipow(lambda, 2) + -0.0312388 *x*lens_ipow(dx, 4) + 8.53971e-06 *lens_ipow(x, 2)*y*dx*dy + 1.05372e-05 *lens_ipow(x, 3)*lens_ipow(dx, 2) + 0.0101301 *dx*lens_ipow(lambda, 5) + -0.00040734 *lens_ipow(y, 2)*dx*lens_ipow(dy, 2)*lambda + 7.89562e-12 *lens_ipow(x, 3)*lens_ipow(y, 4);
out[3] =  + -1.40815 *dy + -0.0306362 *y + 0.000236412 *y*lambda + 0.811343 *lens_ipow(dy, 3) + 2.0346 *lens_ipow(dx, 2)*dy + 0.00145314 *y*lens_ipow(dx, 2) + -0.000535662 *lens_ipow(y, 2)*dy + -2.16233e-06 *lens_ipow(y, 3) + 0.0525283 *x*dx*dy + -0.000129955 *x*y*dx + 0.000266248 *lens_ipow(x, 2)*dy + -0.268095 *lens_ipow(dy, 3)*lambda + -0.0798762 *lens_ipow(dx, 2)*dy*lambda + 0.00977396 *dy*lens_ipow(lambda, 4) + 1.54939 *lens_ipow(dx, 2)*lens_ipow(dy, 3) + -0.00393053 *y*lens_ipow(dy, 2)*lens_ipow(lambda, 2) + -0.031067 *y*lens_ipow(dy, 4) + 1.04254e-05 *lens_ipow(y, 3)*lens_ipow(dy, 2) + -2.59103e-06 *lens_ipow(y, 3)*lens_ipow(dx, 2) + -0.0239333 *x*lens_ipow(dx, 3)*dy + 4.69398e-09 *lens_ipow(x, 2)*lens_ipow(y, 3) + 3.06118e-09 *lens_ipow(x, 4)*y;
out_transmittance =  + 0.53546  + 0.644943 *lambda + -0.888791 *lens_ipow(lambda, 2) + 0.430822 *lens_ipow(lambda, 3) + -0.000664659 *lens_ipow(y, 2)*lens_ipow(dx, 2) + -0.00338703 *x*y*dx*dy + -0.000114326 *x*lens_ipow(y, 2)*dx + -0.000566222 *lens_ipow(x, 2)*lens_ipow(dy, 2) + -0.00177956 *lens_ipow(x, 2)*lens_ipow(dx, 2) + -0.000112054 *lens_ipow(x, 2)*y*dy + -2.97932e-06 *lens_ipow(x, 2)*lens_ipow(y, 2) + -8.75096e-05 *lens_ipow(x, 3)*dx + -1.12123e-06 *lens_ipow(x, 4) + -0.0449872 *lens_ipow(y, 2)*lens_ipow(dy, 4) + -0.0039516 *lens_ipow(y, 3)*lens_ipow(dy, 3) + -0.000139045 *lens_ipow(y, 4)*lens_ipow(dy, 2) + -2.386e-06 *lens_ipow(y, 5)*dy + -1.70635e-08 *lens_ipow(y, 6) + 7.39176e-08 *lens_ipow(x, 3)*lens_ipow(y, 3)*dx*dy + -3.6793e-11 *lens_ipow(x, 4)*lens_ipow(y, 4) + -2.90206e-10 *lens_ipow(x, 7)*dx + -6.78241e-12 *lens_ipow(x, 8);
} break;
