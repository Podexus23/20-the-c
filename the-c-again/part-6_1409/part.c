#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IN 1
#define HASHSIZE 101

struct nlist
{
  struct nlist *next;
  char *name;
  char *defn;
};

static struct nlist *hashtab[HASHSIZE]; /* таблица указателей */
struct nlist *lookup(char *);
char *strdup(const char *);

int main(int argc, char **argv)
{
  return 0;
}

/* hash: формирования хэш кода для строки s */
unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

/* lookup: поиск элемента s в таблице hashtab */
struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np; /* эелемент найден */
  return NULL;   /* элемент не найден */
}

/* install: помещает запись "имя-определение" (name, defn) в таблицу hashtab */
struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) /* имя не найдено */
  {
    np = (struct nlist *)malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  }
  else                      /* уже есть в таблице */
    free((void *)np->defn); /* удаление старого определения */
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

void undef(char *name)
{
  struct nlist *list;
  struct nlist *prev_list = NULL;
  unsigned has_num = hash(name);

  {
    for (list = hashtab[has_num]; list != NULL; prev_list = list, list = list->next)
    {
      if (strcmp(list->name, name) == 0)
      {
        free(list->name);
        free(list->defn);

        if (prev_list == NULL)
        {
          hashtab[has_num] = list->next;
        }
        else
          prev_list->next = list->next;
      }

      free(list);
    }
  };
}

/* создание дубликата строки s */
char *strdup(const char *s)
{
  char *p;

  p = (char *)malloc(strlen(s) + 1); /* +1 для '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}