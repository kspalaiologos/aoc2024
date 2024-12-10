#include"a.h" // 1603498 25574739
#define P 1000
M(Fp f = fget("d01.txt"); I n[2][P], p2, h[P*P] = { 0 };
  Fi(P, scani(f, &n[0][i]), scani(f, &n[1][i]), h[n[1][i]]++)
  p2 = Fisum(P, 0, n[0][i] * h[n[0][i]]);
  hsort(n[0],P, a,b,a<b) hsort(n[1],P, a,b,a<b)
  resi(Fisum(P, 0, abs(n[0][i] - n[1][i])), p2))