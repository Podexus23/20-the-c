#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSTACK 100                                 /* максимальный размер стэка */
static double stack[MAXSTACK];                       /* стэк для хранения чисел */
int stack_i = 0;                                     /* индикатор указателя стека */
static char operand_list[10] = {'*', '+', '-', '/'}; /* список возможных операций*/

enum getop_res
{
  NUMBER,
  OPERAND
};

int getop(char s[]);
void push(double arg);
double pop(void);

int main(int argc, char *argv[])
{
  while (--argc > 0)
  {
    switch (getop(*++argv))
    {
    case NUMBER:
      printf("number %s goes to stack\n", *(argv));
      push(atof(*argv));
      break;
    case OPERAND:
      printf("Poped out: %c\n", (char)(*argv[0]));
      double op2 = 0.0;
      double op1 = 0.0;
      switch ((char)(*argv[0]))
      {
      case '+':
        op2 = pop();
        op1 = pop();
        printf("two: %g\n", op2);
        printf("one: %g\n", op1);
        printf("both: %g\n", op1 + op2);
        push((op1 + op2));
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
      }
      break;
    default:
      printf("main: wrong number or operand, try again\n");
      break;
    }
  }

  int i = 0;
  while (i < 5)
    printf("%g\n", stack[i++]);
  return 0;
}

/* getop: по значению с указателя определяем действие.
  если первые идут буквы, значит комманды отправляем в комманды?
  если знаки значит операции отправляем в операции
  если цифры значит переводим в числа отправляем в числа
 */

int getop(char s[])
{
  if (isdigit(s[0]))
    return NUMBER;

  if (!isalnum(s[0]))
    if (strstr(operand_list, s))
    {
      return OPERAND;
    }
  return -1;
}

/*stack functions*/

void push(double arg)
{
  if (stack_i < MAXSTACK)
    stack[stack_i++] = arg;
  else
    printf("push: stack is full");
}

double pop(void)
{
  if (stack_i < 1)
    printf("pop: stack is empty");
  else
    return stack[--stack_i];
}