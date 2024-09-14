#include <stdio.h>

/* echo */
int main(int argc, char *argv[])
{
  int i;

  for (i = 1; i < argc; i++)
    printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
  printf("\n");
  return 0;
}
// просто какой нибудь код
/* echo: вывод аргументов командной строки; 2-ая версия */
int echo2(int argc, char *argv[])
{
  while (--argc > 0)
    printf("%s%s", *++argv, (argc > 1) ? " " : "");
  printf("\n");
  return 0;
}