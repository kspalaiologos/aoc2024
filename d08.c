#include"a.h"
#define P 50
C g[P][P], na[256], t1[P][P], t2[P][P]; I s1, s2;
v2C a[256][12];
M(Fp f = fget("d08.txt"); C c, * p; v2I X, Y, d;
  CHARGRIDF(P, f, g, I((c = g[i][j]) != '.', a[c][na[c]++] = (v2C) { i, j }))
  Fx(256, F2d(na[x], X = VC(v2I, a[x][i]), Y = VC(v2I, a[x][j]);
    I(Vor(X != Y), I i = 0; t2[V2I(X)] = 1; d = 2 * Y - X;
      W(CR0(d[0],P) && CR0(d[1],P), I(!i++, t1[V2I(d)] = 1)
        t2[V2I(d)] = 1; d += Y - X))))
  F2d(P, s1 += t1[i][j], s2 += t2[i][j]) resi(s1, s2))