#include"a.h"
I r[2][1200], nr, u[999][99], nu[999], g[100][200], ng[100], id[100];
I uidx(I ui, I v)_(Fj(nu[ui], I (u[ui][j] == v, R j)); -1)
#define IX(n) (i##n = uidx(ui, r[n][i])) != -1
#define POS(x) x = MAX(x, 0)
I uv(I ui)_(I i0, i1; Fi(nr, I(IX(0) && IX(1) && i0 >= i1, R 0)) 1)
I ru(I ui)_(
  Fi(100, ng[i] = 0, id[i] = -1)
  Fi(nr,
    I a = r[0][i], b = r[1][i], i0, i1;
    I(IX(0) && IX(1), POS(id[a]); POS(id[b]); id[g[a][ng[a]++] = b]++))
  I t[100], ti = 0, q[100], qh = 0, qt = 0, n; Fi(100, I(!id[i], q[qt++] = i))
  W(qh < qt, t[ti++] = n = q[qh++]; Fj(ng[n], I(!--id[g[n][j]], q[qt++] = g[n][j])))
  t[ti / 2])
M(C * p = slurp("d05.txt");
  I i = 0, j = 0, a, b, t1 = 0, t2 = 0;
  #define D (p[i++] - '0') * 10 + (p[i++] - '0'), i++
  W(p[i] != '\n', r[0][nr] = D; r[1][nr] = D; nr++) i++;
  W(p[i], u[j][nu[j]++] = D; I(p[i-1] == '\n', j++))
  Fi(j, I(uv(i), t1 += u[i][nu[i] / 2]) E(t2 += ru(i)))
  resi(t1, t2))