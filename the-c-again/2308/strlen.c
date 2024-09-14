#include <stdio.h>
#include <string.h>
#include <ctype.h>

int numbs[10];

int power(int x, int y);

int main(void)
{
  char line[] = "0x008CAD";
  int len;
  int i;
  int result;
  int num;

  len = strlen(line) - 1;
  result = 0;
  if (line[0] == '0' && (line[1] == 'x' || line[1] == 'X'))
  {
    len = len - 2;
  }

  for (i = 0; i <= len; ++i)
  {
    num = line[i + 2];
    if (num > '9')
    {
      num = tolower(num);
      if (num == 'a')
        num = 10;
      if (num == 'b')
        num = 11;
      if (num == 'c')
        num = 12;
      if (num == 'd')
        num = 13;
      if (num == 'e')
        num = 14;
      if (num == 'f')
        num = 15;
    }
    else
      num = num - '0';
    printf("%d\n", result);
    result = result + num * power(16, len - i);
  }

  printf("%x\n", result);
  printf("%s\n", line);

  return 0;
}

int power(int x, int y)
{
  int res, i;

  res = x;
  if (y == 0)
    res = 1;

  for (i = 1; i < y; ++i)
  {
    res = res * x;
  }

  return res;
}

int atoi(char s[])
{
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
  {
    n = 10 * n + (s[i] - '0');
  }
  return n;
}
