#include"a.h"
#define P 30
char r[2000][2], u[200][P];
#define ok Fany(z, 0, nr, u[i][j] == r[z][1] && u[i][k] == r[z][0])
#define sol ({ F$(y = 0, y < P && u[i][y], y++) u[i][y / 2]; })
M(C * p = slurp("d05.txt");
  I i = 0, n = 0, nr = 0, nu = 0, t1 = 0, t2 = 0, y, v;
  #define D (p[i++] - '0') * 10 + (p[i++] - '0'), i++
  W(p[i] != '\n', r[nr][0] = D; r[nr][1] = D; nr++) i++;
  W(p[i], u[n][nu++] = D; I(p[i-1] == '\n', n++, nu = 0))
  Fi(n, I(!Fany(j, 0, P, Fany(k, j+1, P, ok)), t1 += sol))
  Fi(n, Fj(P, F_(k, j+1, P, I(ok, SWAP(u[i][j], u[i][k]) v++)))
        I(v, t2 += sol, v = 0)) resi(t1, t2))
