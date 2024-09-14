#include <stdio.h>

#define MAXSIZE 100000

int main(void)
{
  char ctrlv[MAXSIZE];

  int prev_slash = 0;            /* check for prime slash for making a comment*/
  int star_check = 0;            /* multi star for a comm*/
  int double_comm = 0, comm = 0; /* 1 if comment section started */
  char c;
  int i = 0;

  while ((c = getchar()) != EOF && i < MAXSIZE)
  {
    if (!prev_slash && c == '/')
      prev_slash = 1;

    else if (prev_slash && c == '/' && !star_check)
    {
      double_comm = 1;
      continue;
    }
    else if (double_comm && c == '\n')
    {
      double_comm = 0;
      prev_slash = 0;
      ctrlv[i++] = c;
      continue;
    }

    else if (comm && c == '*')
    {
      star_check = 1;
      continue;
    }

    else if (comm && star_check && c == '/')
    {
      comm = 0;
      star_check = 0;
      prev_slash = 0;
      continue;
    }

    else if (prev_slash && c == '*')
    {
      comm = 1;
      continue;
    }

    else if (double_comm || comm)
      continue;

    else
      ctrlv[i++] = c;
  }

  printf("--------------HERE COMES JOHNY-----------------");
  ctrlv[i] = '\0';
  printf("\n%s\n", ctrlv);

  return 0;
}