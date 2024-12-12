#include"a.h" // 1381056, 834828
#define P 140
#define QPUSH(x,y) q[qt][0] = x; q[qt++][1] = y
#define Fs(a,b) \
  !Fany(j,0,s, k1[j] == y - a && k2[j] == z - b && k3[j] == x)
C a[P][P], v[P][P]; I p1, p2; M(T q[P*2][2]; Fp f = fget("d12.txt");
  Fi(P, Fj(P, a[i][j] = getc(f)) getc(f)) I k1[2*P], k2[2*P], k3[2*P];
  I qh, qt, p, s; F2d(P, I(!v[i][j], qh=qt=p=s=0; QPUSH(i,j);
    v[i][j] = 1; W(qh < qt, I ui=q[qh][0],uj=q[qh++][1]; Fx(4,
      I y = ui + dir4cw[x][0], z = uj + dir4cw[x][1];
      I(!CR0(y,P)||!CR0(z,P) || a[y][z] != a[ui][uj], p++;
        I(Fs(0,0), k1[s]=y,k2[s]=z,k3[s++]=x))
      J(!v[y][z], v[y][z] = 1; QPUSH(y,z))))
    p2 += qh * Fisum(s,0, I y=k1[i],z=k2[i],x=k3[i];
      x % 2 ? Fs(1,0) : Fs(0,1)); p1 += qh * p)) resi(p1, p2))