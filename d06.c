#include"a.h"
C g[140][140], v[140][140], v2[140][140], d; I n, p1, p2, cx, cy;
I s() {
  I pcx = cx + dir4cw[d][0], pcy = cy + dir4cw[d][1];
  I(0 <= pcx && pcx < n && 0 <= pcy && pcy < strlen(g[pcx]),
    I(g[pcx][pcy] == '#', d = (d + 1) % 4)
    E(I(v[pcx][pcy] == d + 1, p2++; R 0)
      E(v[cx = pcx][cy = pcy] = d + 1)) R 1) E(R 0) }
V a()_(
  Fi(140, Fj(140, I(g[i][j] == '^', cx = i, cy = j)))
  bzero(v, 19600); v[cx][cy] = 1; d = 0; W(s()))
M(Fp f = fget("d06.txt", "r");
  W(fgets(g[n], 140, f), g[n][strlen(g[n]) - 1] = 0, n++)
  a(); memcpy(v2, v, 19600); Fi(140, Fj(140, p1 += v[i][j] != 0))
  Fi(140, Fj(140, I(g[i][j] == '.' && v2[i][j], g[i][j] = '#'; a(); g[i][j] = '.')))
  resi(p1, p2))

