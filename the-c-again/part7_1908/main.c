#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define getchar() getc(stdin);
#define putchar() putc((c), stdout);

/* cat: сцепление файлов по порядку, версия 1 */
int main(int argc, char **argv)
{
  FILE *fp;
  void filecopy(FILE *, FILE *);
  char *prog = argv[0]; /* имя программы для сообщегния */

  if (argc == 1) /* нет аргументов, стандартный поток*/
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
      if ((fp = fopen(*++argv, "r")) == NULL)
      {
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
      }
      else
      {
        filecopy(fp, stdout);
        fclose(fp);
      }
  if (ferror(stdout))
  {
    fprintf(stderr, "%s: error writing wtdout\n", prog);
    exit(2);
  }
  return 0;
}

/* filecopy: копирование файла ifp в файл ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}

/* fgets: считывание не более n символов из iop */
char *f_gets(char *s, int n, FILE *iop)
{
  register int c;
  register char *cs;

  cs = s;
  while (--n > 0 && (c = getc(iop)) != EOF)
    if ((*cs++ = c) == '\n')
      break;
  *cs = '\0';
  return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: вывод строки s в файл iop */
int f_puts(char *s, FILE *iop)
{
  int c;

  while (c = *s++)
    putc(c, iop);
  return ferror(iop) ? EOF : 0;
}

/* getline: считывает строку и возвращает её длину */
int get_line(char *line, int max)
{
  if (f_gets(line, max, stdin) == NULL)
    return 0;
  else
    return strlen(line);
}