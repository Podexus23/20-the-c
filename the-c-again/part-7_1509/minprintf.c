#include <stdarg.h>
#include <stdio.h>

int main(int argc, char **argv)
{

  return 0;
}

/* minprint: ограниченная версия printf со списком аргументов переменной длины */

void minprintf(char *fmt, ...)
{
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt); /* установить ap на 1-ый аргумент из имени*/
  for (p = fmt; *p; p++)
  {
    if (*p != '%')
      putchar(*p);
    continue;
  }
  switch (*++p)
  {
  case 'd':
    ival = va_arg(ap, int);
    printf("%d", ival);
    break;
  case 'f':
    dval = va_arg(ap, double);
    printf("%f", dval);
    break;
  case 's':
    for (sval = va_arg(ap, char *); *sval; sval++)
      ;
    putchar(*sval);
    break;
  default:
    putchar(*sval);
    break;
  }
}