#include"a.h"
#define P 1000
V sort(L * a, I n) {
  Fi(n, F_(j, i + 1, n, I(a[i] <= a[j], SWAP(a[i], a[j]))))
}
I main(V){
  FILE * f = fget("d01a.txt", "r");
  L n[2][P], s = 0, sim = 0;
  Fi(P, scanl(f, &n[0][i]) && scanl(f, &n[1][i]));
  struct { L k, v; } h[P]; Fi(P, h[i].k = -1, h[i].v = 0);
  Fi(P,
    L a = n[1][i] % P;
    W(h[a].k != -1 && h[a].k != n[1][i])
      a = (a + 1) % P;
    h[a].k = n[1][i], h[a].v++)
  Fi(P,
    L x = n[0][i], v, a = x % P;
    W(h[a].k != -1 && h[a].k != x)
      a = (a + 1) % P;
    I(v = h[a].v, sim += x * v))
  sort(n[0], P); sort(n[1], P);
  Fi(P, s += labs(n[0][i] - n[1][i]));
  printf("T1: %ld, T2: %ld\n", s, sim);
}