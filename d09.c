#include "a.h" // 6344673854800 6360363199987
#define P 19999
V p2(T * e, I sz)_(Fid(sz, I(e[i] != -1 && i, I n = e[i], need = 1, has;
  W (e[--i] == n && i, need++); Fj(i, I(e[j] == -1,
    F$(has = 1, e[++j] == -1, has++) I(need <= has,
      F$(j -= has + 1, need--, e[i] = -1, e[++j] = e[++i]) B))) i++)))
V p1(T * e, I sz)_(I j = sz - 1; Fi(j, I(e[i] == -1,
  W(e[j] == -1, j--) SWAP(e[i], e[j]) j--)))
M(C * c = slurp("d09.txt"); I ns = Fisum(P, 0, c[i] - '0');
  T e[2][P*5]; I j = 0, k = 0; L s[2];
  Fi(P, Fx(c[i] - '0', e[0][k] = j; k++)
    I(++i < P, Fx(c[i] - '0', e[0][k] = -1; k++) j++))
  CM(e[1], e[0]); p1(e[0], ns); p2(e[1], ns);
  Fx(2, s[x] = Fisum(ns, 0l, MAX(i * e[x][i], 0))) resl(s[0], s[1]))
