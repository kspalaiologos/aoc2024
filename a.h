
#ifndef _A_H
#define _A_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <regex.h>

typedef int I;
typedef short T;
typedef long L;
typedef FILE * Fp;
typedef void V;
typedef char C;
typedef double D;
typedef regex_t Re;
typedef regmatch_t Rm;
#define S static
#define SI static int
#define SV static void
#define SC static char
#define R return
#define _(a...) {return({a;});}
#define Fi(n,a...) for(typeof(n) i=0;i<n;i++){a;}
#define Fj(n,a...) for(typeof(n) j=0;j<n;j++){a;}
#define Fx(n,a...) for(typeof(n) x=0;x<n;x++){a;}
#define Fy(n,a...) for(typeof(n) y=0;y<n;y++){a;}
#define F_(z,i,n,a...) for(typeof(n) z=i;z<n;z++){a;}
#define F$(x,y,z,a...) for(x;y;z){a;}
#define I(x,a...) if(x){a;}
#define J(a...) else I(a)
#define E(a...) else{a;}
#define W(c,a...) while(c){a;}
#define SWAP(a,b) { typeof(a) _t = a; a = b; b = _t; }
#define hsort(x, n, cmp) { \
  L _n = n, _i = _n / 2, _p, _c; \
  F$ (typeof(x[0]) t,,x[_p] = t, \
    I (_i > 0, t = x[--_i]) \
    J (--_n == 0, break) \
    E (t = x[_n], x[_n] = x[0]) \
    _p = _i;  _c = _i * 2 + 1; \
    W (_c < _n, \
      I (_c + 1 < _n && \
        ({ typeof(x[0]) a = x[_c + 1], b = x[_c]; cmp; }), _c++) \
      I (({ typeof(x[0]) a = x[_c], b = t; cmp; }), \
        x[_p] = x[_c]; _p = _c; _c = _p * 2 + 1; \
      ) E(break)))}
#define M(a...) I main(V){a;}

S FILE * fget(C * n, C * m) {
  FILE * f = fopen(n, m);
  I(!f, perror("fopen"); exit(1)); R f; }
S I scani(FILE * f, I * l)_(fscanf(f, "%d", l) != EOF)
S I scanl(FILE * f, L * l)_(fscanf(f, "%ld", l) != EOF)
S C * slurp(C * n) {
  FILE * f = fget(n, "r");
  fseek(f, 0, SEEK_END);
  L s = ftell(f);
  rewind(f);
  C * d = malloc(s + 1);
  fread(d, 1, s, f);
  d[s] = 0; R d; }
S V resi(I t1, I t2) { printf("T1: %d, T2: %d\n", t1, t2); }

S I dir[8][2] = {
  {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

#define sgn(x) ((x > 0) - (x < 0))

#endif

