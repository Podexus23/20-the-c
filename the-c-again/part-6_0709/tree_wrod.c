#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode
{
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
char *strdup(const char *s);

/* программа подсчета частоты слов */

int main(void)
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  treeprint(root);
  return 0;
}

struct tnode *talloc(void);

/* addtree: добавление узла со словом w в узел p или ниже */
struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL)
  {
    p = talloc();
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  }
  else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);
  return p;
}

/* treeprint: вывод дерева p и алфаввином порядке */
void treeprint(struct tnode *p)
{
  if (p != NULL)
  {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

/* talloc: создание узла дерева типа tnode */
struct tnode *talloc(void)
{
  return (struct tnode *)malloc(sizeof(struct tnode));
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

/* getword: считывает очередное слово или символ из потока ввода со спец символами и нижним подчеркиванием */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c) && c != '#')
  {
    *w = '\0';
    return c;
  }

  for (; --lim > 0; w++)
  {
    *w = getch();
    if (!isalnum(*w) && *w != '_' && *w != '#')
    {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* буфер для ungetch */
int bufp = 0;      /* следующая свободная позиция в buf */

int getch(void) /* ввод символа, возможно возвращенного в поток */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* возвращение символа в поток */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}