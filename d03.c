#include"a.h"
I main(V) {
  C * data = slurp("d03.txt"), * p = data;
  regex_t r, y, n;  regmatch_t m[3];  I t1, t2, on = 1;
  regcomp(&r, "mul\\(([0-9]{1,3}),([0-9]{1,3})\\)", REG_EXTENDED);
  regcomp(&y, "do\\(\\)", REG_EXTENDED);
  regcomp(&n, "don't\\(\\)", REG_EXTENDED);
  F$ ((t1 = t2 = 0), !regexec(&r, p, 3, m, 0), p += m[0].rm_eo,
    t1 += atoi(&p[m[1].rm_so]) * atoi(&p[m[2].rm_so]))
  F$ (p = data, *p != '\0', p += m[0].rm_eo,
    I(!regexec(&y, p, 1, m, 0) && !m[0].rm_so, on = 1)
    J(!regexec(&n, p, 1, m, 0) && !m[0].rm_so, on = 0)
    J(!regexec(&r, p, 3, m, 0) && !m[0].rm_so,
      I(on, t2 += atoi(&p[m[1].rm_so]) * atoi(&p[m[2].rm_so])))
    E(m[0].rm_eo = 1))
  printf("T1: %d, T2: %d\n", t1, t2);
}
