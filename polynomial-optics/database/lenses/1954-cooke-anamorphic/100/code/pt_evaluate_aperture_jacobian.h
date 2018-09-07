case cooke_anamorphic_1954_100mm:
{
const float dx00 =  + 0.937613  + 0.0893812 *lambda + -0.0547221 *y*dy + -0.000408792 *lens_ipow(y, 2) + -1.77898 *lens_ipow(dy, 2) + -37.6423 *lens_ipow(dx, 2)*lambda + -0.013285 *lens_ipow(x, 2)*lambda + -1.22764 *x*dx*lambda + -0.000573957 *lens_ipow(x, 3)*dx + 0.0116821 *lens_ipow(x, 2)*lens_ipow(lambda, 2) + 32.9374 *lens_ipow(dx, 2)*lens_ipow(lambda, 2) + -6.91297e-06 *lens_ipow(x, 4) + -0.0111437 *lens_ipow(x, 2)*lens_ipow(dx, 2) + 2.37945 *x*dx*lens_ipow(lambda, 3) + -6.30428e-07 *lens_ipow(x, 4)*y*dy + -2.81749e-08 *lens_ipow(x, 4)*lens_ipow(y, 2) + -1.45911 *x*dx*lens_ipow(lambda, 4) + -1.11785e-06 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx + -0.165046 *lens_ipow(lambda, 7)+0.0f;
const float dx01 =  + -2.83632 *dx*dy + -0.0547221 *x*dy + -0.000817585 *x*y + -0.036679 *y*dx + -1.26086e-07 *lens_ipow(x, 5)*dy + -1.12699e-08 *lens_ipow(x, 5)*y + -5.58926e-07 *lens_ipow(x, 4)*y*dx+0.0f;
const float dx02 =  + 47.6584  + 4.20096 *lambda + -2.83632 *y*dy + -313.71 *lens_ipow(dx, 2) + -109.637 *lens_ipow(dy, 2) + -0.0183395 *lens_ipow(y, 2) + -75.2846 *x*dx*lambda + -576.591 *lens_ipow(dx, 2)*lambda + -0.613822 *lens_ipow(x, 2)*lambda + -0.000143489 *lens_ipow(x, 4) + 65.8747 *x*dx*lens_ipow(lambda, 2) + -0.00742911 *lens_ipow(x, 3)*dx + 1.18972 *lens_ipow(x, 2)*lens_ipow(lambda, 3) + -0.729554 *lens_ipow(x, 2)*lens_ipow(lambda, 4) + -2.79463e-07 *lens_ipow(x, 4)*lens_ipow(y, 2) + -8.00047 *lens_ipow(lambda, 7) + 1002.16 *lens_ipow(dx, 2)*lens_ipow(lambda, 5)+0.0f;
const float dx03 =  + -2.83632 *y*dx + -0.0547221 *x*y + -219.274 *dx*dy + -3.55795 *x*dy + -1.26086e-07 *lens_ipow(x, 5)*y+0.0f;
const float dx04 =  + 0.0893812 *x + 4.20096 *dx + -37.6423 *x*lens_ipow(dx, 2) + -192.197 *lens_ipow(dx, 3) + -0.00442832 *lens_ipow(x, 3) + -0.613822 *lens_ipow(x, 2)*dx + 0.00778808 *lens_ipow(x, 3)*lambda + 65.8747 *x*lens_ipow(dx, 2)*lambda + 3.56917 *lens_ipow(x, 2)*dx*lens_ipow(lambda, 2) + -2.91821 *lens_ipow(x, 2)*dx*lens_ipow(lambda, 3) + -56.0033 *dx*lens_ipow(lambda, 6) + 1670.27 *lens_ipow(dx, 3)*lens_ipow(lambda, 4) + -1.15532 *x*lens_ipow(lambda, 6)+0.0f;
const float dx10 =  + -5.3588 *dx*dy + -0.0680939 *y*dx + -0.00132386 *x*y + -0.106061 *x*dy + -0.000299714 *lens_ipow(x, 2)*lens_ipow(y, 2)*dx*dy + -2.5067e-05 *lens_ipow(x, 2)*lens_ipow(y, 3)*dx + -0.000868689 *x*lens_ipow(y, 3)*lens_ipow(dx, 2) + -0.011158 *lens_ipow(y, 3)*lens_ipow(dx, 3) + -2.59653e-07 *lens_ipow(x, 3)*lens_ipow(y, 3) + -8.35573e-06 *lens_ipow(x, 3)*lens_ipow(y, 2)*dy + -0.000134174 *lens_ipow(x, 5)*y*lens_ipow(dy, 4)+0.0f;
const float dx11 =  + 0.530478  + 0.0864972 *lambda + -1.83727 *lens_ipow(dx, 2) + -0.058706 *y*dy + -2.70308 *lens_ipow(dy, 2) + -0.0680939 *x*dx + -0.0589897 *lens_ipow(lambda, 2) + -0.000661932 *lens_ipow(x, 2) + -0.00041642 *lens_ipow(y, 2) + -0.00120663 *lens_ipow(y, 3)*dy + -1.35201 *y*lens_ipow(dy, 3) + -7.96848e-06 *lens_ipow(y, 4) + -0.0653843 *lens_ipow(y, 2)*lens_ipow(dy, 2) + -0.00019981 *lens_ipow(x, 3)*y*dx*dy + -2.5067e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx + -0.00130303 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2) + -0.343749 *lens_ipow(y, 2)*lens_ipow(dx, 4) + -0.0334741 *x*lens_ipow(y, 2)*lens_ipow(dx, 3) + -1.9474e-07 *lens_ipow(x, 4)*lens_ipow(y, 2) + -4.17786e-06 *lens_ipow(x, 4)*y*dy + -2.23623e-05 *lens_ipow(x, 6)*lens_ipow(dy, 4)+0.0f;
const float dx12 =  + -3.67454 *y*dx + -5.3588 *x*dy + -0.0680939 *x*y + -294.771 *dx*dy + -9.99048e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*dy + -8.35568e-06 *lens_ipow(x, 3)*lens_ipow(y, 3) + -0.000868689 *lens_ipow(x, 2)*lens_ipow(y, 3)*dx + -0.458333 *lens_ipow(y, 3)*lens_ipow(dx, 3) + -0.0334741 *x*lens_ipow(y, 3)*lens_ipow(dx, 2)+0.0f;
const float dx13 =  + 35.9657  + 5.4834 *lambda + -0.029353 *lens_ipow(y, 2) + -5.40617 *y*dy + -5.3588 *x*dx + -147.386 *lens_ipow(dx, 2) + -3.69976 *lens_ipow(lambda, 2) + -0.0530305 *lens_ipow(x, 2) + -245.307 *lens_ipow(dy, 2) + -0.000301658 *lens_ipow(y, 4) + -2.02801 *lens_ipow(y, 2)*lens_ipow(dy, 2) + -0.0435895 *lens_ipow(y, 3)*dy + -9.99048e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx + -2.08893e-06 *lens_ipow(x, 4)*lens_ipow(y, 2) + -8.94494e-05 *lens_ipow(x, 6)*y*lens_ipow(dy, 3)+0.0f;
const float dx14 =  + 5.4834 *dy + 0.0864972 *y + -0.117979 *y*lambda + -7.39953 *dy*lambda+0.0f;
const float dx20 =  + -0.0049494  + 0.000713546 *lambda + -0.00409311 *y*dy + -0.00870289 *x*dx + -5.40863e-05 *lens_ipow(y, 2) + -0.00019839 *lens_ipow(x, 2) + -0.0387079 *lens_ipow(dy, 2) + 8.99062e-05 *lens_ipow(x, 2)*lambda + -0.177389 *lens_ipow(dx, 2)*lens_ipow(lambda, 2) + -3.10733e-05 *lens_ipow(x, 2)*y*dy + -0.00123791 *x*y*dx*dy + 2.22491 *x*lens_ipow(dx, 3)*lambda + 42.4326 *lens_ipow(dx, 4)*lambda + 0.0331731 *lens_ipow(x, 2)*lens_ipow(dx, 2)*lambda + -2.31683e-06 *lens_ipow(x, 4)*lambda + -3.6099e-07 *lens_ipow(x, 2)*lens_ipow(y, 3)*dy*lambda + -3.59215e-06 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx*lens_ipow(lambda, 2) + -1.85648e-08 *lens_ipow(y, 6)*lens_ipow(dx, 2) + -4.46443e-08 *lens_ipow(x, 4)*lens_ipow(y, 2)*lens_ipow(lambda, 2) + -5.48935e-11 *lens_ipow(x, 2)*lens_ipow(y, 6) + -6.71595e-05 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(lambda, 2) + -2.29462e-09 *x*lens_ipow(y, 6)*dx+0.0f;
const float dx21 =  + -0.145925 *dx*dy + -0.00409311 *x*dy + -0.000108173 *x*y + -0.00394092 *y*dx + -1.03578e-05 *lens_ipow(x, 3)*dy + -0.000618955 *lens_ipow(x, 2)*dx*dy + -3.6099e-07 *lens_ipow(x, 3)*lens_ipow(y, 2)*dy*lambda + -1.79607e-06 *lens_ipow(x, 4)*y*dx*lens_ipow(lambda, 2) + -1.11389e-07 *x*lens_ipow(y, 5)*lens_ipow(dx, 2) + -1.78577e-08 *lens_ipow(x, 5)*y*lens_ipow(lambda, 2) + -1.09787e-10 *lens_ipow(x, 3)*lens_ipow(y, 5) + -4.4773e-05 *lens_ipow(x, 3)*y*lens_ipow(dx, 2)*lens_ipow(lambda, 2) + -6.88387e-09 *lens_ipow(x, 2)*lens_ipow(y, 5)*dx+0.0f;
const float dx22 =  + 0.786396  + -0.145925 *y*dy + -0.00435144 *lens_ipow(x, 2) + 10.9599 *lens_ipow(dx, 2) + -0.00197046 *lens_ipow(y, 2) + -17.0174 *lens_ipow(dx, 2)*lens_ipow(lambda, 2) + -0.354777 *x*dx*lens_ipow(lambda, 2) + -0.000618955 *lens_ipow(x, 2)*y*dy + 2885.39 *lens_ipow(dx, 4)*lambda + 3.33736 *lens_ipow(x, 2)*lens_ipow(dx, 2)*lambda + 169.73 *x*lens_ipow(dx, 3)*lambda + 0.0221154 *lens_ipow(x, 3)*dx*lambda + -8.98036e-07 *lens_ipow(x, 4)*lens_ipow(y, 2)*lens_ipow(lambda, 2) + -3.71295e-08 *x*lens_ipow(y, 6)*dx + -4.4773e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx*lens_ipow(lambda, 2) + -1.14731e-09 *lens_ipow(x, 2)*lens_ipow(y, 6)+0.0f;
const float dx23 =  + -0.145925 *y*dx + -0.00409311 *x*y + -0.0774157 *x*dy + -1.03578e-05 *lens_ipow(x, 3)*y + -0.000618955 *lens_ipow(x, 2)*y*dx + -1.2033e-07 *lens_ipow(x, 3)*lens_ipow(y, 3)*lambda+0.0f;
const float dx24 =  + 0.000713546 *x + 2.99687e-05 *lens_ipow(x, 3) + -11.345 *lens_ipow(dx, 3)*lambda + -0.354777 *x*lens_ipow(dx, 2)*lambda + 577.077 *lens_ipow(dx, 5) + 1.11245 *lens_ipow(x, 2)*lens_ipow(dx, 3) + 42.4326 *x*lens_ipow(dx, 4) + 0.0110577 *lens_ipow(x, 3)*lens_ipow(dx, 2) + -4.63366e-07 *lens_ipow(x, 5) + -1.2033e-07 *lens_ipow(x, 3)*lens_ipow(y, 3)*dy + -1.79607e-06 *lens_ipow(x, 4)*lens_ipow(y, 2)*dx*lambda + -1.78577e-08 *lens_ipow(x, 5)*lens_ipow(y, 2)*lambda + -4.4773e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*lens_ipow(dx, 2)*lambda+0.0f;
const float dx30 =  + -0.0247564 *dx*dy + -0.00488897 *y*dx + -0.000129721 *x*y + -0.00261302 *x*dy + 0.0455703 *y*lens_ipow(dx, 3) + 0.000946643 *x*y*lens_ipow(dx, 2) + -0.00018717 *lens_ipow(x, 2)*lens_ipow(y, 2)*dx*dy + -2.10377e-06 *lens_ipow(x, 2)*lens_ipow(y, 3)*dx + -3.06164e-05 *x*lens_ipow(y, 3)*lens_ipow(dx, 2) + -0.00260115 *x*lens_ipow(y, 2)*lens_ipow(dx, 2)*dy + -3.15056e-08 *lens_ipow(x, 3)*lens_ipow(y, 3) + -2.95059e-06 *lens_ipow(x, 3)*lens_ipow(y, 2)*dy + -7.0484e-07 *lens_ipow(x, 5)*y*lens_ipow(dy, 2) + -3.17178e-05 *lens_ipow(x, 4)*y*dx*lens_ipow(dy, 2)+0.0f;
const float dx31 =  + -0.0238319  + 0.00476919 *lambda + -0.0931587 *lens_ipow(dx, 2) + -0.00608023 *y*dy + -0.132561 *lens_ipow(dy, 2) + -0.00488897 *x*dx + -0.00330426 *lens_ipow(lambda, 2) + -6.48607e-05 *lens_ipow(x, 2) + -8.24758e-05 *lens_ipow(y, 2) + 1.05773 *lens_ipow(dx, 4) + -0.000200024 *lens_ipow(y, 3)*dy + 0.0455703 *x*lens_ipow(dx, 3) + -0.284441 *y*lens_ipow(dy, 3) + 0.000473322 *lens_ipow(x, 2)*lens_ipow(dx, 2) + -1.17081e-06 *lens_ipow(y, 4) + -0.0123489 *lens_ipow(y, 2)*lens_ipow(dy, 2) + -0.00012478 *lens_ipow(x, 3)*y*dx*dy + -2.10377e-06 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx + -4.59246e-05 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2) + -0.00260115 *lens_ipow(x, 2)*y*lens_ipow(dx, 2)*dy + -2.36292e-08 *lens_ipow(x, 4)*lens_ipow(y, 2) + -1.4753e-06 *lens_ipow(x, 4)*y*dy + -1.17473e-07 *lens_ipow(x, 6)*lens_ipow(dy, 2) + -6.34355e-06 *lens_ipow(x, 5)*dx*lens_ipow(dy, 2)+0.0f;
const float dx32 =  + -0.186317 *y*dx + -0.0247564 *x*dy + -0.00488897 *x*y + 4.05182 *dx*dy + 4.23093 *y*lens_ipow(dx, 3) + 0.136711 *x*y*lens_ipow(dx, 2) + 0.000946643 *lens_ipow(x, 2)*y*dx + -6.23901e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*dy + -7.01257e-07 *lens_ipow(x, 3)*lens_ipow(y, 3) + -3.06164e-05 *lens_ipow(x, 2)*lens_ipow(y, 3)*dx + -0.00260115 *lens_ipow(x, 2)*lens_ipow(y, 2)*dx*dy + -6.34355e-06 *lens_ipow(x, 5)*y*lens_ipow(dy, 2)+0.0f;
const float dx33 =  + 0.279203  + -0.00304012 *lens_ipow(y, 2) + -0.265121 *y*dy + -0.0247564 *x*dx + 2.02591 *lens_ipow(dx, 2) + -0.00130651 *lens_ipow(x, 2) + -5.00059e-05 *lens_ipow(y, 4) + -0.426662 *lens_ipow(y, 2)*lens_ipow(dy, 2) + -0.00823257 *lens_ipow(y, 3)*dy + -6.23901e-05 *lens_ipow(x, 3)*lens_ipow(y, 2)*dx + -0.00130057 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dx, 2) + -7.37648e-07 *lens_ipow(x, 4)*lens_ipow(y, 2) + -2.34947e-07 *lens_ipow(x, 6)*y*dy + -1.26871e-05 *lens_ipow(x, 5)*y*dx*dy+0.0f;
const float dx34 =  + 0.00476919 *y + -0.00660852 *y*lambda+0.0f;
const float dx40 =  + -3.01263 *lens_ipow(dx, 3) + -0.000345135 *x*y*dy + -0.154562 *x*lens_ipow(dx, 2) + -0.00264049 *lens_ipow(x, 2)*dx + -1.51211e-05 *lens_ipow(x, 3) + -0.020405 *y*dx*dy + -1.12855e-06 *lens_ipow(y, 4)*dx + -1.95885e-08 *x*lens_ipow(y, 4) + -2.6258 *x*lens_ipow(dy, 4) + -158.195 *dx*lens_ipow(dy, 4) + -1.10695 *lens_ipow(y, 3)*dx*lens_ipow(dy, 5) + -0.0172548 *x*lens_ipow(y, 3)*lens_ipow(dy, 5)+0.0f;
const float dx41 =  + -2.62456e-05 *y + -0.421852 *lens_ipow(dy, 3) + -0.000172567 *lens_ipow(x, 2)*dy + -0.60686 *lens_ipow(dx, 2)*dy + -0.00870573 *y*lens_ipow(dy, 2) + -0.020405 *x*dx*dy + -0.00011157 *lens_ipow(y, 2)*dy + -4.51419e-06 *x*lens_ipow(y, 3)*dx + -3.91769e-08 *lens_ipow(x, 2)*lens_ipow(y, 3) + 0.00523821 *lens_ipow(y, 2)*lens_ipow(dy, 3) + -0.000131245 *lens_ipow(y, 3)*lens_ipow(dx, 2) + -102.198 *lens_ipow(y, 2)*lens_ipow(dx, 2)*lens_ipow(dy, 5) + -3.32085 *x*lens_ipow(y, 2)*dx*lens_ipow(dy, 5) + -0.0258823 *lens_ipow(x, 2)*lens_ipow(y, 2)*lens_ipow(dy, 5)+0.0f;
const float dx42 =  + -175.427 *lens_ipow(dx, 3) + -9.0379 *x*lens_ipow(dx, 2) + -0.154562 *lens_ipow(x, 2)*dx + -1.21372 *y*dx*dy + -0.000880162 *lens_ipow(x, 3) + -0.020405 *x*y*dy + -1.12855e-06 *x*lens_ipow(y, 4) + -9463.1 *dx*lens_ipow(dy, 4) + -6.56226e-05 *lens_ipow(y, 4)*dx + -158.195 *x*lens_ipow(dy, 4) + -68.1321 *lens_ipow(y, 3)*dx*lens_ipow(dy, 5) + -1.10695 *x*lens_ipow(y, 3)*lens_ipow(dy, 5)+0.0f;
const float dx43 =  + -0.177879 *dy + -1.26556 *y*lens_ipow(dy, 2) + -0.000172567 *lens_ipow(x, 2)*y + -0.60686 *y*lens_ipow(dx, 2) + -0.00870573 *lens_ipow(y, 2)*dy + -0.020405 *x*y*dx + -3.71899e-05 *lens_ipow(y, 3) + -18926.2 *lens_ipow(dx, 2)*lens_ipow(dy, 3) + 0.00523821 *lens_ipow(y, 3)*lens_ipow(dy, 2) + -5.2516 *lens_ipow(x, 2)*lens_ipow(dy, 3) + -632.781 *x*dx*lens_ipow(dy, 3) + -170.33 *lens_ipow(y, 3)*lens_ipow(dx, 2)*lens_ipow(dy, 4) + -5.53475 *x*lens_ipow(y, 3)*dx*lens_ipow(dy, 4) + -0.0431371 *lens_ipow(x, 2)*lens_ipow(y, 3)*lens_ipow(dy, 4)+0.0f;
const float dx44 =  + 1.21434  + -5.07442 *lambda + 7.48728 *lens_ipow(lambda, 2) + -3.80916 *lens_ipow(lambda, 3)+0.0f;
} break;