case kodak__petzval__1948__65mm:
{
out[0] =  + 49.8357 *dx + 0.793548 *x + 0.791318 *dx*lambda + -0.00151901 *x*lambda + -0.577759 *dx*lens_ipow(lambda, 2) + 0.512329 *y*dx*dy + 0.00810194 *lens_ipow(y, 2)*dx + 0.100015 *x*lens_ipow(dy, 2) + 0.571734 *x*lens_ipow(dx, 2) + 0.011248 *x*y*dy + 0.000113484 *x*lens_ipow(y, 2) + 0.0170971 *lens_ipow(x, 2)*dx + 8.34546e-05 *lens_ipow(x, 3) + 27.5173 *lens_ipow(dx, 3)*lens_ipow(dy, 2) + -0.039681 *x*y*lens_ipow(dx, 2)*dy + 0.000461425 *x*lens_ipow(y, 2)*lens_ipow(dy, 2) + 1.62897e-05 *x*lens_ipow(y, 3)*dy + 1.18569e-07 *x*lens_ipow(y, 4) + 0.0424619 *lens_ipow(x, 2)*lens_ipow(dx, 3) + 1.89441e-05 *lens_ipow(x, 2)*lens_ipow(y, 2)*dx + 0.000323218 *lens_ipow(x, 3)*lens_ipow(dy, 2) + 0.00293363 *lens_ipow(x, 3)*lens_ipow(dx, 2) + 1.94167e-05 *lens_ipow(x, 3)*y*dy + 3.65412e-07 *lens_ipow(x, 3)*lens_ipow(y, 2) + 6.60368e-05 *lens_ipow(x, 4)*dx + 4.70589e-07 *lens_ipow(x, 5) + 0.0187018 *lens_ipow(x, 2)*y*lens_ipow(dx, 3)*lens_ipow(dy, 3)*lambda + -6.36602e-12 *lens_ipow(x, 6)*lens_ipow(y, 3)*dx*dy;
out[1] =  + 49.8145 *dy + 0.793134 *y + 0.782763 *dy*lambda + -0.00173041 *y*lambda + -0.569979 *dy*lens_ipow(lambda, 2) + 1.8223 *lens_ipow(dx, 2)*dy + 0.540615 *y*lens_ipow(dy, 2) + 0.143649 *y*lens_ipow(dx, 2) + 0.016552 *lens_ipow(y, 2)*dy + 8.64649e-05 *lens_ipow(y, 3) + 0.564544 *x*dx*dy + 0.0129486 *x*y*dx + 0.008746 *lens_ipow(x, 2)*dy + 0.00013555 *lens_ipow(x, 2)*y + 14.8466 *lens_ipow(dy, 5) + 2.28976 *y*lens_ipow(dy, 4) + 0.148822 *lens_ipow(y, 2)*lens_ipow(dy, 3) + 0.00507292 *lens_ipow(y, 3)*lens_ipow(dy, 2) + 8.44335e-05 *lens_ipow(y, 4)*dy + 5.10374e-07 *lens_ipow(y, 5) + 0.00018379 *lens_ipow(x, 2)*y*lens_ipow(dy, 2) + 7.31837e-06 *lens_ipow(x, 2)*lens_ipow(y, 2)*dy + 0.327032 *y*lens_ipow(dx, 2)*lens_ipow(dy, 2)*lambda + 5.28801e-09 *lens_ipow(x, 5)*y*dx + -347.529 *lens_ipow(dx, 8)*dy + 3.66578e-05 *lens_ipow(x, 2)*lens_ipow(y, 3)*lens_ipow(dx, 2)*lens_ipow(dy, 2) + -2.26265e-08 *lens_ipow(x, 3)*lens_ipow(y, 4)*dx*dy + 3.3364e-12 *lens_ipow(x, 4)*lens_ipow(y, 5);
out[2] =  + 0.581607 *dx + -0.0107614 *x + -0.179966 *dx*lens_ipow(dy, 2) + -0.223445 *lens_ipow(dx, 3) + 0.013369 *y*dx*dy + 0.000268833 *lens_ipow(y, 2)*dx + 0.00500965 *x*lens_ipow(dy, 2) + 0.0154507 *x*lens_ipow(dx, 2) + 0.000591278 *x*y*dy + 6.40062e-06 *x*lens_ipow(y, 2) + 0.000752304 *lens_ipow(x, 2)*dx + 5.03575e-06 *lens_ipow(x, 3) + 0.00104768 *lens_ipow(x, 2)*lens_ipow(dx, 3) + 8.77827e-05 *lens_ipow(x, 3)*lens_ipow(dx, 2) + 2.23209e-06 *lens_ipow(x, 4)*dx + 1.74792e-08 *lens_ipow(x, 5) + -0.000865152 *lens_ipow(x, 2)*dx*lens_ipow(dy, 2)*lambda + 4.12906e-07 *lens_ipow(x, 3)*y*dy*lambda + 0.0600005 *x*lens_ipow(dy, 6) + 0.000280395 *x*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 2) + 1.14933e-06 *x*lens_ipow(y, 3)*lens_ipow(dy, 3) + 1.63744e-06 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 3) + -2.07653e-07 *lens_ipow(x, 2)*lens_ipow(y, 3)*dx*dy + 3.72822e-11 *lens_ipow(x, 3)*lens_ipow(y, 4) + 0.083707 *y*dx*lens_ipow(dy, 5)*lambda + 1.70699e-11 *lens_ipow(x, 5)*lens_ipow(y, 2)*lambda + -0.0646334 *x*y*lens_ipow(dx, 6)*dy*lambda + 9.43238e-09 *lens_ipow(x, 5)*y*lens_ipow(dx, 2)*dy*lambda;
out[3] =  + 0.581579 *dy + -0.010769 *y + -0.202601 *lens_ipow(dy, 3) + -0.180116 *lens_ipow(dx, 2)*dy + 0.0157879 *y*lens_ipow(dy, 2) + 0.00555545 *y*lens_ipow(dx, 2) + 0.000757536 *lens_ipow(y, 2)*dy + 5.1755e-06 *lens_ipow(y, 3) + 0.013955 *x*dx*dy + 0.000612511 *x*y*dx + 0.000276913 *lens_ipow(x, 2)*dy + 6.6723e-06 *lens_ipow(x, 2)*y + -0.0311432 *lens_ipow(dy, 3)*lambda + 0.000830198 *lens_ipow(y, 2)*lens_ipow(dy, 3) + 7.18082e-05 *lens_ipow(y, 3)*lens_ipow(dy, 2) + 1.91241e-06 *lens_ipow(y, 4)*dy + 1.52354e-08 *lens_ipow(y, 5) + -2.01653e-09 *lens_ipow(x, 2)*lens_ipow(y, 3) + 0.000262345 *lens_ipow(x, 2)*y*lens_ipow(dx, 2)*lens_ipow(dy, 2) + -1.91883e-07 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx*dy + 3.41762e-11 *lens_ipow(x, 4)*lens_ipow(y, 3) + 9.26605e-10 *lens_ipow(x, 5)*y*dx*lambda + -5.29445 *lens_ipow(dx, 6)*dy*lens_ipow(lambda, 2) + -0.00759056 *lens_ipow(y, 2)*lens_ipow(dx, 6)*dy + 0.000946473 *lens_ipow(y, 3)*lens_ipow(dx, 2)*lens_ipow(dy, 4) + 1.00166e-08 *x*lens_ipow(y, 5)*dx*lens_ipow(dy, 2) + 2.40498e-14 *lens_ipow(x, 2)*lens_ipow(y, 7) + 4.57673e-14 *lens_ipow(x, 8)*y*lens_ipow(lambda, 2);
out_transmittance =  + 0.641946  + 0.514388 *lambda + -0.707307 *lens_ipow(lambda, 2) + 0.341823 *lens_ipow(lambda, 3) + 1.11965 *lens_ipow(dx, 2)*lens_ipow(dy, 2) + -0.000880364 *lens_ipow(y, 2)*lens_ipow(dx, 2) + -0.0033474 *x*y*dx*dy + -0.000100299 *x*lens_ipow(y, 2)*dx + -0.00079783 *lens_ipow(x, 2)*lens_ipow(dy, 2) + -9.69376e-05 *lens_ipow(x, 2)*y*dy + -2.28067e-06 *lens_ipow(x, 2)*lens_ipow(y, 2) + -0.0254599 *lens_ipow(y, 2)*lens_ipow(dy, 4) + -0.00224215 *lens_ipow(y, 3)*lens_ipow(dy, 3) + -7.84075e-05 *lens_ipow(y, 4)*lens_ipow(dy, 2) + -1.30085e-06 *lens_ipow(y, 5)*dy + -8.69639e-09 *lens_ipow(y, 6) + -0.025656 *lens_ipow(x, 2)*lens_ipow(dx, 4) + -0.00218607 *lens_ipow(x, 3)*lens_ipow(dx, 3) + -7.54182e-05 *lens_ipow(x, 4)*lens_ipow(dx, 2) + -1.25578e-06 *lens_ipow(x, 5)*dx + -8.51806e-09 *lens_ipow(x, 6) + 0.0329051 *lens_ipow(x, 2)*y*lens_ipow(dx, 4)*lens_ipow(dy, 3) + -1.44881e-12 *lens_ipow(x, 2)*lens_ipow(y, 7)*dy + -2.93626e-14 *lens_ipow(x, 2)*lens_ipow(y, 8) + 4.44111e-08 *lens_ipow(x, 4)*lens_ipow(y, 2)*lens_ipow(dx, 4) + 2.64935e-10 *lens_ipow(x, 5)*lens_ipow(y, 3)*dx*dy + -8.20544e-14 *lens_ipow(x, 6)*lens_ipow(y, 4) + -2.45117e-09 *x*lens_ipow(y, 6)*lens_ipow(dx, 3)*lambda;
} break;