#include <stdio.h>
#include <ctype.h>

#define ON 1
#define OFF 0
#define MAXSIZE 10000

/* программа для зачисти из кода элементов за кавычками и комментариев из потока*/
//! сделать что бы жрала не из потока
/*
  получаем указатель на массив с данными
*/

char text[MAXSIZE];
char text2[MAXSIZE];

char getch(void);                                   /* либо берет отлиженный кусок потока, либо берет поток*/
void ungetch(char c);                               /* кладет в запас не использованный кусок потока */
char *remove_comm(int, int);                        /* убирает комменты из потока */
char *remove_comm_arr(int comm, int br, char *arr); /* убирает комменты из массива текста */
void str_up(char *dest, char *from);                /* переносит в dest, всю инфорцию из from до '\0' */

// int main(int argc, char **argv)
// {
//   char c;
//   int i = 0;

//   while ((c = getchar()) != EOF)
//     text2[i++] = c;
//   text2[i] = '\0';

//   remove_comm_arr(ON, ON, text2);
//   printf("%s\n", text2);
//   return 0;
// }

/*
  remove_comm: удаляем комментарии и данные в кавычках, возвращает указатель на текст
  comm = 1, удаляем комментарии, br = 1 удаляем в кавычках
*/
char *remove_comm(int comm, int br)
{
  char c;
  int i = 0;
  int open_slash = OFF;
  int open_bracets = OFF;

  while ((c = getch()) != EOF)
  {
    if (open_slash)
    {
      if (c == '/') /* строковый комментарий */
      {
        c = getch();

        while (c != EOF && c != '\n')
          c = getch();

        ungetch(c);
        open_slash = OFF;
        continue;
      }
      else if (c == '*') /* многострочный коммент */
      {

        while ((c = getch()) != EOF)
        {
          if (c == '*')
          {
            c = getch();
            if (c == '/')
            {
              open_slash = OFF;
              break;
            }
            else
              ungetch(c);
          }
        }
      }
      else
        open_slash = OFF;
    }

    else if (open_bracets)
    {
      if (c != '\"')
      {
        while (c != EOF && c != '\"')
          c = getch();
        if (c == '\"')
          open_bracets = OFF;
      }
    }

    else if (c == '/' && comm)
      open_slash = ON;

    else if (c == '\"' && br)
      open_bracets = ON;

    else
      text[i++] = c;
  }
  printf("------------------------COMM REMOVED-------------------------\n");
  return text;
}

/*
  remove_comm_arr: удаляем комментарии и данные в кавычках, возвращает указатель на текст
  comm = 1, удаляем комментарии, br = 1 удаляем в кавычках
*/
char *remove_comm_arr(int comm, int br, char *arr)
{
  int i = 0;
  char *c = arr;
  int open_slash = OFF;
  int open_bracets = OFF;

  char *from;
  char *dest;
  int temp = 0;
  while (c[i] != '\0')
  {
    if (open_slash)
    {
      if (c[i] == '/') /* строковый комментарий */
      {
        dest = &c[--i];
        temp = i;

        while (c[i] != '\0' && c[i] != '\n')
          i++;

        from = &c[++i];
        str_up(dest, from);
        i = temp;

        open_slash = OFF;
        continue;
      }

      else if (c[i] == '*') /* многострочный коммент */
      {
        dest = &c[--i];
        temp = i;

        while (c[i++] != '\0')
        {
          if (c[i] == '*')
          {
            i++;
            if (c[i] == '/')
            {
              from = &c[++i];
              str_up(dest, from);
              i = temp;
              open_slash = OFF;
              break;
            }
          }
        }
      }
      else
        open_slash = OFF;
    }

    else if (open_bracets)
    {
      dest = &c[--i];
      temp = i++;
      if (c[i] != '\"')
      {
        while (c[i] != '\0' && c[i] != '\"')
          i++;
        if (c[i] == '\"')
        {
          from = &c[++i];
          str_up(dest, from);
          i = temp;
          open_bracets = OFF;
        }
      }
    }

    else if (c[i] == '/' && comm)
      open_slash = ON;

    else if (c[i] == '\"' && br)
      open_bracets = ON;
    i++;
  }
  printf("------------------------COMM REMOVED-------------------------\n");
  return arr;
}

/* str_up: сдвигает массив из from в dest*/
void str_up(char *dest, char *from)
{
  while (*from != '\0')
    *dest++ = *from++;

  *dest = '\0';
}

char ch_buf[MAXSIZE];
int ch_buf_i = 0;

char getch(void)
{
  return (ch_buf_i > 0) ? ch_buf[--ch_buf_i] : getchar();
}

void ungetch(char c)
{
  if (ch_buf_i < MAXSIZE - 1)
  {
    ch_buf[ch_buf_i++] = c;
  }
  else
    printf("ungetch: sorry buf is full\n");
}
