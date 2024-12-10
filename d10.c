#include "a.h" // 646 1494
#define P 60
I d, p1, p2; C g[P][P], r9[P][P], v[P][P];
V f(I r, I c){
  I h = g[r][c], nc, nr; I(h == 9, p2++; r9[r][c] = 1; R) v[r][c] = 1;
  Fi(4, I(CR0((nr = r + dir4cw[i][0]), d) && CR0((nc = c + dir4cw[i][1]), d)
    && g[nr][nc] == h + 1 && !v[nr][nc], f(nr, nc))) v[r][c] = 0;}
M(Fp h = fget("d10.txt"); W(fgets(g[d], P, h), d++); F2d(d, g[i][j] -= '0')
  F2d(d, I(!g[i][j], ZM(r9); f(i, j); F2d(P,0, p1 += r9[i][j]))) resi(p1, p2))
