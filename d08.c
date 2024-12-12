#include"a.h"
#define P 50
C g[P][P], na[256], a[256][12][2], t1[P][P], t2[P][P]; I s1, s2;
M(Fp f = fget("d08.txt"); C c, * p, * X, * Y;
  CHARGRIDF(P, f, g, I((c = g[i][j]) != '.',
    p = a[c][na[c]++]; p[0] = i; p[1] = j))
  Fx(256, F2d(na[x], I(memcmp(X = a[x][i], Y = a[x][j], 2),
    I d[2], i = 0; t2[X[0]][X[1]] = 1; Fy(2, d[y] = 2 * Y[y] - X[y]);
    W(CR0(d[0],P) && CR0(d[1],P), I(!i++, t1[d[0]][d[1]] = 1)
      t2[d[0]][d[1]] = 1; Fy(2, d[y] += Y[y] - X[y])))))
  F2d(P, s1 += t1[i][j], s2 += t2[i][j]) resi(s1, s2))