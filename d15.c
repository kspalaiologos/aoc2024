#include"a.h"
#define P 100
S C g[P][P],g2[P][P],t[P][3],cn,dr,dc,rr,rc;
V ec(I i, I j)_(C*p=g[i]+j;I(*p=='#'||*p=='.',R);C ch=*p;*p='.';
 CM(t[cn],((C[3]){i,j,ch}));cn++;ec(i+dr,j+dc);
 I(ch=='[',ec(i,j+1))I(ch==']',ec(i,j-1)))
I f(C*m, I d)_(I l=strlen(m);F2d(d,I(g[i][j]=='@',rr=i,rc=j))
 Fj(l,dr=dc=cn=0;SW(m[j],SC('v',dr=1)SC('^',dr=-1)SC('>',dc=1)SC('<',dc=-1)
  SD(CO))ec(rr,rc);I(!Fany(i,0,cn,g[t[i][0]+dr][t[i][1]+dc]!='.'),Fi(cn,
    t[i][0]+=dr;t[i][1]+=dc)rr+=dr;rc+=dc)Fi(cn,g[t[i][0]][t[i][1]]=t[i][2]))
 F2dsum(d,0,g[i][j]=='O'||g[i][j]=='['?i*P+j:0))
M(C*in=slurp("d15.txt"),*m=in+2550;F2d(50,T*e=g2[i];
 SW(g[i][j]=in[i*51+j],SC('@',e[j]='.@')SC('.',e[j]='..')
  SC('O',e[j]='][')SC('#',e[j]='##')))I p1=f(m,50);CM(g,g2);resi(p1,f(m,P)))