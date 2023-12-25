#include <stdio.h>

#define MAXSIZE 100

int getLine(char line[], int line_length);
void squeeze(char to_squeeze[], char from[]);

int main()
{
  char s1[MAXSIZE], s2[MAXSIZE];

  getLine(s1, MAXSIZE);
  getLine(s2, MAXSIZE);

  squeeze(s1, s2);
  printf("squeezed: %s", s1);
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

void squeeze(char to_squeeze[], char from[])
{
  char copy[MAXSIZE];
  int i = 0;

  while ((copy[i] = to_squeeze[i]) != '\0')
  {
    i++;
  }

  for (i = 0; from[i] != '\0'; ++i)
  {
    int j = 0;
    while (copy[j] != '\0')
    {
      if (copy[j] != from[i])
      {
        j++;
      }
      else
      {
        int t = j;
        while ((copy[t] = copy[t + 1]) != '\0')
        {
          t++;
        }
      }
    }
  }

  i = 0;
  while ((to_squeeze[i] = copy[i]) != '\0')
  {
    i++;
  }
}