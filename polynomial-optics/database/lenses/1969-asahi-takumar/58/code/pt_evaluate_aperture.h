case asahi__takumar__1969__58mm:
{
out[0] =  + 35.3504 *dx + 0.332363 *x + 6.97928 *dx*lambda + 0.191351 *x*lambda + -4.80586 *dx*lens_ipow(lambda, 2) + -20.3723 *dx*lens_ipow(dy, 2) + -20.1465 *lens_ipow(dx, 3) + -0.131496 *y*dx*dy + -0.133966 *x*lens_ipow(lambda, 2) + -0.128929 *x*lens_ipow(dy, 2) + -0.272339 *x*lens_ipow(dx, 2) + 0.00123259 *x*y*dy + -8.13897e-05 *x*lens_ipow(y, 2) + 0.00301142 *lens_ipow(x, 2)*dx + -8.77939e-05 *lens_ipow(x, 3) + 0.00293381 *lens_ipow(y, 2)*dx*lambda + -0.2949 *y*dx*lens_ipow(dy, 3) + 0.0184865 *x*y*lens_ipow(dx, 2)*dy + -1.18574e-07 *x*lens_ipow(y, 4) + -4.20053e-07 *lens_ipow(x, 3)*lens_ipow(y, 2) + -9.8336e-08 *lens_ipow(x, 5) + 3.56329e-07 *lens_ipow(x, 3)*lens_ipow(y, 2)*lambda + -0.0195012 *lens_ipow(y, 2)*lens_ipow(dx, 3)*lens_ipow(lambda, 2) + -0.074804 *lens_ipow(x, 2)*dx*lens_ipow(dy, 4);
out[1] =  + 35.372 *dy + 0.33302 *y + 6.83847 *dy*lambda + 0.19069 *y*lambda + -4.6714 *dy*lens_ipow(lambda, 2) + -20.1086 *lens_ipow(dy, 3) + -20.0429 *lens_ipow(dx, 2)*dy + -0.133313 *y*lens_ipow(lambda, 2) + -0.273146 *y*lens_ipow(dy, 2) + -0.160689 *y*lens_ipow(dx, 2) + 0.003187 *lens_ipow(y, 2)*dy + -8.68112e-05 *lens_ipow(y, 3) + -0.152337 *x*dx*dy + 0.00124609 *x*y*dx + -8.49409e-05 *lens_ipow(x, 2)*y + 0.00302293 *lens_ipow(x, 2)*dy*lambda + 0.222472 *y*lens_ipow(dx, 4) + -0.0108468 *lens_ipow(y, 2)*lens_ipow(dx, 2)*dy + -1.0183e-07 *lens_ipow(y, 5) + 0.0156842 *x*y*dx*lens_ipow(dy, 2) + -4.09e-07 *lens_ipow(x, 2)*lens_ipow(y, 3) + -1.07898e-07 *lens_ipow(x, 4)*y + 3.49524e-07 *lens_ipow(x, 2)*lens_ipow(y, 3)*lambda + -0.0214537 *lens_ipow(x, 2)*lens_ipow(dy, 3)*lens_ipow(lambda, 2);
out[2] =  + 0.357561 *dx + -0.0253258 *x + 0.00806322 *x*lambda + -0.697798 *dx*lens_ipow(dy, 2) + -0.78774 *lens_ipow(dx, 3) + -0.022616 *y*dx*dy + -9.21474e-05 *lens_ipow(y, 2)*dx + -0.00567841 *x*lens_ipow(lambda, 2) + -0.010936 *x*lens_ipow(dy, 2) + -0.0338437 *x*lens_ipow(dx, 2) + -0.000115133 *x*y*dy + -8.5487e-06 *x*lens_ipow(y, 2) + -0.00024058 *lens_ipow(x, 2)*dx + -9.22568e-06 *lens_ipow(x, 3) + 0.551515 *lens_ipow(dx, 5) + -1.91019e-08 *lens_ipow(x, 3)*lens_ipow(y, 2) + 2.3529e-08 *lens_ipow(x, 3)*lens_ipow(y, 2)*lambda + -1.35646e-11 *x*lens_ipow(y, 6) + 1.74617e-09 *lens_ipow(x, 3)*lens_ipow(y, 3)*dy + 2.05129e-09 *lens_ipow(x, 4)*lens_ipow(y, 2)*dx + 8.98293e-10 *lens_ipow(x, 6)*dx + -2.65595e-07 *x*lens_ipow(y, 4)*lens_ipow(dx, 4) + -6.69187e-11 *lens_ipow(x, 7)*lens_ipow(dy, 2) + 154.671 *lens_ipow(dx, 5)*lens_ipow(dy, 4)*lambda;
out[3] =  + 0.355879 *dy + -0.0254446 *y + 0.00841777 *y*lambda + -0.723072 *lens_ipow(dy, 3) + -0.694961 *lens_ipow(dx, 2)*dy + -0.00595967 *y*lens_ipow(lambda, 2) + -0.0338035 *y*lens_ipow(dy, 2) + -0.0108788 *y*lens_ipow(dx, 2) + -0.000239358 *lens_ipow(y, 2)*dy + -9.16709e-06 *lens_ipow(y, 3) + -0.0225832 *x*dx*dy + -0.000113396 *x*y*dx + -9.15125e-05 *lens_ipow(x, 2)*dy + -8.47201e-06 *lens_ipow(x, 2)*y + -1.94504e-08 *lens_ipow(x, 2)*lens_ipow(y, 3) + 2.33551e-08 *lens_ipow(x, 2)*lens_ipow(y, 3)*lambda + 8.99913e-10 *lens_ipow(y, 6)*dy + 1.99827e-09 *lens_ipow(x, 2)*lens_ipow(y, 4)*dy + 1.70736e-09 *lens_ipow(x, 3)*lens_ipow(y, 3)*dx + -1.36642e-11 *lens_ipow(x, 6)*y + -7.02255e-11 *lens_ipow(y, 7)*lens_ipow(dx, 2) + -2.75169e-07 *lens_ipow(x, 4)*y*lens_ipow(dy, 4) + 13.8536 *lens_ipow(dy, 9)*lambda + 151.703 *lens_ipow(dx, 4)*lens_ipow(dy, 5)*lambda;
out_transmittance =  + 0.461253  + 0.654458 *lambda + -0.899593 *lens_ipow(lambda, 2) + -2.97804e-06 *lens_ipow(y, 2) + -2.93442e-06 *lens_ipow(x, 2) + 0.435779 *lens_ipow(lambda, 3) + -0.410214 *lens_ipow(dy, 4) + -0.888818 *lens_ipow(dx, 2)*lens_ipow(dy, 2) + -0.408709 *lens_ipow(dx, 4) + -0.00752878 *y*lens_ipow(dy, 3) + -0.00754562 *y*lens_ipow(dx, 2)*dy + -0.00756252 *x*dx*lens_ipow(dy, 2) + -0.00753132 *x*lens_ipow(dx, 3) + -8.82919e-05 *x*y*dx*dy + -1.89884e-07 *lens_ipow(y, 4)*lens_ipow(dy, 2) + -2.78579e-07 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dy, 2) + -2.73682e-07 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2) + -1.9701e-07 *lens_ipow(x, 4)*lens_ipow(dx, 2) + -8.47412e-07 *lens_ipow(y, 4)*lens_ipow(dx, 4) + -8.40664e-07 *lens_ipow(x, 4)*lens_ipow(dy, 4) + -2.82462 *lens_ipow(dy, 8)*lambda + -28.1263 *lens_ipow(dx, 4)*lens_ipow(dy, 4)*lambda + -2.94897 *lens_ipow(dx, 8)*lambda + 0.024475 *x*y*lens_ipow(dx, 3)*lens_ipow(dy, 3)*lambda;
} break;