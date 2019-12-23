case nikon__retrofocus_wideangle__1971__18mm:
{
const double dx00 =  + -0.160044  + 0.612015 *lens_ipow(dy, 2) + 1.63107 *lens_ipow(dx, 2) + 0.0478055 *y*dy + 0.00186743 *lens_ipow(y, 2) + 0.209288 *x*dx + 0.0067578 *lens_ipow(x, 2) + -1.39524 *lens_ipow(dx, 2)*lambda + -0.116373 *x*dx*lambda + -0.00235816 *lens_ipow(x, 2)*lambda + 0.00420018 *y*lens_ipow(dy, 3) + -0.0848119 *y*lens_ipow(dx, 2)*dy + 0.00296676 *lens_ipow(y, 2)*lens_ipow(dx, 2) + 0.119334 *x*dx*lens_ipow(dy, 2) + -0.010867 *x*y*dx*dy + 0.00831343 *lens_ipow(x, 2)*lens_ipow(dy, 2) + -0.00173793 *lens_ipow(x, 2)*lens_ipow(dx, 2) + 1.30102e-06 *lens_ipow(x, 4)+0.0f;
const double dx01 =  + 0.29956 *dx*dy + 0.0553394 *y*dx + 0.0478055 *x*dy + 0.00373486 *x*y + -0.205298 *dx*lens_ipow(dy, 3) + 0.111981 *y*lens_ipow(dx, 3) + 0.00420018 *x*lens_ipow(dy, 3) + -0.0848119 *x*lens_ipow(dx, 2)*dy + 0.00593351 *x*y*lens_ipow(dx, 2) + -0.00543352 *lens_ipow(x, 2)*dx*dy+0.0f;
const double dx02 =  + 15.4646  + 10.3325 *lambda + -14.2917 *lens_ipow(lambda, 2) + -5.76141 *lens_ipow(dy, 2) + 0.29956 *y*dy + 0.0276697 *lens_ipow(y, 2) + 3.26213 *x*dx + 0.104644 *lens_ipow(x, 2) + 6.9205 *lens_ipow(lambda, 3) + -31.2669 *lens_ipow(dx, 2)*lambda + -2.79049 *x*dx*lambda + -0.0581866 *lens_ipow(x, 2)*lambda + -0.205298 *y*lens_ipow(dy, 3) + 0.167972 *lens_ipow(y, 2)*lens_ipow(dx, 2) + -0.169624 *x*y*dx*dy + 0.00593351 *x*lens_ipow(y, 2)*dx + 0.059667 *lens_ipow(x, 2)*lens_ipow(dy, 2) + -0.00543352 *lens_ipow(x, 2)*y*dy + -0.00115862 *lens_ipow(x, 3)*dx+0.0f;
const double dx03 =  + -11.5228 *dx*dy + 0.29956 *y*dx + 1.22403 *x*dy + 0.0478055 *x*y + -0.615895 *y*dx*lens_ipow(dy, 2) + 0.0126005 *x*y*lens_ipow(dy, 2) + -0.0848119 *x*y*lens_ipow(dx, 2) + 0.119334 *lens_ipow(x, 2)*dx*dy + -0.00543352 *lens_ipow(x, 2)*y*dx + 0.00554228 *lens_ipow(x, 3)*dy+0.0f;
const double dx04 =  + 10.3325 *dx + -28.5834 *dx*lambda + 20.7615 *dx*lens_ipow(lambda, 2) + -10.4223 *lens_ipow(dx, 3) + -1.39524 *x*lens_ipow(dx, 2) + -0.0581866 *lens_ipow(x, 2)*dx + -0.000786052 *lens_ipow(x, 3)+0.0f;
const double dx10 =  + 0.237957 *dx*dy + 0.0441562 *y*dx + 0.0521412 *x*dy + 0.00356 *x*y + -0.155835 *y*dx*lens_ipow(dy, 2) + -0.00812805 *lens_ipow(y, 2)*dx*dy + 0.106571 *x*lens_ipow(dy, 3) + 0.0041751 *x*y*lens_ipow(dy, 2) + 2.15752e-06 *x*lens_ipow(y, 3) + -0.000539227 *lens_ipow(x, 2)*dx*dy + 7.48079e-05 *lens_ipow(x, 2)*y*dx + 2.6331e-06 *lens_ipow(x, 3)*y+0.0f;
const double dx11 =  + -0.15536  + -0.00799896 *lambda + 0.869034 *lens_ipow(dy, 2) + 0.57695 *lens_ipow(dx, 2) + 0.145098 *y*dy + 0.00543748 *lens_ipow(y, 2) + 0.0441562 *x*dx + 0.00178 *lens_ipow(x, 2) + -1.12335 *lens_ipow(dx, 2)*lens_ipow(dy, 2) + -0.00176308 *lens_ipow(y, 2)*lens_ipow(dy, 2) + 0.00665686 *lens_ipow(y, 2)*lens_ipow(dx, 2) + 1.35898e-06 *lens_ipow(y, 4) + -0.155835 *x*dx*lens_ipow(dy, 2) + -0.0162561 *x*y*dx*dy + 0.00208755 *lens_ipow(x, 2)*lens_ipow(dy, 2) + 3.23628e-06 *lens_ipow(x, 2)*lens_ipow(y, 2) + 2.4936e-05 *lens_ipow(x, 3)*dx + 6.58275e-07 *lens_ipow(x, 4)+0.0f;
const double dx12 =  + -12.0013 *dx*dy + 1.1539 *y*dx + 0.237957 *x*dy + 0.0441562 *x*y + -2.24671 *y*dx*lens_ipow(dy, 2) + 0.00443791 *lens_ipow(y, 3)*dx + -0.155835 *x*y*lens_ipow(dy, 2) + -0.00812805 *x*lens_ipow(y, 2)*dy + -0.000179742 *lens_ipow(x, 3)*dy + 2.4936e-05 *lens_ipow(x, 3)*y+0.0f;
const double dx13 =  + 15.537  + 10.2929 *lambda + -14.543 *lens_ipow(lambda, 2) + -16.9246 *lens_ipow(dy, 2) + -6.00065 *lens_ipow(dx, 2) + 1.73807 *y*dy + 0.0725489 *lens_ipow(y, 2) + 0.237957 *x*dx + 0.0260706 *lens_ipow(x, 2) + 7.07517 *lens_ipow(lambda, 3) + -2.24671 *y*lens_ipow(dx, 2)*dy + -0.00117539 *lens_ipow(y, 3)*dy + -0.311669 *x*y*dx*dy + -0.00812805 *x*lens_ipow(y, 2)*dx + 0.159856 *lens_ipow(x, 2)*lens_ipow(dy, 2) + 0.0041751 *lens_ipow(x, 2)*y*dy + -0.000179742 *lens_ipow(x, 3)*dx+0.0f;
const double dx14 =  + 10.2929 *dy + -0.00799896 *y + -29.0861 *dy*lambda + 21.2255 *dy*lens_ipow(lambda, 2)+0.0f;
const double dx20 =  + -0.0499329  + 0.0101433 *lambda + -0.006542 *lens_ipow(lambda, 2) + -0.0295855 *lens_ipow(dy, 2) + 0.0199315 *lens_ipow(dx, 2) + -0.00249575 *y*dy + -4.36396e-05 *lens_ipow(y, 2) + -0.00860351 *x*dx*lambda + -0.000231976 *lens_ipow(x, 2)*lambda + 0.00334182 *x*dx*lens_ipow(dy, 2) + 0.000328025 *x*y*dx*dy + -3.35813e-07 *lens_ipow(x, 2)*lens_ipow(y, 2) + -0.15954 *lens_ipow(dx, 2)*lens_ipow(lambda, 4) + -1.77869e-09 *lens_ipow(x, 6) + 0.00020885 *lens_ipow(x, 2)*lens_ipow(lambda, 6) + -3.18104e-07 *lens_ipow(x, 5)*lens_ipow(dx, 3) + -1.27245e-06 *lens_ipow(y, 5)*lens_ipow(dx, 4)*dy + -5.85617e-14 *lens_ipow(x, 4)*lens_ipow(y, 6) + 6.76593e-07 *lens_ipow(x, 5)*lens_ipow(dx, 5)+0.0f;
const double dx21 =  + 0.000196451 *y*dx + -0.00249575 *x*dy + -8.72792e-05 *x*y + 0.000164012 *lens_ipow(x, 2)*dx*dy + -2.23875e-07 *lens_ipow(x, 3)*y + -3.30624e-05 *lens_ipow(y, 3)*dx*lens_ipow(dy, 2) + 4.25342e-08 *lens_ipow(y, 5)*dx + 4.57281e-06 *lens_ipow(y, 5)*lens_ipow(dx, 5) + -6.36226e-06 *x*lens_ipow(y, 4)*lens_ipow(dx, 4)*dy + -7.0274e-14 *lens_ipow(x, 5)*lens_ipow(y, 5)+0.0f;
const double dx22 =  + -1.03521  + -0.235099 *lens_ipow(dy, 2) + 9.82253e-05 *lens_ipow(y, 2) + 0.039863 *x*dx + 4.86871 *lens_ipow(dx, 2)*lambda + -0.00430175 *lens_ipow(x, 2)*lambda + 0.00167091 *lens_ipow(x, 2)*lens_ipow(dy, 2) + 0.000164012 *lens_ipow(x, 2)*y*dy + 0.0387146 *lens_ipow(lambda, 6) + -10.5718 *lens_ipow(dx, 2)*lens_ipow(lambda, 4) + -8.26559e-06 *lens_ipow(y, 4)*lens_ipow(dy, 2) + 7.08904e-09 *lens_ipow(y, 6) + -0.319081 *x*dx*lens_ipow(lambda, 4) + -1.59052e-07 *lens_ipow(x, 6)*lens_ipow(dx, 2) + 3.81068e-06 *lens_ipow(y, 6)*lens_ipow(dx, 4) + -5.08981e-06 *x*lens_ipow(y, 5)*lens_ipow(dx, 3)*dy + 5.63828e-07 *lens_ipow(x, 6)*lens_ipow(dx, 4)+0.0f;
const double dx23 =  + -0.470198 *dx*dy + -0.059171 *x*dy + -0.00249575 *x*y + 0.00334182 *lens_ipow(x, 2)*dx*dy + 0.000164012 *lens_ipow(x, 2)*y*dx + -1.65312e-05 *lens_ipow(y, 4)*dx*dy + -1.27245e-06 *x*lens_ipow(y, 5)*lens_ipow(dx, 4)+0.0f;
const double dx24 =  + 0.0101433 *x + -0.013084 *x*lambda + 1.6229 *lens_ipow(dx, 3) + -0.00430175 *lens_ipow(x, 2)*dx + -7.73255e-05 *lens_ipow(x, 3) + 0.232288 *dx*lens_ipow(lambda, 5) + -14.0957 *lens_ipow(dx, 3)*lens_ipow(lambda, 3) + -0.638161 *x*lens_ipow(dx, 2)*lens_ipow(lambda, 3) + 0.000417699 *lens_ipow(x, 3)*lens_ipow(lambda, 5)+0.0f;
const double dx30 =  + 0.0590055 *dx*dy + -0.000400082 *y*dx + -0.00368144 *y*dx*lambda + -0.000122909 *x*y*lambda + -0.00721798 *y*lens_ipow(dx, 3) + -0.00161207 *x*y*lens_ipow(dx, 2) + -9.32879e-05 *lens_ipow(x, 2)*y*dx + -1.77378e-06 *lens_ipow(x, 3)*y + 0.000342869 *x*y*lens_ipow(dy, 2)*lambda + -2.03174e-07 *x*lens_ipow(y, 3)*lambda + -2.37856e-06 *x*lens_ipow(y, 3)*lens_ipow(dy, 2) + -0.123112 *dx*lens_ipow(dy, 3)*lens_ipow(lambda, 3) + -0.000255656 *lens_ipow(y, 3)*dx*lens_ipow(dy, 4) + 0.000363916 *lens_ipow(x, 3)*lens_ipow(dy, 5)*lambda + -0.000516884 *x*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 3)*lens_ipow(lambda, 2)+0.0f;
const double dx31 =  + -0.0497363  + 0.00914487 *lambda + -0.00558881 *lens_ipow(lambda, 2) + -0.0045402 *y*dy + -0.000106854 *lens_ipow(y, 2) + -0.000400082 *x*dx + -0.0588882 *lens_ipow(dx, 2)*lambda + -0.00368144 *x*dx*lambda + -6.14547e-05 *lens_ipow(x, 2)*lambda + -1.0993e-05 *lens_ipow(y, 3)*dy + -4.81057e-07 *lens_ipow(y, 4) + -0.00721798 *x*lens_ipow(dx, 3) + -0.000806033 *lens_ipow(x, 2)*lens_ipow(dx, 2) + -3.1096e-05 *lens_ipow(x, 3)*dx + -4.43445e-07 *lens_ipow(x, 4) + 0.000171435 *lens_ipow(x, 2)*lens_ipow(dy, 2)*lambda + -3.04761e-07 *lens_ipow(x, 2)*lens_ipow(y, 2)*lambda + -3.56785e-06 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dy, 2) + -0.000766967 *x*lens_ipow(y, 2)*dx*lens_ipow(dy, 4) + -0.0537867 *lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 6) + -0.000516884 *lens_ipow(x, 2)*y*lens_ipow(dx, 2)*lens_ipow(dy, 3)*lens_ipow(lambda, 2)+0.0f;
const double dx32 =  + 2.34086 *dx*dy + 0.0590055 *x*dy + -0.000400082 *x*y + -0.117776 *y*dx*lambda + -0.00368144 *x*y*lambda + -0.0216539 *x*y*lens_ipow(dx, 2) + -0.00161207 *lens_ipow(x, 2)*y*dx + -3.1096e-05 *lens_ipow(x, 3)*y + -0.123112 *x*lens_ipow(dy, 3)*lens_ipow(lambda, 3) + -0.000255656 *x*lens_ipow(y, 3)*lens_ipow(dy, 4) + -0.0358578 *lens_ipow(y, 3)*dx*lens_ipow(dy, 6) + -0.000516884 *lens_ipow(x, 2)*lens_ipow(y, 2)*dx*lens_ipow(dy, 3)*lens_ipow(lambda, 2)+0.0f;
const double dx33 =  + -1.03646  + 1.28531 *lens_ipow(dy, 2) + 1.17043 *lens_ipow(dx, 2) + -0.0022701 *lens_ipow(y, 2) + 0.0590055 *x*dx + 0.310007 *lens_ipow(dy, 2)*lambda + -2.74825e-06 *lens_ipow(y, 4) + 0.000342869 *lens_ipow(x, 2)*y*dy*lambda + -2.37856e-06 *lens_ipow(x, 2)*lens_ipow(y, 3)*dy + -0.369336 *x*dx*lens_ipow(dy, 2)*lens_ipow(lambda, 3) + -0.00102262 *x*lens_ipow(y, 3)*dx*lens_ipow(dy, 3) + 0.000454895 *lens_ipow(x, 4)*lens_ipow(dy, 4)*lambda + -0.107573 *lens_ipow(y, 3)*lens_ipow(dx, 2)*lens_ipow(dy, 5) + -0.000775326 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 2)*lens_ipow(lambda, 2)+0.0f;
const double dx34 =  + 0.00914487 *y + -0.0111776 *y*lambda + 0.103336 *lens_ipow(dy, 3) + -0.0588882 *y*lens_ipow(dx, 2) + -0.00368144 *x*y*dx + -6.14547e-05 *lens_ipow(x, 2)*y + 0.000171435 *lens_ipow(x, 2)*y*lens_ipow(dy, 2) + -1.01587e-07 *lens_ipow(x, 2)*lens_ipow(y, 3) + -0.369336 *x*dx*lens_ipow(dy, 3)*lens_ipow(lambda, 2) + 9.09791e-05 *lens_ipow(x, 4)*lens_ipow(dy, 5) + -0.000516884 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 3)*lambda+0.0f;
const double dx40 =  + -0.250079 *lens_ipow(dx, 3) + 0.0017805 *y*dx*dy + -0.0211534 *x*lens_ipow(dx, 2) + -4.84586e-05 *x*y*dy + -4.3408e-06 *x*lens_ipow(y, 2) + -0.000761444 *lens_ipow(x, 2)*dx + -1.13787e-05 *lens_ipow(x, 3) + -0.0026451 *x*lens_ipow(dx, 4) + 0.976081 *lens_ipow(dx, 3)*lens_ipow(dy, 4) + 8.97342e-08 *x*lens_ipow(y, 4)*lens_ipow(dx, 2) + 9.96904e-05 *lens_ipow(x, 3)*lens_ipow(dy, 4) + -2.2746e-10 *lens_ipow(x, 3)*lens_ipow(y, 4) + -5.02966e-09 *lens_ipow(x, 6)*dx + -1.63965e-10 *lens_ipow(x, 7)+0.0f;
const double dx41 =  + 0.000632595 *y*lens_ipow(dx, 2) + 0.0017805 *x*dx*dy + -2.42293e-05 *lens_ipow(x, 2)*dy + -4.3408e-06 *lens_ipow(x, 2)*y + -4.70422 *lens_ipow(dy, 5) + -0.266402 *y*lens_ipow(dy, 4) + -1.14294e-05 *lens_ipow(y, 4)*dy + -2.50715e-07 *lens_ipow(y, 5) + -0.133427 *lens_ipow(dy, 7) + 1.79468e-07 *lens_ipow(x, 2)*lens_ipow(y, 3)*lens_ipow(dx, 2) + -2.2746e-10 *lens_ipow(x, 4)*lens_ipow(y, 3)+0.0f;
const double dx42 =  + -2.77795 *dx*lens_ipow(dy, 2) + -10.6626 *lens_ipow(dx, 3) + 0.000632595 *lens_ipow(y, 2)*dx + -0.750237 *x*lens_ipow(dx, 2) + 0.0017805 *x*y*dy + -0.0211534 *lens_ipow(x, 2)*dx + -0.000253815 *lens_ipow(x, 3) + -0.0052902 *lens_ipow(x, 2)*lens_ipow(dx, 3) + 2.92824 *x*lens_ipow(dx, 2)*lens_ipow(dy, 4) + 8.97342e-08 *lens_ipow(x, 2)*lens_ipow(y, 4)*dx + -7.18522e-10 *lens_ipow(x, 7)+0.0f;
const double dx43 =  + -0.0170035 *dy + -2.77795 *lens_ipow(dx, 2)*dy + 0.0017805 *x*y*dx + -2.42293e-05 *lens_ipow(x, 2)*y + -290.24 *lens_ipow(dy, 5) + -23.5211 *y*lens_ipow(dy, 4) + -0.532805 *lens_ipow(y, 2)*lens_ipow(dy, 3) + -2.28588e-06 *lens_ipow(y, 5) + -0.933991 *y*lens_ipow(dy, 6) + 3.90432 *x*lens_ipow(dx, 3)*lens_ipow(dy, 3) + 9.96904e-05 *lens_ipow(x, 4)*lens_ipow(dy, 3)+0.0f;
const double dx44 =  + 2.05257  + -8.88827 *lambda + 13.5978 *lens_ipow(lambda, 2) + -7.16285 *lens_ipow(lambda, 3)+0.0f;
} break;