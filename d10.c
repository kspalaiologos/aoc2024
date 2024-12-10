#include "a.h"
#define P 60
I d, p1, p2; C g[P][P], r9[P][P];
V f(I r, I c, C v[P][P])_(
  I h = g[r][c], nc, nr; I(h == '9', p2++; r9[r][c] = 1; R) v[r][c] = 1;
  Fi(4, I(CR0((nr = r + dir4cw[i][0]), d) && CR0((nc = c + dir4cw[i][1]), d)
    && g[nr][nc] == h + 1 && !v[nr][nc], C p[P][P]; CM(p, v); f(nr, nc, p))))
M(Fp h = fget("d10.txt", "r"); C v[P][P]; W(fgets(g[d], P, h), d++);
  F2d(d, I(g[i][j] == '0', ZM(v); ZM(r9); f(i, j, v);
    p1 += F2dsum(P, 0, r9[i][j]))) resi(p1, p2))
