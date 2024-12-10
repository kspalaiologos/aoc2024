#include "a.h"
#define P 60
I d, p1, p2; C g[P][P];
#define DL(a...) \
  Fi(4, I nr = r + dir4cw[i][0], nc = c + dir4cw[i][1]; \
    I(CR0(nr, d) && CR0(nc, d), I(g[nr][nc] == h + 1 && !v[nr][nc], a)))
V bfs(I r, I c){
  C r9[P][P], v[P][P], q[P][2]; ZM(r9); ZM(v); ZM(q);
  I qh = 0, qt = 0, h; v[q[qt][0] = r][q[qt][1] = c] = 1; qt++;
  W(qh < qt,
    r = q[qh][0], c = q[qh++][1], h = g[r][c]; I(h == 9, r9[r][c] = 1)
    DL(v[nr][nc] = 1; q[qt][0] = nr; q[qt++][1] = nc))
  p1 += F2dsum(P, 0, r9[i][j]);}
V dfs(I r, I c, C v[P][P]){
  I h = g[r][c]; I(h == 9, p2++; R) v[r][c] = 1;
  DL(C nv[P][P]; CM(nv, v); dfs(nr, nc, nv))}
M(Fp f = fget("d10.txt", "r"); C v[P][P]; W(fgets(g[d], P, f), d++);
  F2d(d, g[i][j] -= '0') F2d(d, I(!g[i][j], ZM(v); bfs(i, j), dfs(i, j, v)))
  resi(p1, p2))
