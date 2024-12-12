#include"a.h"
#define P 1000
I n[2][P], p2, h[P*P]; M(Fp f = fget("d01.txt");
  Fi(P, scani(f, &n[0][i]), scani(f, &n[1][i]), h[n[1][i]]++)
  p2 = Fisum(P, 0, n[0][i] * h[n[0][i]]);
  hsort(n[0],P, a,b,a<b) hsort(n[1],P, a,b,a<b)
  resi(Fisum(P, 0, abs(n[0][i] - n[1][i])), p2))