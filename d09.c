#include "a.h"
#define P 20000
L sol(C * p, I part)_(
  T b[100000], fid = 0; I bs = 0;
  Fi(P - 1, Fj(p[i], b[bs++] = fid) fid++;
    I(++i < P - 1, Fj(p[i], b[bs++] = -1)))
  I(part,
    C fm[10000] = { 0 }; I fp[99], n, fb, fc;
    Fi(bs, I(b[i] > 0, fm[b[i]] = 1))
    Fid(10000, I(fm[i], n = 0, fb = -1, fc = 0;
      Fj(bs, I(b[j] == i, fp[n++] = j))
      Fi(bs,
        I(b[i] == -1, I(fb == -1, fb = i) I(++fc == n, break))
        E(fb = -1, fc = 0))
      I(fb != -1 && fb < fp[0],
        Fi(n, b[fp[i]] = -1) Fj(n, b[fb + j] = i)))))
  E(W(1, I rf = -1, lf = -1;
    Fid(bs, I(b[i] > 0, rf = i; break))
    Fi(bs, I(b[i] == -1, lf = i; break))
    I (rf == -1 || lf == -1 || lf > rf, break)
    b[lf] = b[rf]; b[rf] = -1))
  L c = 0; Fi(bs, I(b[i] > 0, c += i * b[i])) c)
M(C * p = slurp("d09.txt"); Fi(P - 1, p[i] -= '0')
  L t[2]; Fi(2, t[i] = sol(p, i)) resl(t[0], t[1]))