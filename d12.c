#include"a.h"
#define P 140
#define Fs(a,b) \
  !Fany(j,0,s, k1[j] == y - a && k2[j] == z - b && k3[j] == x)
C a[P][P], v[P][P]; I p1, p2; M(T q[P*2][2]; Fp f = fget("d12.txt");
  CHARGRIDF(P, f, a); I k1[2*P], k2[2*P], k3[2*P];
  I p, s, ui, uj; F2d(P, I(!v[i][j], QINIT(); p = s = 0;
    QPUSH2(i,j); v[i][j] = 1; WQ(QPOP2(ui,uj); Fx(4,
      I y = ui + dir4cw[x][0], z = uj + dir4cw[x][1];
      I(!CR0(y,P) || !CR0(z,P) || a[y][z] != a[ui][uj], p++;
        I(Fs(0,0), k1[s] = y, k2[s] = z, k3[s++] = x))
      J(!v[y][z], v[y][z] = 1; QPUSH2(y,z))))
    p2 += qh * Fisum(s,0, I y = k1[i], z = k2[i], x = k3[i];
      x % 2 ? Fs(1,0) : Fs(0,1)); p1 += qh * p)) resi(p1, p2))