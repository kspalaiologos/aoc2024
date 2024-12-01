#include"a.h"
#define P 1000
I main(V){
  FILE * f = fget("d01a.txt", "r");
  L n[2][P], s = 0, sim = 0, a;
  Fi(P, scanl(f, &n[0][i]) && scanl(f, &n[1][i]));
  struct { L k, v; } h[P]; Fi(P, h[i].k = -1, h[i].v = 0);
  Fi(P,
    F$(a=n[1][i]%P,h[a].k!=-1&&h[a].k!=n[1][i],a=(a+1)%P)
    h[a].k = n[1][i], h[a].v++)
  Fi(P,
    F$(a=n[0][i]%P,h[a].k!=-1&&h[a].k!=n[0][i],a=(a+1)%P)
    I(h[a].v, sim += n[0][i] * h[a].v))
  isort(n[0], P, y < x); isort(n[1], P, y < x);
  Fi(P, s += labs(n[0][i] - n[1][i]));
  printf("T1: %ld, T2: %ld\n", s, sim);
}
