#include"a.h"
#define P 1000
I main(V){
  FILE * f = fget("d01.txt", "r");
  I n[2][P], p1 = 0, p2 = 0, a;
  Fi(P, scani(f, &n[0][i]) && scani(f, &n[1][i]))
  struct { I k, v; } h[P]; Fi(P, h[i].k = -1, h[i].v = 0)
  Fi(P,
    F$(a=n[1][i]%P,h[a].k!=-1&&h[a].k!=n[1][i],a=(a+1)%P)
    h[a].k = n[1][i], h[a].v++)
  Fi(P,
    F$(a=n[0][i]%P,h[a].k!=-1&&h[a].k!=n[0][i],a=(a+1)%P)
    I(h[a].v, p2 += n[0][i] * h[a].v))
  isort(n[0], P, y < x) isort(n[1], P, y < x)
  Fi(P, p1 += abs(n[0][i] - n[1][i]))
  printf("T1: %d, T2: %d\n", p1, p2);}
