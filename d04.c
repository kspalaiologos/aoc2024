#include"a.h" // 2718 2046
#define P 140
M(Fp f = fget("d04.txt"); C g[P+8][P+8]; I p1 = 0, p2 = 0, k;
  Fi(P, Fj(P, g[i][j] = getc(f)) getc(f));
  F2d(P, Fx(8, k = 1; Fy(4,
    I X = i + y * dir8[x][0], Y = j + y * dir8[x][1];
    I(X < 0 || Y < 0 || g[X][Y] != "XMAS"[y], k = 0; B)) I(k, p1++)))
  F2d(P-2, Fx(4,
    C s[] = { g[i][j], g[i][j+2], g[i+1][j+1], g[i+2][j], g[i+2][j+2] };
    I(!memcmp(s, &"MSAMSSSAMMSMASMMMASS"[5*x], 5), p2++))) resi(p1, p2))