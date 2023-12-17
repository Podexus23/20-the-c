#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
  int c, i, nwhite, counter, state;
  int ndigit[20];

  nwhite = counter = 0;
  state = OUT;
  for (i = 0; i < 15; i++)
  {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',')
    {
      ndigit[counter]++;
      state = OUT;
      counter = -1;
    }
    else if (state == OUT)
    {
      state = IN;
      counter = 0;
    }
    counter++;
  }

  printf("digits =\n");
  for (i = 1; i < 15; ++i)
  {
    printf("%2d times: ", i);
    for (int j = 0; j < ndigit[i]; j++)
    {
      printf("#");
    }
    printf("\n");
  }
}