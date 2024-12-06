#include"a.h" // 1603498 25574739
#define P 1000
M(Fp f = fget("d01.txt", "r");
  I n[2][P], p1 = 0, p2 = 0, h[P*P] = { 0 };
  Fi(P, scani(f, &n[0][i]), scani(f, &n[1][i]), h[n[1][i]]++)
  Fi(P, p2 += n[0][i] * h[n[0][i]])
  hsort(n[0],P, a,b,a<b) hsort(n[1],P, a,b,a<b)
  Fi(P, p1 += abs(n[0][i] - n[1][i]))
  resi(p1, p2))