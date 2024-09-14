#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

/* find: вывод строк, содержащих образец из 1-го аргумента */
int main(int argc, char *argv[])
{
  char line[MAXLINE];
  int found = 0;

  if (argc != 2)
    printf("Usage: find pattern\n");
  else
    while (getline(line, MAXLINE) > 0)
      if (strstr(line, argv[1]) != NULL)
      {
        printf("%s", line);
        found++;
      }
  return found;
}

/* find: вывод строк, содержащих образец из последнего аргумента */
int find2(int argc, char *argv[])
{
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c)
      {
      case 'x':
        except = 1;
        break;
      case 'n':
        number = 1;
        break;
      default:
        printf("Find: illegal option %c\n", c);
        argc = 0;
        found = -1;
        break;
      }

  if (argc != 1)
    printf("Usage: find -x -n pattern\n");
  else
    while (getline(line, MAXLINE) > 0)
    {
      lineno++;
      if ((strstr(line, argv[1]) != NULL) != except)
      {
        if (number)
          printf("%ld", lineno);
        printf("%s", line);
        found++;
      }
    }
  return found;
}