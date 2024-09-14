#include <stdio.h>

#define ALLOCSIZE 10000 /* размер доступного пространства */

static char allocbuf[ALLOCSIZE]; /* выделенная память */
static char *allocp = allocbuf;  /* указатель на свободное место */

char *alloc(int n);

int main(void)
{
  char *op;

  op = alloc(10);
  printf("%s", op);
  alloc(10001);
  return 0;
}

char *alloc(int n) /* возвращает указатель на n символов*/
{
  if (allocbuf + ALLOCSIZE - allocp >= n)
  {
    allocp += n;
    return allocp - n;
  }
  else
    return 0;
}

void afree(char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}