#include"a.h"
#define P 100
I r0[1200], r1[1200], nr, u[999][P], nu[999], g[P][2*P], ui;
I uidx(I v)_(Fj(nu[ui], I(u[ui][j] == v, R j)) -1)
I uhas(I v)_(uidx(r0[v]) != -1 && uidx(r1[v]) != -1)
I ru(V)_(
  I ng[P], id[P], pr[P], t[P], ti = 0, q[P], qh = 0, qt = 0, n;
  Fi(P, id[i] = ng[i] = pr[i] = 0)
  Fi(nr, I(uhas(i),
    pr[r0[i]] = pr[r1[i]] = 1; id[g[r0[i]][ng[r0[i]]++] = r1[i]]++))
  Fi(P, I(!id[i] && pr[i], q[qt++] = i))
  W(qh < qt, t[ti++] = n = q[qh++];
    Fj(ng[n], I(!--id[g[n][j]], q[qt++] = g[n][j]))) t[ti / 2])
M(C * p = slurp("d05.txt");
  I i = 0, j = 0, t1 = 0, t2 = 0;
  #define D (p[i++] - '0') * 10 + (p[i++] - '0'), i++
  W(p[i] != '\n', r0[nr] = D; r1[nr] = D; nr++) i++;
  W(p[i], u[j][nu[j]++] = D; I(p[i-1] == '\n', j++))
  Fi(j, ui = i; I(Fany(i, 0, nr, uhas(i) && uidx(r0[i]) >= uidx(r1[i])),
    t2 += ru()) E(t1 += u[i][nu[i] / 2])) resi(t1, t2))