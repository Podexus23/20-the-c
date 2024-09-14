/* задание 4.5, в 4.6 возможно действиетльно сделать переменные через 1 символ, последняя переменная будет last, не очень понятно зачем ну да ладно */

#include <stdio.h>
#include <stdlib.h> /* для объявления atof */
#include <math.h>
#include "calc.h"

#define MAXOP 100  /* максимальный размер операнда */
#define NUMBER '0' /* сигнал, что обнаружено число */
#define COMM '1'   /* сигнал, что обнаружена комманда */
enum math_op
{
  SIN = 1,
  EXP,
  POW,
  VAR,
  ARG
};

int getop(char s[]);
void push(double);
double pop(void);
int do_comm(char s[]);
double top(void);
// int do_var(char s[]);
// char do_arg(char s[]);

int main(void)
{
  int type;
  double op2, op1;

  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;
    case COMM:
      switch (do_comm(s))
      {
      case SIN:
        push(sin(pop()));
        break;
      case EXP:
        push(exp(pop()));
        break;
      case POW:
        op2 = pop();
        if ((top() == 0 && op2 <= 0) || (top() < 0 && ((int)op2 != op2)))
        {
          printf("POW: x < 0 and y is not integer, or x = 0 and y <= 0");
          push(op2);
        }
        else
          push(pow(pop(), op2));
        break;
        // case VAR:
        //   do_var(s);
        //   break;
        // case ARG:
        //   push(s[0]);
        //   do_arg(s);
        //   break;
      }
      break;

    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() - op2);
      else
        printf("error: zero divizor\n");
      break;
    case '%':
      op2 = pop();
      push((int)pop() % (int)op2);
      break;
    case '\n':
      printf("\t%.8g\n", top());
      break;

    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}