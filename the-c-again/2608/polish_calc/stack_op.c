#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /* максимальная глубина стека val */

int sp = 0;         /* следующая свободная поизция в стеке */
double val[MAXVAL]; /* стек операндов */

/* push: помещает число f в стек операндов */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: извлекает и возвращает верхнее число из стека*/
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* get_all_stack: показывает все значения в стэке*/
void get_all_stack(void)
{
  int i;

  for (i = 0; i < sp; i++)
    printf("%g ", val[i]);
  printf("\n");
}

/* top: показывает и возвращает верхнее значение стака*/
double top(void)
{
  int i;
  return val[sp - 1];
}

/* copy: копирует последнее значение в стаке*/
void copy(void)
{
  if (sp < MAXVAL)
  {
    val[sp] = val[sp - 1];
    sp++;
  }
  else
    printf("error: stack full, can't push %g\n", val[sp - 1]);
}

/* swap: заменяет два последних значения*/
void swap(void)
{
  double ex;

  if (sp > 1)
  {
    ex = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = ex;
  }
  else
  {
    printf("swap: not enough arguments to swap\n");
  }
}

/* clean_stack: чистик массив и обнуляет указатель*/
void clean_stack(void)
{
  int i;

  for (i = 0; i < sp; i++)
    val[i] = '\0';
  sp = 0;
}