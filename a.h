
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
typedef unsigned int UI;
typedef unsigned long UL;
typedef void V;
typedef char C;
typedef double D;
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
#define SWAP(a,b) {typeof(a) t = a; a = b; b = t;}

// Type-generic insertion sort.
// E.g. L a[10]; isort(a, 10, y < x); sorts descending.
#define isort(v, n, c...) \
  { L j; typeof(v[0]) y, x; \
    Fi(n, y = v[i], j = i; \
      W(j > 0 && ({ x = v[j - 1]; c; })) \
        v[j] = v[j - 1], j--; v[j] = y)}

S FILE * fget(C * n, C * m) {
  FILE * f = fopen(n, m);
  I(!f, perror("fopen"); exit(1)); R f;
}
S I scanl(FILE * f, L * l)_(fscanf(f, "%ld", l) != EOF)
S C * slurp(C * n) {
  FILE * f = fget(n, "r");
  fseek(f, 0, SEEK_END);
  L s = ftell(f);
  rewind(f);
  C * d = malloc(s + 1);
  fread(d, 1, s, f);
  d[s] = '\0';
  return d;
}

#define sgn(x) ((x > 0) - (x < 0))

#endif

