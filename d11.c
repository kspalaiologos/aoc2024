#include"a.h"
#define MS (1<<21)
L k[MS], v[MS];
L ins(L kk, L vv)_(I i = kk % MS; W(v[i] && k[i] != kk, i = (i + 1) % MS)
  k[i] = kk; v[i] = vv)
I get(L kk, L * vv)_(I i = kk % MS, s = i; W(v[i],
  I(k[i] == kk, *vv = v[i]; R 1) i = (i + 1) % MS; I(i == s, B)) 0)
L f(L n, int b)_(
  L k = n * 80 + b, v, dl = ilog10l(n); I(get(k, &v), R v) I(b == 0, R 1)
  I(n == 0, R ins(k, f(1, b - 1))) I(dl % 2 == 0, L d = pow(10, dl / 2);
  R ins(k, f(n / d, b - 1) + f(n % d, b - 1))) ins(k, f(n * 2024, b - 1)))
M(Fp fp = fget("d11.txt"); I i[9], ni = 0; W(scani(fp, &i[ni]), ni++);
  L s1 = 0, s2 = 0; Fj(ni, s1 += f(i[j], 25), s2 += f(i[j], 75)) resl(s1, s2))
