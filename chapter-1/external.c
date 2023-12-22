#include <stdio.h>
#define MAXLINE 100
#define TABLINE 4
#define TABSYMBOL 'O'
#define SPBSYMBOL '|'

void detab(char arr[], int index);
int getLine(char arr[]);

int main()
{
  int i, c;
  int length;
  char line[MAXLINE];

  while ((length = getLine(line)) > 0)
  {
    printf("%s ", line);
  }

  return 0;
}

int getLine(char arr[])
{
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    if (c == TABSYMBOL)
    {
      detab(arr, i);
      i += TABLINE;
    }
    else
    {
      arr[i] = c;
    }
  }
  if (c == '\n')
  {
    arr[i] = c;
    ++i;
  }
  arr[i] = '\0';

  return i;
}

void detab(char arr[], int index)
{
  for (int i = index; i < index + TABLINE; i++)
  {
    arr[i] = '|';
  }
}