#include <stdio.h>
#include <ctype.h>

#define SIZE 100

/* буффер для getch ungetch*/
#define BUFF_SIZE 100
int buff[BUFF_SIZE];
int bufp = 0;

int getint(int *);
double getfloat(double *);
int getch(void);
void ungetch(int);

int main(void)
{
  int n, array[SIZE], getint(int *);
  // for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
  //   ;

  double arrayf[SIZE], getfloat(double *);
  for (n = 0; n < SIZE && getfloat(&arrayf[n]) != EOF; n++)
    ;
  // printf("Int Number: %d\n", array[0]);
  printf("Float Number: %g\n", arrayf[0]);
  return 0;
}

int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (isspace(c))
  {
    ungetch((sign < 0) ? '-' : '+');
    return getint(pn);
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

double getfloat(double *pn)
{
  int c, sign;
  int dec;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-')
    c = getch();
  if (isspace(c))
  {
    ungetch((sign < 0) ? '-' : '+');
    return getfloat(pn);
  }
  for (*pn = 0.0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c - '0');
  if (c == '.')
    c = getchar();
  for (dec = 1.0; isdigit(c); c = getch())
  {
    *pn = 10.0 * *pn + (c - '0');
    dec *= 10;
  }
  *pn /= dec;
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int getch(void)
{
  return (bufp > 0) ? buff[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp < BUFF_SIZE)
  {
    buff[bufp++] = c;
  }
  else
    printf("ungetch: buffer is full\n");
}