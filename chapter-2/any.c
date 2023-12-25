#include <stdio.h>

#define MAXSIZE 100

int getLine(char line[], int line_length);
int any(char to_search[], char from[]);

int main()
{
  char s1[MAXSIZE], s2[MAXSIZE];
  int foundAny;

  getLine(s1, MAXSIZE);
  getLine(s2, MAXSIZE);

  foundAny = any(s1, s2);
  printf("any result: %d", foundAny);
  return 0;
}

int getLine(char line[], int line_length)
{
  int c, i;

  for (i = 0; i < line_length - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }
  line[i] = '\0';
  return i;
}

int any(char to_search[], char from[])
{
  int min = MAXSIZE;
  int j = 0;
  for (int i = 0; from[i] != '\0'; ++i)
  {
    j = 0;
    while (to_search[j] != '\0')
    {
      if (to_search[j] == from[i] && from[i] != '\0')
      {
        if (j < min)
          min = j;
      }
      j++;
    }
  }
  if (min < MAXSIZE)
    return min;
  else
    return -1;
}