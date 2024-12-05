#include"a.h" // 185797128 89798695
M(C * p = slurp("d03.txt"); Re r; Rm m[3]; 
  regcomp(&r, "mul\\(([0-9]+),([0-9]+)\\)", REG_EXTENDED);
  I t1, t2, on = 1, n, z;  F$((t1 = t2 = 0), *p, p += n,
    I(!strncmp(p, "do()", 4), on = 1, n = 4)
    J(!strncmp(p, "don't()", 7), on = 0, n = 7)
    J(!regexec(&r, p, 3, m, 0) && !m[0].rm_so,
      z = atoi(&p[m[1].rm_so]) * atoi(&p[m[2].rm_so]);
      I(on, t2 += z) t1 += z; n = m[0].rm_eo) E(n = 1))
  resi(t1, t2))
// perl oneliner for part 1:
//   perl -nE '$s+=$1*$2while/mul\((\d+),(\d+)\)/g}{say$s' d03.txt