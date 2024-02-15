#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

#define MAXVAL 100

#define BUFSIZE 100

int sp = 0;         /* position */
double val[MAXVAL]; /* stack */

char buf[BUFSIZE];
int bufp = 0; /* next available pos in buffer*/

int getop(char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int c);

int main()
{
  int type;
  double op1, op2, rem, res;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
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
        push(pop() / op2);
      else
        printf("Error: trying to divide by 0");
      break;
    case '%':
      op2 = pop();
      op1 = pop();
      if (op2 > op1)
        push(op1);
      else
      {
        res = op1 / op2;
        push(op1 - (op2 * (int)res));
      }
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("Error: unknown operatios %s\n", s);
      break;
    }
  }
  return 0;
}

void push(double f)
{
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
    printf("Error: stack is full, %g not pushable\n", f);
}

double pop(void)
{
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("Error: stack is empty\n");
    return 0.0;
  }
}

int getop(char s[])
{
  int i, c;

  4 6 while ((s[0] = c = getch()) == ' ' || c == '\t')
  {
    ;
  }

  s[1] = '\0';
  i = 0;

  if (c == '-')
  {
    c = getch();
    if (!isdigit(c) && c != '.')
    {
      ungetch(c);
      return '-';
    }
    s[++i] = c;
  }

  if (!isdigit(c) && c != '.')
    return c;

  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  if (c == '.')
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  s[i] = '\0';
  printf("The number %s\n", s);
  if (c != EOF)
  {
    ungetch(c);
  }

  return NUMBER;
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
  {
    printf("ungetch: too much symbols\n");
  }
  else
    buf[bufp++] = c;
}