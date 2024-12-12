#include"a.h" // 5212 1767
#define P 130
C g[P][P], v[P][P], v2[P][P], d;
I p1, p2, cx, cy, ox, oy, pcx, pcy;
I s(){
  I(CR0((pcx = cx + dir4cw[d][0]),P) && CR0((pcy = cy + dir4cw[d][1]),P),
    I(g[pcx][pcy] == '#', d = (d + 1) % 4)
    E(I(v[pcx][pcy] == d + 1, p2++; R 0)
      E(v[cx = pcx][cy = pcy] = d + 1)) R 1) E(R 0) }
V a()_(cx = ox, cy = oy; ZM(v); v[cx][cy]++; d = 0; W(s()))
M(Fp f = fget("d06.txt"); CHARGRIDF(P, f, g);
  F2d(P, I(g[i][j] == '^', ox = i, oy = j))
  a(); CM(v2, v); p1 = F2dsum(P, 0, v[i][j] != 0);
  F2d(P, I(g[i][j] == '.' && v2[i][j], g[i][j] = '#'; a(); g[i][j] = '.'))
  resi(p1, p2))