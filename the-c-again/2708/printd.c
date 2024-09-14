#include <stdio.h>

void printd(int n);

int main(void)
{

  printd(123);
  return 0;
}

void printd(int n)
{
  if (n < 0)
  {
    putchar('-');
    n = -n;
  }
  if (n / 10)
    printd(n / 10);
  putchar(n % 10 + '0');
}

void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);

  if (left >= right)                  /* ничего не делается если */
    return;                           /*в массиве менее двух элементов*/
  swap(v, left, (left + right) / 2);  /* делящий элемент */
  last = left;                        /* переносится в v[0] */
  for (i = left + i; i <= right; i++) /* деление на части */
    if (v[i] < v[left])
      swap(v, ++last, i);

  swap(v, left, last); /* перезапоминаем делящий элемент */
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}