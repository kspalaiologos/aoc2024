#include"a.h"
I r[2][1200], nr, u[999][99], nu[999], g[100][200], ng[100], id[100];
I uidx(I ui, I v)_(Fj(nu[ui], I (u[ui][j] == v, R j)); -1)
I uv(I ui)_(
  I i0, i1; Fi(nr, I(
    (i0 = uidx(ui, r[0][i])) != -1 && (i1 = uidx(ui, r[1][i])) != -1 && i0 >= i1,
      R 0)) 1)
I ru(I ui)_(
  Fi(100, ng[i] = 0, id[i] = -1)
  Fi(nr,
    I a = r[0][i], b = r[1][i];
    I(uidx(ui, a) != -1 && uidx(ui, b) != -1,
      g[a][ng[a]++] = b; id[a] = MAX(id[a], 0); id[b] = MAX(id[b]+1, 1)))
  I t[100], ti = 0, q[100], qh = 0, qt = 0, n;
  Fi(100, I(!id[i], q[qt++] = i))
  W(qh < qt,
    t[ti++] = n = q[qh++];
    Fj(ng[n], I(!--id[g[n][j]], q[qt++] = g[n][j])))
  t[ti / 2])
M(C * p = slurp("d05.txt");
  I i = 0, j = 0, a, b, t1 = 0, t2 = 0;
  #define D (p[i++] - '0')
  W(p[i] != '\n', r[0][nr] = D * 10 + D; i++; r[1][nr] = D * 10 + D; i++; nr++) i++;
  W(p[i], u[j][nu[j]++] = D * 10 + D; I(p[i] == '\n', j++) i++)
  Fi(j, I(uv(i), t1 += u[i][nu[i] / 2]) E(t2 += ru(i)))
  resi(t1, t2))