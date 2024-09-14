/* разбивать строку на нескольно под строк меньшего размера удаляя ненудные табы и прбелы с конца*/

#include <stdio.h>

#define MAXLENGTH 100
#define STEP 10
#define IN 1
#define OUT 0

char line[MAXLENGTH];
char divided_line[MAXLENGTH];

int get_line();
void divider(int len);
int space_fix(int len);

int main(void)
{
  extern char line[], divided_line[];
  int len;
  int i;

  while ((len = get_line()) > 0)
  {
    len = space_fix(len);
    divider(len);
    printf("pre:%s\n", line);
    printf("pre:%s\n", divided_line);
  }

  return 0;
}

int get_line()
{
  extern char line[];
  int i, c;

  for (i = 0; i < MAXLENGTH; ++i)
    line[i] = 0;

  for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n')
  {
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';

  return i;
}

int space_fix(int len)
{
  extern char line[], divided_line[];
  int i, counter, state;

  for (i = 0; i < MAXLENGTH; ++i)
    divided_line[i] = 0;

  counter = 0;
  state = OUT;

  for (i = 0; i < len - 1; ++i)
  {
    if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
    {
      state = IN;
      divided_line[counter] = line[i];
      ++counter;
    }
    else if ((line[i] == ' ' || line[i] == '\t' || line[i] == '\n') && state == IN)
    {
      state = OUT;
      divided_line[counter] = line[i];
      ++counter;
    }
  }
  divided_line[counter] = '\0';
  for (i = 0; i < MAXLENGTH; ++i)
  {
    if (i <= counter)
      line[i] = divided_line[i];
    else
      line[i] = 0;
  }

  return counter;
}

void divider(int len)
{
  extern char line[], divided_line[];
  int i, state, counter;

  counter = 0;
  for (i = 0; i < len - 1; ++i)
  {
    if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
    {
      ++counter;
      divided_line[i] = line[i];
    }
    else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
    {
      if (counter >= STEP)
      {
        counter = 0;
        divided_line[i] = '\n';
      }
    }
  }
  /* разделить массив на каждый шаг
    если в месте раздела есть непустые символы, искать место до следущего пробела и непустого символа
    после разделения в конце строки не должно быть пробелов и в начале тоже
  */
}