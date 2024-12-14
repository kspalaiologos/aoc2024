#include"a.h"
I r[500][4], i, c[3][3], d[103], W = 101, H = 103; M(Fp f = fget("d14.txt");
  LINESF(99, f, W(*p, I(isnum(*p), r[i/4][i++%4] = strtol(p, &p, 10)) p++))
  Fi(500, c[SGN(REM(r[i][0] + 100 * r[i][2], W) - 50) + 1]
           [SGN(REM(r[i][1] + 100 * r[i][3], H) - 51) + 1]++)
  #define MOD_M(x, a, b) \
    Fimini(x, ~0U, ZM(d); Fj(500, d[REM(r[j][a] + i * r[j][b], x)] = 1) \
      Fisum(x, 0, d[i]))
  I t = MOD_M(W, 0, 2) * H*mod_inv(H, W) + MOD_M(H, 1, 3) * W*mod_inv(W, H);
  resi(F2dprod(2, 1, c[i * 2][j * 2]), t % (W * H)))