#include"a.h" // 5212 1767
C g[140][140], v[140][140], v2[140][140], d;
I n, p1, p2, cx, cy, l[140], ox, oy;
I s(){
  I pcx = cx + dir4cw[d][0], pcy = cy + dir4cw[d][1];
  I(CR0(pcx,n) && CR0(pcy,l[pcx]),
    I(g[pcx][pcy] == '#', d = (d + 1) % 4)
    E(I(v[pcx][pcy] == d + 1, p2++; R 0)
      E(v[cx = pcx][cy = pcy] = d + 1)) R 1) E(R 0) }
V a()_(cx = ox, cy = oy; ZM(v); v[cx][cy]++; d = 0; W(s()))
M(Fp f = fget("d06.txt"); W(fgets(g[n], 140, f), l[n] = strlen(g[n]) - 1, n++)
  F2d(140, I(g[i][j] == '^', ox = i, oy = j))
  a(); CM(v2, v); p1 = F2dsum(140, 0, v[i][j] != 0);
  F2d(140, I(g[i][j] == '.' && v2[i][j], g[i][j] = '#'; a(); g[i][j] = '.'))
  resi(p1, p2))