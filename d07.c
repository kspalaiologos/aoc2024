#include"a.h"
L eq[850][16], t[2];
L conc(L a, L b)_(L m = 1; W (m <= b, m *= 10); a * m + b)
I fn(L v, L a, L * n, I t)_(
  #define FR(x) fn(v, x, n + 1, t)
  I (!*n, R a == v)
  FR(a + *n) || FR(a * *n) || (t && FR(conc(a, *n))))
M(Fp f = fget("d07.txt", "r"); C buf[256], * p; I i, j;
  F$((i = j = 0), p = fgets(buf, 256, f), (i++, j = 0),
    eq[i][0] = strtol(p, &p, 10); p += 2;
    W(*p, eq[i][++j] = strtol(p, &p, 10); p++))
  Fi(850, L * e = eq[i]; Fx(2, I(fn(e[0], e[1], &e[2], x), t[x] += e[0])))
  resl(t[0], t[1]))