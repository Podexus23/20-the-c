#include <stdio.h>

#define swap(s, a, b) \
  int i = s[a];       \
  s[a] = s[b];        \
  s[b] = i;

#define on(xpl) printf(#xpl " =%d\n", xpl)

int main(void)
{
  int x = 4;
  int y = 2;

  // int s[5] = {1, 2};/
  char s[10] = "hello";
  int c[5] = {5, 6};

  printf("%s\n", s);
  swap(s, 0, 1);
  printf("%s\n", s);
}
