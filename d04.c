#include"a.h"
#define P 140
M(Fp f = fget("d04.txt", "r"); C g[P+8][P+8];
  Fi(P, Fj(P, g[i][j] = getc(f)) getc(f));
  I p1 = 0, p2 = 0, k;
  Fi(P, Fj(P, Fx(8,
    k = 1; Fy(4,
      I X = i + y * dir[x][0], Y = j + y * dir[x][1];
      I(X < 0 || Y < 0 || g[X][Y] != "XMAS"[y], k = 0; break))
    I(k, p1++))))
  Fi(P-2, Fj(P-2, Fx(4,
    C s[] = { g[i][j], g[i][j+2], g[i+1][j+1], g[i+2][j], g[i+2][j+2] };
    I(!memcmp(s, &"MSAMSSSAMMSMASMMMASS"[5*x], 5), p2++))))
  resi(p1, p2))