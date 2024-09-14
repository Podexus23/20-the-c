#include <stdio.h>

int main(void)
{
  char s[] = "pointer";
  char *p;

  int x = 1;
  int *xp;
  xp = &x;
  *xp += 1;
  printf("%d\n", x);
  p = &s[2];
  // printf("%s", p);
  *p = 'h';
  printf("%s", s);
  return 0;
}