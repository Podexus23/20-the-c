#include <stdio.h>

#define MAXSIZE 15

int search(char s[], int c);

int main()
{

  char one[15] = "passos biba";
  char dva[15] = "lx";

  int i, res;
  i = 0;
  res = -1;
  while (res == -1 && dva[i] != '\0')
  {
    res = search(one, dva[i]);
    i++;
  }

  printf("Cycle %d\n", res);
  return 0;
}

int search(char s[], int c)
{
  int i = 0;
  int res = -1;

  while (res == -1 && s[i] != '\0')
  {
    if (s[i] == c)
    {
      res = i;
    }
    ++i;
  }
  return res;
}