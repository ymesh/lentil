case angenieux_double_gauss_1953_49mm:
{
out[0] =  + 48.8821 *dx + -0.645099 *x + 0.721375 *x*lambda + -19.6882 *dx*lens_ipow(dy, 2) + -18.9497 *lens_ipow(dx, 3) + 0.193832 *y*dx*dy + 0.00510371 *lens_ipow(y, 2)*dx + -0.555092 *x*lens_ipow(lambda, 2) + 0.269599 *x*lens_ipow(dy, 2) + 0.549184 *x*lens_ipow(dx, 2) + 0.007716 *x*y*dy + -0.00130559 *x*lens_ipow(y, 2) + -0.00105494 *lens_ipow(x, 3) + 0.000559786 *x*lens_ipow(y, 2)*lambda + 0.040214 *lens_ipow(x, 2)*dx*lambda + 0.000507259 *lens_ipow(x, 3)*lambda + 0.0360917 *lens_ipow(y, 2)*dx*lens_ipow(dy, 2) + 0.0759788 *x*y*lens_ipow(dx, 2)*dy + -0.00234288 *lens_ipow(x, 3)*lens_ipow(dx, 2) + -1.59685e-06 *lens_ipow(x, 5) + -3.42304e-06 *lens_ipow(y, 5)*dx*dy + -3.83629e-06 *x*lens_ipow(y, 4)*lens_ipow(dx, 2) + -2.63138e-09 *x*lens_ipow(y, 6) + -1.78393e-07 *lens_ipow(x, 3)*lens_ipow(y, 3)*dy + -1.07142e-08 *lens_ipow(x, 3)*lens_ipow(y, 4) + -0.000304642 *lens_ipow(x, 4)*dx*lens_ipow(lambda, 2) + -8.53655e-09 *lens_ipow(x, 5)*lens_ipow(y, 2) + 8.10945e-07 *lens_ipow(x, 6)*dx*lens_ipow(lambda, 3);
out[1] =  + 49.027 *dy + -0.621037 *y + 0.696948 *y*lambda + -23.107 *lens_ipow(dy, 3) + -18.7367 *lens_ipow(dx, 2)*dy + -0.553529 *y*lens_ipow(lambda, 2) + 0.241088 *y*lens_ipow(dx, 2) + 0.0124908 *lens_ipow(y, 2)*dy + -0.00132421 *lens_ipow(y, 3) + 0.00537062 *x*y*dx + -0.00140918 *lens_ipow(x, 2)*y + 0.38429 *y*lens_ipow(dy, 2)*lambda + 0.000582984 *lens_ipow(y, 3)*lambda + 0.277135 *x*dx*dy*lambda + 0.0112343 *lens_ipow(x, 2)*dy*lambda + 0.000706359 *lens_ipow(x, 2)*y*lambda + 18.2152 *lens_ipow(dy, 5) + 1.94318 *y*lens_ipow(dy, 4) + -1.65049e-05 *lens_ipow(y, 4)*dy + 0.144205 *lens_ipow(y, 2)*lens_ipow(dy, 3)*lambda + 0.183519 *x*y*dx*lens_ipow(dy, 2)*lambda + 5.89866 *y*lens_ipow(dx, 4)*lens_ipow(dy, 2) + -3.33064e-09 *lens_ipow(y, 7) + 2.6672 *x*dx*lens_ipow(dy, 5) + -9.20241e-09 *lens_ipow(x, 2)*lens_ipow(y, 5) + 0.000245366 *lens_ipow(x, 4)*lens_ipow(dx, 2)*dy + -8.37379e-09 *lens_ipow(x, 4)*lens_ipow(y, 3) + -2.99011e-09 *lens_ipow(x, 6)*y;
out[2] =  + -0.610441 *dx + -0.0125123 *x + 0.0110383 *dx*lambda + -0.00922338 *x*lambda + 0.148194 *dx*lens_ipow(dy, 2) + 0.22954 *lens_ipow(dx, 3) + 0.00748852 *x*lens_ipow(lambda, 2) + -0.00110408 *x*lens_ipow(dy, 2) + -6.12117e-05 *x*y*dy + 1.80792e-05 *x*lens_ipow(y, 2) + -0.000166332 *lens_ipow(x, 2)*dx + 1.85718e-05 *lens_ipow(x, 3) + -8.28448e-06 *x*lens_ipow(y, 2)*lambda + -8.08293e-06 *lens_ipow(x, 3)*lambda + 0.0003898 *lens_ipow(y, 2)*lens_ipow(dx, 3) + -1.20995e-07 *lens_ipow(y, 4)*dx + -0.00449414 *x*lens_ipow(dy, 4) + -3.49031e-07 *x*lens_ipow(y, 3)*dy + 0.000719834 *lens_ipow(x, 2)*dx*lens_ipow(dy, 2) + 0.0010609 *lens_ipow(x, 2)*lens_ipow(dx, 3) + 3.98186e-05 *lens_ipow(x, 2)*y*dx*dy + 2.57891e-08 *lens_ipow(x, 3)*lens_ipow(y, 2) + 4.08399e-11 *x*lens_ipow(y, 6) + -3.87996e-06 *lens_ipow(x, 4)*lens_ipow(dx, 3) + 4.02693e-11 *lens_ipow(x, 7) + 2.00841e-13 *lens_ipow(x, 7)*lens_ipow(y, 2) + 2.39022e-15 *lens_ipow(x, 5)*lens_ipow(y, 6) + 0.460264 *x*y*lens_ipow(dx, 6)*lens_ipow(dy, 3)*lambda;
out[3] =  + -0.616863 *dy + -0.0119682 *y + 0.0104117 *dy*lambda + -0.0100025 *y*lambda + 0.291716 *lens_ipow(dy, 3) + 0.422799 *lens_ipow(dx, 2)*dy + 0.00733861 *y*lens_ipow(lambda, 2) + -0.00410946 *y*lens_ipow(dx, 2) + 1.36949e-05 *lens_ipow(y, 3) + 0.00307779 *x*dx*dy + -0.000104203 *x*y*dx + 1.44688e-05 *lens_ipow(x, 2)*y + -0.442489 *lens_ipow(dx, 2)*lens_ipow(dy, 3) + -0.320492 *lens_ipow(dx, 4)*dy + -1.11051e-06 *lens_ipow(y, 4)*dy + 2.30472e-05 *x*lens_ipow(y, 2)*dx*dy + -2.41972e-07 *lens_ipow(x, 4)*dy + -4.9917e-07 *lens_ipow(x, 2)*lens_ipow(y, 2)*dy*lambda + 3.92392e-06 *lens_ipow(y, 4)*lens_ipow(dx, 2)*dy + 4.24265e-11 *lens_ipow(y, 7) + 3.65779e-10 *lens_ipow(x, 2)*lens_ipow(y, 5) + 1.29196e-10 *lens_ipow(x, 4)*lens_ipow(y, 3) + 4.1403e-11 *lens_ipow(x, 6)*y + -1.15075 *lens_ipow(dy, 7)*lambda + -0.0653355 *y*lens_ipow(dy, 6)*lambda + 3.55529e-09 *lens_ipow(y, 6)*dy*lambda + -4.4978e-10 *lens_ipow(x, 2)*lens_ipow(y, 5)*lambda + 2.67424e-06 *lens_ipow(x, 4)*lens_ipow(dy, 3)*lambda;
out_transmittance =  + 0.238048  + 0.856356 *lambda + -1.17367 *lens_ipow(lambda, 2) + 0.567787 *lens_ipow(lambda, 3) + -0.000559814 *y*dy*lambda + -0.000554268 *x*dx*lambda + -0.169285 *lens_ipow(dy, 4) + -0.496274 *lens_ipow(dx, 2)*lens_ipow(dy, 2) + -0.17286 *lens_ipow(dx, 4) + -0.00824271 *y*lens_ipow(dy, 3) + -0.00655018 *y*lens_ipow(dx, 2)*dy + -0.000234472 *lens_ipow(y, 2)*lens_ipow(dy, 2) + -0.000123029 *lens_ipow(y, 2)*lens_ipow(dx, 2) + -5.09404e-08 *lens_ipow(y, 4) + -0.00661154 *x*dx*lens_ipow(dy, 2) + -0.00811139 *x*lens_ipow(dx, 3) + -0.000477706 *x*y*dx*dy + -0.000124752 *lens_ipow(x, 2)*lens_ipow(dy, 2) + -0.000235274 *lens_ipow(x, 2)*lens_ipow(dx, 2) + -7.64568e-08 *lens_ipow(x, 2)*lens_ipow(y, 2) + -4.86286e-08 *lens_ipow(x, 4) + -0.120174 *lens_ipow(dy, 4)*lambda + -0.112317 *lens_ipow(dx, 4)*lambda + -0.000909037 *lens_ipow(y, 2)*lens_ipow(dy, 4) + -0.000889541 *lens_ipow(x, 2)*lens_ipow(dx, 4) + 1.02523e-08 *lens_ipow(x, 3)*lens_ipow(y, 3)*dx*dy + -5.84143e-17 *lens_ipow(x, 4)*lens_ipow(y, 8) + -1.75004e-17 *lens_ipow(x, 10)*lens_ipow(y, 2);
} break;
