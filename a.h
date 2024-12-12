
#ifndef _A_H
#define _A_H

// Headers
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <regex.h>

// Types
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

// Language
#define R return
#define B break
#define _(a...) {return({a;});}
#define Fi(n,a...) for(typeof(n) i=0;i<n;i++){a;}
#define Fid(n,a...) for(typeof(n) i=n-1;i>=0;i--){a;}
#define Fj(n,a...) for(typeof(n) j=0;j<n;j++){a;}
#define Fx(n,a...) for(typeof(n) x=0;x<n;x++){a;}
#define Fy(n,a...) for(typeof(n) y=0;y<n;y++){a;}
#define F2d(n,a...) Fi(n, Fj(n, a))
#define F_(z,i,n,a...) for(typeof(n) z=i;z<n;z++){a;}
#define F$(x,y,z,a...) for(x;y;z){a;}
#define I(x,a...) if(x){a;}
#define J(a...) else I(a)
#define E(a...) else{a;}
#define W(c,a...) while(c){a;}
#define C3(a,c1,b,c2,c) (a c1 b && b c2 c)
#define CR0(b,c) (0 <= b && b < c)
#define ZM(a) bzero(a, sizeof(a))
#define CM(a,b) memcpy(a,b,sizeof(a))

// Hygienic heapsort w. comparator.
#define _UNIQUE() __COUNTER__
#define _VAR(name) _JOIN(name, _UNIQUE())
#define _JOIN(a, b) _JOIN_2(a, b)
#define _JOIN_2(a, b) a ## b
#define hsort_internal(x, n, cmp, _a, _b, _n, _i, _p, _c) { \
  L _n = n, _i = _n / 2, _p, _c; \
  F$ (typeof(x[0]) t,,x[_p] = t, \
    I (_i > 0, t = x[--_i]) \
    J (--_n == 0, break) \
    E (t = x[_n], x[_n] = x[0]) \
    _p = _i;  _c = _i * 2 + 1; \
    W (_c < _n, \
      I (_c + 1 < _n && \
        ({ typeof(x[0]) _a = x[_c + 1], _b = x[_c]; cmp; }), _c++) \
      I (({ typeof(x[0]) _a = x[_c], _b = t; cmp; }), \
        x[_p] = x[_c]; _p = _c; _c = _p * 2 + 1; \
      ) E(break)))}
#define hsort(x, n, _a, _b, cmp) \
  hsort_internal(x, n, cmp, _a, _b, _VAR(__n), _VAR(__i), _VAR(__p), _VAR(__c))

// Fall: 1 if predicate holds for all elements, 0 otherwise. Short-circuits.
// Fany: 1 if predicate holds for any element, 0 otherwise. Short-circuits.
#define Fall_internal(_v,z,i,n,a...) \
  ({ I _v = 1; F_(z, i, n, I(!(a), _v = 0; B)) _v; })
#define Fall(z,i,n,a...) Fall_internal(_VAR(__v),z,i,n,a)
#define Fany_internal(_v,z,i,n,a...) \
  ({ I _v = 0; F_(z, i, n, I(a, _v = 1; B)) _v; })
#define Fany(z,i,n,a...) Fany_internal(_VAR(__v),z,i,n,a)

// Summing fold-like LTR construct.
#define Fisum(n,i,a...) ({ typeof(i) _v = i; Fi(n, _v += ({a;})); _v; })
#define Fjsum(n,j,a...) ({ typeof(j) _v = j; Fj(n, _v += ({a;})); _v; })
#define F2dsum(n,i,a...) ({ typeof(i) _v = i; F2d(n, _v += ({a;})); _v; })

// Swap
#define SWAP_internal(a,b,_t) { typeof(a) _t = a; a = b; b = _t; }
#define SWAP(a,b) SWAP_internal(a,b,_VAR(__t))

// High precision timer:
#include <emmintrin.h>
#include <time.h>
S V barrier() { asm volatile("mfence" ::: "memory"); }
#define TIC() struct timespec __tic; barrier(); clock_gettime(CLOCK_MONOTONIC, &__tic); barrier()
#define TOC() ({ struct timespec __toc; barrier(); clock_gettime(CLOCK_MONOTONIC, &__toc); barrier(); \
  (__toc.tv_sec - __tic.tv_sec) + (__toc.tv_nsec - __tic.tv_nsec) / 1e9; })

// Main
#define M(a...) I main(V){TIC();a;printf("Elapsed: %f s\n",TOC());}

// Queue
#define QPUSH2(x,y) q[qt][0] = x; q[qt++][1] = y
#define QPOP2(x,y) x = q[qh][0]; y = q[qh++][1]
#define QPUSH(x) q[qt++] = x
#define QPOP(x) x = q[qh++]
#define QINIT() I qh = 0, qt = 0
#define WQ(a...) W(qh < qt, a)

// Grid
#define CHARGRID(P,f,g,a...) Fi(P, Fj(P, g[i][j] = getc(f); a) getc(f))

// Min/max/signum
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define sgn(x) ((x > 0) - (x < 0))

// Regex stuff
#define regcomp(r, e) regcomp(&r, e, REG_EXTENDED)

// ASAN stuff
const char * __asan_default_options() { return "detect_leaks=0"; }

// Static helpers
S Fp fget(C * n) {
  Fp f = fopen(n, "r"); I(!f, perror("fopen"); exit(1)); R f; }
S I scani(FILE * f, I * l)_(fscanf(f, "%d", l) != EOF)
S I scanl(FILE * f, L * l)_(fscanf(f, "%ld", l) != EOF)
S C * slurp(C * n) {
  Fp f = fget(n);
  fseek(f, 0, SEEK_END);
  L s = ftell(f);
  rewind(f);
  C * d = malloc(s + 1);
  fread(d, 1, s, f);
  d[s] = 0; R d; }
S V resi(I t1, I t2) { printf("T1: %d, T2: %d\n", t1, t2); }
S V resl(L t1, L t2) { printf("T1: %ld, T2: %ld\n", t1, t2); }

L ilog10l(L n)_(L r = 0; W (n > 0, n /= 10; r++) r)

S I dir8[8][2] = {
  {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};
S I dir4cw[4][2] = {
  {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

#endif

