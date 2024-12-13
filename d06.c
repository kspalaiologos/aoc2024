#include"a.h"
#define P 130
C g[P][P], v[P][P], v2[P][P], d;
I p1, p2;  v2I o, c, pc;
I s()_(pc = c + dir4cw[d]; I(CR0(pc[0], P) && CR0(pc[1], P),
  I(g[V2I(pc)] == '#', d = (d + 1) % 4)
  E(I(v[V2I(pc)] == d + 1, p2++; R 0)
    E(c = pc; v[V2I(c)] = d + 1)) R 1) 0)
V a()_(c = o; ZM(v); v[V2I(c)]++; d = 0; W(s()))
M(Fp f = fget("d06.txt"); CHARGRIDF(P, f, g);
  F2d(P, I(g[i][j] == '^', o = ij))
  a(); CM(v2, v); p1 = F2dsum(P, 0, v[i][j] != 0);
  F2d(P, I(g[i][j] == '.' && v2[i][j], g[i][j] = '#'; a(); g[i][j] = '.'))
  resi(p1, p2))