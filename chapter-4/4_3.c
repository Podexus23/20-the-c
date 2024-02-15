#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define MAXOP 100
#define NUMBER '0'
#define COMMAND 'a'

#define STACK_TOP "top"
#define STACK_COPY "copy"
#define STACK_CHANGE "change"
#define STACK_CLEAN "clean"
#define STACK_LNG "length"

#define MAXVAL 100

#define BUFSIZE 100

int sp = 0;         /* position */
double val[MAXVAL]; /* stack */

char buf[BUFSIZE];
int bufp = 0; /* next available pos in buffer*/

int getop(char s[]);
int getword(char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int c);
void get_stack_top(void);

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
    case COMMAND:
      getword(s);
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
      // printf("\t%.8g\n", pop());
      get_stack_top();
      break;
    default:
      printf("Error: unknown operatios %s\n", s);
      break;
    }
  }
  return 0;
}
/* STACK COMMS */
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
/* ADDED COMMANDS */
void get_stack_top(void)
{
  if (sp > 0)
  {
    printf("stack top: %g\n", val[sp - 1]);
  }
  else
  {
    printf("Error: stack is empty\n");
  }
}

void copy_stack_top(void)
{
  if (sp > 0)
  {
    push(val[sp - 1]);
  }
  else
  {
    printf("Error: stack is empty\n");
  }
}

void change_stack_top(void)
{
  double s1, s2;

  if (sp > 1)
  {
    s1 = val[sp - 1];
    s2 = val[sp - 2];
    val[sp - 2] = s1;
    val[sp - 1] = s2;
  }
  else
  {
    printf("Error: not enough elemenets in stack\n");
  }
}

void clean_stack(void)
{
  int i;
  for (i = 0; i <= sp; i++)
  {
    val[i] = '\0';
  }
  sp = 0;
  printf("stack is empty");
}

void get_stack_length(void)
{
  printf("Stack length: %i", sp);
}

int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
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

  if (c >= 'a' && c <= 'z')
  {
    ungetch(c);
    return COMMAND;
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

int check_word(char s1[], char s2[])
{
  int i = 0;

  while (s1[i] != '\0')
  {
    if (s1[i] != s2[i])
      return FALSE;
    i++;
  }
  return TRUE;
}

int getword(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
  {
    ;
  }

  s[1] = '\0';
  i = 0;
  while ((s[++i] = c = getch()) >= 'a' && c <= 'z')
  {
    ;
  }
  s[i] = '\0';

  if (check_word(s, STACK_CHANGE) == TRUE)
    change_stack_top();
  if (check_word(s, STACK_CLEAN) == TRUE)
    clean_stack();
  if (check_word(s, STACK_COPY) == TRUE)
    copy_stack_top();
  if (check_word(s, STACK_TOP) == TRUE)
    get_stack_top();
  if (check_word(s, STACK_LNG) == TRUE)
    get_stack_length();
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