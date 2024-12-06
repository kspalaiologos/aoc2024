#include"a.h" // 479 531
M(Fp f = fget("d02.txt", "r");
  I z = 0, n, d, t1 = 0, t2 = 0, c;
  C l[64], * p; I in[1000][16], x[16], xl[1000];
  W(p = fgets(l, 64, f),
    F$(n = 0, *p, p++, in[z][n++] = strtol(p, &p, 10))
    xl[z++] = n)
  Fi(z, Fj(15, c = -1;
    #define D(f, n) f(x[n] - x[n - 1])
    Fy(xl[i], I(y != j - 1, x[++c] = in[i][y]))
    d = D(sgn, 1);
    Fy(c, d = d == D(sgn, y + 1) ? d : 0)
    Fy(c, d = d && C3(1,<=,D(abs, y + 1),<=,3))
    I(d, I(!j, t1++) E(t2++; break))))
  resi(t1, t2))