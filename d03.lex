%{
  int p1, p2, on=1, x, y; /* Alternative, less clean solution: a Flex scanner for day 3 */
%}
%%
mul\([0-9]+,[0-9]+\) sscanf(yytext+4,"%d,%d",&x,&y);p1+=x*=y;if(on)p2+=x;
do(n\'t)?"()" on=!yytext[4];
.|\n { }
%%
int yywrap(){}int main(){yylex();printf("T1: %d, T2: %d\n",p1,p2);}
