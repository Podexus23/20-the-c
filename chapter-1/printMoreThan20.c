#include <stdio.h>

#define POS_LENGTH 20
#define MAXLINE 100

int check_line();
int getLine(char arr[], int maxline);
void copy();

int main()
{
  int i, c;                       /* iterator and chracter catcher*/
  int line;                       /* line length */
  char strArr[100], copyArr[100]; /* arr to check, and arr to print if condition satisfied*/
  line = 0;
  while ((line = getLine(strArr, MAXLINE)) > 0)
  {
    if (line > POS_LENGTH)
    {
      printf("%s ", strArr);
      printf("line length: %d \n", line);
    }
    else
    {
      printf("\n");
    }
  }
  return 0;
}

int getLine(char arr[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    arr[i] = c;
  }
  if (c == '\n')
  {
    arr[i] = c;
    ++i;
  }
  arr[i] = '\0';
  return i;
}