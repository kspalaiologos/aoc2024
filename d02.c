#include"a.h"
I main(V){
  FILE * f = fget("d02.txt", "r");
  I z = 0, n, d, t1 = 0, t2 = 0, c;
  C l[64], * p; I in[1000][16], x[16];
  W(fgets(l, 64, f)) {
    F$((n = 0, p = l), *p, p++,
      F$(d = 0, isdigit(*p), d = d * 10 + *p++ - '0');
      in[z][n++] = d) in[z++][n] = -1;}
  Fi(z, Fj(15,
    F$((c = 0, d = 0), in[i][c] != -1, c++,
      I(c != j - 1, x[d++] = in[i][c]));
    #define D(f, n) f(x[n] - x[n - 1])
    F$((x[d] = -1, d = D(sgn, 1), n = 1), x[n] != -1, n++,
      d = d == D(sgn, n) ? d : 0);
    I(!d, continue)
    F$((c = 1, n = 1), x[n] != -1, n++,
      d = D(abs, n), c = c && d >= 1 && d <= 3);
    I(c, I(j == 0, t1++) E(t2++; break))))
  printf("T1: %d, T2: %d\n", t1, t2);
}