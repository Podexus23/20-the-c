/* считывать текст  программы на С
  выводить в алфавитном порядке каждую группу имен переменных
  которые совпадают по первым шести символам но могут отличатся дальше
  не принимать во внимание слова внутри строк и комментариев
  сделать число 6 возможным вводить как параметр для коммандной строки
*/

/* gcc main.c remove.c && ./a.out 4 */
/* программа считывания имен(переменных) и сортировки по n-символам */
// добавить считывание переменных

/*
  - определение переменных(пока наверное мимо)

  - игнорирование комментариев +
  - игнорирование кавычек +
  - функция считывающая слова+
  - массив для упаковки слов+
  - массив с указателями на слова+
  - структура для групп слов по определенному параметру+

  - сортировка групп по алфавиту
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAXWORD 1000   /* количество слов или групп слов?*/
#define WORDSIZE 100   /* размер слова */
#define LINESIZE 10000 /* количество символов в потоке */
#define ON 1
#define OFF 0

// IMPORT
char *
remove_comm(int comm, int br);                      // remove.c
char *remove_comm_arr(int comm, int br, char *arr); // remove.c remove_comm_arr(ON, ON, text2);

/* общие данные */
struct word_gr
{
  char name[WORDSIZE];
  int count;
  char *words[MAXWORD];
};

char stream[LINESIZE];          /* хранилище всего текста */
char words[MAXWORD][WORDSIZE];  /* хранилище слов */
char *words_pnt[LINESIZE];      /* указатели на строки */
int wrd_i = 0;                  /* количество слов*/
struct word_gr groups[MAXWORD]; /* хранилище групп*/
int grp_i = 0;                  /*счетчик групп*/

char *
getword(char *, char *, int);
char *add_word(char *w, char *arr);
void write_words(char *arr[]);
int sort_count = 2; /* параметр количества букв для сортировки */

void add_group(char *, struct word_gr arr[]);
void sort_gr(struct word_gr arr[]);
void write_groups(struct word_gr arr[]);

int main(int argc, char **argv)
{
  char c;
  char *p;
  int i = 0;

  if (argc > 1 && atoi(argv[1]) > 0)
    sort_count = atoi(argv[1]);

  /*засовываем свесь текст в 1 массив*/
  while ((c = getchar()) != EOF)
    stream[i++] = c;
  stream[i] = '\0';

  remove_comm_arr(ON, ON, stream);
  p = stream;
  for (; *p != '\0'; p++)
  {
    if (isspace(*p)) /* пропускаем пробелы */
      continue;
    if (!isalnum(*p)) /* пропускаем все спецсимволы */
      continue;

    /* набираем слово */
    if (isalpha(*p))
    {
      char word[WORDSIZE];
      p = getword(p, word, WORDSIZE);
      add_word(word, words[wrd_i]);
      add_group(words_pnt[wrd_i], groups);
      wrd_i++;
    }
  }

  // write_words(words_pnt);
  sort_gr(groups);
  write_groups(groups);
  return 0;
}

/* getword: берет указатель, из массива, указатель на массив для сохранения и макс длину слова */
char *getword(char *word, char *dest, int max_len)
{
  char *w = word;
  int i = 0;
  while ((isalnum(*w) || *w == '_') && i < max_len - 1)
  {
    *(dest++) = *(w++);
    i++;
  }
  *dest = '\0';

  return w;
}

char *add_word(char *word, char *arr)
{
  /* копирую указатель в двумерный массив, пытаясь выделить отдельную память под каждое слово*/
  char *start = arr;
  words_pnt[wrd_i] = start;
  strcpy(start, word);

  return start + strlen(word);
}

/* add_group: если группа есть, добавляет слова в неё, если нет, добавляет группу */
//! можно написать и по лучше... но кто жто будет делать, я устал, я мухожук)
void add_group(char *word, struct word_gr arr[])
{
  if (grp_i > 0)
  {
    int i;
    for (i = 0; i < grp_i; i++)
    {
      char *gr_name = groups[i].name;
      if (strncmp(word, gr_name, sort_count) == 0)
      {
        int c = arr[i].count;
        arr[i].words[c] = word;
        arr[i].count++;
        break;
      }
      else if (i == grp_i - 1)
      {
        strncpy(arr[grp_i].name, word, sort_count);
        int c = arr[grp_i].count = 0;
        arr[grp_i].words[c] = word;
        arr[grp_i].count++;
        grp_i++;
        break;
      }
    }
  }
  else
  {
    strncpy(arr[grp_i].name, word, sort_count);
    int c = arr[grp_i].count = 0;
    arr[grp_i].words[c] = word;
    arr[grp_i].count++;
    grp_i++;
  }
}

/* write_words: читает слова из указателей*/
void write_words(char *arr[])
{
  int i = 0;
  while (i < wrd_i)
    printf("write_words: %s\n", arr[i++]);
  printf("Words: %d\n", wrd_i);
}

void write_groups(struct word_gr arr[])
{
  int i = 0;
  while (i < grp_i)
  {
    printf("Group name: %s\n  Group words:", arr[i].name);
    int c = 0;
    while (c < arr[i].count)
    {
      printf(" %s,", arr[i].words[c++]);
    }
    printf("\n");
    i++;
  }
}
/* как имена переменных определяем что-то что идет после int char void double struct */
/* не плохо бы выделять отдельно названные strruckt */

void sort_gr(struct word_gr arr[])
{
  int n = grp_i;
  int swapped = 0;
  do
  {
    swapped = 0;
    for (int i = 1; i < n; i++)
    {
      if (strcmp(arr[i - 1].name, arr[i].name) > 0)
      {
        struct word_gr temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
        swapped = 1;
      }
    }
  } while (swapped != 0);
}