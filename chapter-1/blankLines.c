#include <stdio.h>

#define BLANK_LINE -5
#define MAXLINE 100

int check_line();
int getLine(char arr[], int maxline);

int main()
{
  int i, c;                       /* iterator and chracter catcher*/
  int line;                       /* line length */
  char strArr[100], copyArr[100]; /* arr to check, and arr to print if condition satisfied*/

  while ((line = getLine(strArr, MAXLINE)) > 0)
  {
    if (strArr[0] == '\0' && line == 1)
    {
      printf("%s", strArr);
    }
    else
    {
      printf("%s \n", strArr);
    }
  }
  printf("line: %d", line);
  return 0;
}

int getLine(char arr[], int lim)
{
  int c, i;
  int blank;

  blank = 0;
  for (i = 0; i < lim - 1; ++i)
  {
    arr[i] = 0;
  }

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    if (c == ' ' || c == '\t')
    {
      blank = 1;
      --i;
    }
    else if (blank == 1 && (c != ' ' || c != '\t'))
    {
      arr[i] = ' ';
      ++i;
      arr[i] = c;
      blank = 0;
    }
    else if (blank == 0)
    {
      arr[i] = c;
    }
  }
  arr[i] = '\0';
  if (i == 0 && blank == 1)
    ++i;
  return i;
}