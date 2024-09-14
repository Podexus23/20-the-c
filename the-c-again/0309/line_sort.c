#include <stdio.h>
#include <string.h>

#define MAXLINES 5000  /* маскимально число строк */
#define MAXLEN 1000    /* максимальная длина строки */
#define MAXSTORE 10000 /* максимально количество символов которое может быть сохранено */

char *lineptr[MAXLINES]; /* указатели на строки */

int readlines(char *lineptr[], int nlines, char *stored_str);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* сортировка строк */
int main(void)
{
  int nlines;              /* количство прочитанных строк */
  char allocbuf[MAXSTORE]; /* массив с указателями на строки */

  if ((nlines = readlines(lineptr, MAXLINES, allocbuf)) >= 0)
  {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  }
  else
  {
    printf("ошибка: слишком много строк\n");
    return 1;
  }
}

int get_line(char *, int);
char *alloc(int);

/* readlines: чтение строк */
int readlines(char *lineptr[], int maxlines, char *stored_str)
{
  int len, nlines;
  char *p = stored_str + strlen(stored_str);
  char line[MAXLEN];
  nlines = 0;

  while ((len = get_line(line, MAXLEN)) > 0)
    if (nlines >= maxlines || stored_str + MAXSTORE - p < len)
      return -1;
    else
    {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  return nlines;
}

/* writelines: вывод строк в выходной поток */
void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/* get_line: считывает строку в s, возвращает её длину */
int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* qsort: сортировка v[left] ... v[right] в порядке возрастания */

void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

/* swap: обмен местами v[i] и v[j]*/
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}