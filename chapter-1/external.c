#include <stdio.h>
#define MAXLINE 100
#define TABLINE 4
#define TABSYMBOL 'O'
#define SPBSYMBOL '|'

int blankCounter;

void detab(char arr[], int index);
int entab(char arr[], int index);
int getLine(char arr[]);

int main()
{
  int i, c;
  int length;
  char line[MAXLINE];
  extern int blankCounter;
  blankCounter = 0;

  while ((length = getLine(line)) > 0)
  {
    printf("%s", line);
  }

  return 0;
}

int getLine(char arr[])
{
  int i, c;
  int toRemove;
  extern int blankCounter;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    if (c == TABSYMBOL || c == '\t')
    {
      detab(arr, i);
      i += TABLINE - 1;
      c = SPBSYMBOL;
      blankCounter += 4;
    }
    else if (blankCounter == 0 && (c == ' ' || c == SPBSYMBOL))
    {
      blankCounter = 1;
    }
    else if (blankCounter > 0 && (c == ' ' || c == SPBSYMBOL))
    {
      blankCounter += 1;
    }
    else if (blankCounter != 0 && c != ' ' && c != SPBSYMBOL)
    {
      toRemove = entab(arr, i);
      printf("remove result: %d\n", toRemove);
      i -= toRemove;
      arr[i] = c;
      blankCounter = 0;
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
    arr[i] = SPBSYMBOL;
  }
}

int entab(char arr[], int index)
{
  extern int blankCounter;
  int tabs, spaces, moves;
  printf("index: %d \n", index);
  printf("counter: %d \n", blankCounter);

  if (blankCounter >= TABLINE)
  {
    tabs = blankCounter / TABLINE;
    spaces = blankCounter - tabs * TABLINE;
  }
  else
  {
    spaces = blankCounter;
  };

  moves = tabs + spaces;
  printf("tabs: %d, spaces: %d\n", tabs, spaces);

  for (int i = index - blankCounter; i < index + moves; ++i)
  {
    if (tabs > 0)
    {
      arr[i] = TABSYMBOL;
      tabs -= 1;
    }
    else if (spaces > 0)
    {
      arr[i] = SPBSYMBOL;
      spaces -= 1;
    }
  }
  return blankCounter - (moves);
}