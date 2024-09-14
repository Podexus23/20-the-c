#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char a[] = "copy";
  char b[] = "copy";
  char c;
  int i;
  int res = (a[1] == b[1]);
  i = 0;

  c = getchar();
  if (isalpha(c))
  {
    while (isalpha(a[++i] = c = getchar()))
      ;
  }
  printf("%s\n", a);

  return 0;
}