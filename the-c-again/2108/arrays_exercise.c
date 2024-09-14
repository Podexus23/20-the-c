/* 1. вывод гистограммы длинны слов из входного потока горизонтальная и вертикальная */
/* 2. вывод гистограммы различных символов из входного потока */

/* 1.
  массив с длиннами слов
  определние начала и конца слов
  не печатать длинны которых небыло в потоке
*/
/* 1.
  массив с длиннами слов
  определние начала и конца слов
  не печатать длинны которых небыло в потоке

  отслеживать самую высокую и из неё делать количество строк на оборажение
*/

#include <stdio.h>

#define IN 1
#define OUT 0
#define SIZE 200

int main(void)
{
  int c, i, j;
  int chars[SIZE];

  for (i = 0; i < SIZE; ++i)
    chars[i] = 0;

  while ((c = getchar()) != EOF)
  {
    chars[c] = chars[c] + 1;
  }

  for (i = 0; i < SIZE; ++i)
  {
    if (chars[i] > 0)
    {
      printf("%3c ", i);
      for (j = 0; j < chars[i]; ++j)
        printf("#");
      printf("\n");
    }
  }
}

int vert_gysto(void)
{
  int c, i, j, state, nc;
  int max_size, sizes;
  int words[SIZE];

  state = OUT;
  nc = max_size = sizes = 0;
  for (i = 0; i < SIZE; ++i)
    words[i] = 0;

  while ((c = getchar()) != EOF)
  {
    if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
    {
      state = OUT;
      words[nc] = words[nc] + 1;
      sizes == sizes + 1;
      nc = 0;
    }
    else if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      nc = 0;
    }
    else
    {
      state = IN;
      ++nc;
    }
  }

  for (i = 0; i < SIZE; ++i)
  {
    if (words[i] > max_size)
      max_size = words[i];
  }

  for (i = max_size; i > 0; --i)
  {
    for (j = 0; j < SIZE; j++)
    {
      if (words[j] > 0 && words[j] >= i)
      {
        printf("# ");
      }
      if (words[j] > 0 && words[j] < i)
      {
        printf("* ");
      }
    }
    printf("\n");
  }
  for (i = 0; i < SIZE; ++i)
  {
    if (words[i] > 0 && i < 9)
    {
      printf("%d ", i);
    }
    else if (words[i] > 0 && i > 9)
    {
      printf("%d", i);
    }
  }
  printf("\n");

  printf("%d\n", max_size);
}

int hor_gysto(void)
{
  int c, i, j, state, nc;
  int words[SIZE];

  state = OUT;
  nc = 0;
  for (i = 0; i < SIZE; ++i)
    words[i] = 0;

  while ((c = getchar()) != EOF)
  {
    if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
    {
      state = OUT;
      words[nc] = words[nc] + 1;
      nc = 0;
    }
    else if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      nc = 0;
    }
    else
    {
      state = IN;
      ++nc;
    }
  }

  for (i = 0; i < SIZE; ++i)
  {
    if (words[i] != 0)
    {
      printf("%3d ", i);
      for (j = 0; j < words[i]; ++j)
        printf("#");
      printf("\n");
    }
  }
}