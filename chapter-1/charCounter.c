#include <stdio.h>

#define CHARS_LN 26
#define NUMS_LN 10

void clean_arr(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    arr[i] = 0;
  }
}

int main()
{
  int chArr[CHARS_LN], numArr[NUMS_LN];
  int i, c, printCounter;

  clean_arr(chArr, CHARS_LN);
  clean_arr(numArr, NUMS_LN);

  while ((c = getchar()) != EOF)
  {
    if (c >= 'a' && c <= 'z')
    {
      ++chArr[c - 'a'];
    }

    if (c >= '0' && c <= '9')
    {
      ++numArr[c - '0'];
    }
  }

  printCounter = 0;
  for (i = 'a'; i <= 'z'; ++i)
  {
    printf("%c: ", (0 + i));
    for (int j = 0; j < chArr[printCounter]; ++j)
    {
      printf("#");
    }
    printf("\n");
    ++printCounter;
  }

  printCounter = 0;
  for (i = '0'; i <= '9'; ++i)
  {
    printf("%c: ", (0 + i));
    for (int j = 0; j < numArr[printCounter]; ++j)
    {
      printf("#");
    }
    printf("\n");
    ++printCounter;
  }
}