#include "a.h"
#define P 19999
V p2(I * e, I sz)_(Fid(sz, I(e[i] != -1 && i,
  I n = e[i], need = 1, has; W (e[--i] == n && i, need++);
  Fj(i, I(e[j] == -1, F$(has = 1, e[++j] == -1, has++)
    I(need <= has,
      F$ (j -= has + 1, need--, e[i] = -1, e[++j] = e[++i]) B))) i++)))
V p1(I * e, I sz)_(I j = sz - 1; Fi(j, I(e[i] == -1,
  W(e[j] == -1, j--) SWAP(e[i], e[j]) j--)))
M(C * c = slurp("d09.txt"); I ns = 0; Fi(P, ns += c[i] - '0');
  I e[2][P*10], j = 0, k = 0; L s[2] = { 0 };
  Fi(P, Fx(c[i] - '0', e[0][k] = e[1][k] = j; k++)
    I(++i < P, Fx(c[i] - '0', e[0][k] = e[1][k] = -1; k++) j++))
  p1(e[0], ns); p2(e[1], ns);
  Fx(2, Fi(ns, I(e[x][i] != -1, s[x] += i * e[x][i])))
  resl(s[0], s[1]))