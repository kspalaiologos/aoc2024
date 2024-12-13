#include"a.h"
#define P 60
I d, p1, p2; C g[P][P], r9[P][P], v[P][P];
V f(v2I c){
  v2I n; I h = g[V2I(c)]; I(h == 9, p2++; r9[V2I(c)] = 1; R) v[V2I(c)] = 1;
  Fi(4, n = c + dir4cw[i]; I(CR0(n[0], d) && CR0(n[1], d)
    && g[V2I(n)] == h + 1 && !v[V2I(n)], f(n))) v[V2I(c)] = 0;}
M(Fp h = fget("d10.txt"); W(fgets(g[d], P, h), d++); F2d(d, g[i][j] -= '0')
  F2d(d, I(!g[i][j], ZM(r9); f(ij); F2d(P,0, p1 += r9[i][j]))) resi(p1, p2))
