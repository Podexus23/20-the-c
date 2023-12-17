#include <stdio.h>

#define IN 1       /* inside a word */
#define OUT 0      /* outside a word */
#define MAX_DIG 15 /* maximum word length to count*/

int main()
{
  int c, i, nwhite, counter, state;
  int ndigit[MAX_DIG], maxDig;

  nwhite = counter = 0;
  state = OUT;
  for (i = 0; i <= MAX_DIG; i++)
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

  printf("Word gistogramm: \n");
  for (i = MAX_DIG; i >= 1; --i)
  {
    for (int j = 1; j <= MAX_DIG; j++)
    {
      if (ndigit[j] >= i)
        printf(" # ");
      else
        printf(" . ");
    }
    printf("\n");
  }

  for (i = 1; i <= MAX_DIG; ++i)
  {
    printf("%2d ", i);
  }
  printf("\n");
  for (i = 1; i <= MAX_DIG; ++i)
  {
    printf("%2d ", ndigit[i]);
  }
}