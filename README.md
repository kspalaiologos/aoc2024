# aoc2024

## Miscellany

D09 parts 1, 2 are miscompiled by clang and gcc on some platforms. The compiler assumes that the scanning loop does not need to be unrolled, collapsing it into a single tight loop:

```c
#define U I(e[++j], B) /* Manual Unroll */
/* ... */
W(1, U U U U)
```

Compiles to:

```
 17.24 │4e3:   inc          %r13d
 16.52 │       cmp          %r14d,%r13d
       │     ↑ jge          430
 16.49 │4ef:   movslq       %r13d,%r11
 31.55 │       cmpw         $0x0,0x30de6(%rsp,%r11,2)
 15.89 │     ↑ jne          4e3
```

Which is of course very inefficient. This issue costs us about 80% of the runtime.

Perl one-liner for day 3 part 1:
```perl
perl -nE '$s+=$1*$2while/mul\((\d+),(\d+)\)/g}{say$s' d03.txt
```

Flex scanner for day 3 (both parts):
```
%{
  int p1, p2, on=1, x, y; /* A compact Flex scanner for day 3 */
%}
%%
mul\([0-9]+,[0-9]+\) sscanf(yytext+4,"%d,%d",&x,&y);p1+=x*=y;p2+=on*x;
do(n\'t)?"()" on=!yytext[4];
.|\n { }
%%
int yywrap(){}int main(){yylex();printf("T1: %d, T2: %d\n",p1,p2);}
```