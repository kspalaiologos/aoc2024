#include"a.h"
L eq[850][16], t[2], v, i, j;
L conc(L a, L b)_(L m = 1; W(m <= b, m *= 10); a * m + b)
#define FR(f,x...) I f(L a, L * n)_(I(!*n, R a == v) \
  f(a + *n, n + 1) || f(a * *n, n + 1) x)
FR(f1,) FR(f2, || f2(conc(a, *n), n + 1))
#define fn(g, a, n, t) v = g, t ? f2(a, n) : f1(a, n)
M(Fp f = fget("d07.txt"); LINESF(256, f, eq[i][0] = strtol(p, &p, 10); p += 2;
    W(*p, eq[i][++j] = strtol(p, &p, 10); p++) i++, j = 0)
  Fi(850, L * e = eq[i]; Fx(2, I(fn(e[0], e[1], &e[2], x), t[x] += e[0])))
  resl(t[0], t[1]))