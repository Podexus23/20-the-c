#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

int main(int argc, char **argv)
{
  char hop[20];
  int one;
  minscanf("%d", &one);
  scanf("%s", hop);
  printf("Thats much : %d\n", one);
  printf("A vot 4to: %s\n", hop);
  return 0;
}

void minscanf(char *fmt, ...)
{
  va_list ap;
  char *p, *sval;
  int ival[20];
  int ival_cnt = 0;
  float dval[20];
  int dval_cnt = 0;

  va_start(ap, fmt);
  for (p = fmt; *p; p++)
  {
    if (*p != '%')
      continue;
    switch (*++p)
    {
    case 'd':
      scanf("%d", va_arg(ap, int *));
      break;
    case 'f':
      scanf("%f", va_arg(ap, float *));
      break;
    }
  }
}