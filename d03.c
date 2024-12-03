#include"a.h"
I main(V) {
  C * data = slurp("d03.txt"), * p = data;
  regex_t r;  regmatch_t m[3];  I t1, t2, on = 1, n;
  regcomp(&r, "mul\\(([0-9]{1,3}),([0-9]{1,3})\\)", REG_EXTENDED);
  F$ ((t1 = t2 = 0), !regexec(&r, p, 3, m, 0), p += m[0].rm_eo,
    t1 += atoi(&p[m[1].rm_so]) * atoi(&p[m[2].rm_so]))
  F$ (p = data, *p != '\0', p += n,
    I(!strncmp(p, "do()", 4), on = 1, n = 4)
    J(!strncmp(p, "don't()", 7), on = 0, n = 7)
    J(!regexec(&r, p, 3, m, 0) && !m[0].rm_so,
      I(on, t2 += atoi(&p[m[1].rm_so]) * atoi(&p[m[2].rm_so]))
      n = m[0].rm_eo) E(n = 1))
  printf("T1: %d, T2: %d\n", t1, t2);
}
