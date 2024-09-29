#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 5
#define MAX_TASK 100
#define FILE_NAME "task.txt"

struct task
{
  int id;
  char task[50];
};
struct task tasks[MAX_SIZE];
static int tasks_i = 0;

/*
как оределять количсетво заданий?
записывать число в начале побитово,
и потом ставить указатель для вычета всех заданий ?
save tasks +
delete tasks +
modify tasks +
print tasks +

save task to file +
read file with tasks +
*/
int add_task(void);
int mod_task(int id);
void remove_task(int id);
void update_file(char *filename);
void show_tasks(void);
void load_file(char *filename);
struct task *search_task(int id);

void clean_str_end(char *str);
void print_task(struct task *t);

int main(int argc, char **argv)
{
  char *file = "task.txt";

  load_file(FILE_NAME);
  show_tasks();
  mod_task(2421);
  show_tasks();

  return 0;
}

// add remove delete search tasks
int add_task()
{
  char line[MAX_TASK];
  time_t now = time(NULL);
  int id = now % 10000;

  if (tasks_i >= MAX_SIZE)
  {
    printf("add_task: sorry to much tasks\n");
    return 1;
  }

  fgets(line, MAX_TASK, stdin);
  clean_str_end(line);
  strcpy(tasks[tasks_i].task, line);
  tasks[tasks_i].id = id;
  tasks_i++;
  update_file(FILE_NAME);
  return 0;
}

struct task *search_task(int id)
{
  for (int i = 0; i < tasks_i; i++)
  {
    if (tasks[i].id == id)
    {
      return &tasks[i];
    }
  }
  return NULL;
}

void remove_task(int id)
{
  struct task *t = search_task(id);
  if (t != NULL)
  {
    strcpy(t->task, tasks[tasks_i - 1].task);
    t->id = tasks[tasks_i - 1].id;
    tasks_i--;
    update_file(FILE_NAME);
  }
  else
    printf("sorry task not found\n");
}

int mod_task(int id)
{
  char line[MAX_TASK];
  struct task *t = search_task(id);

  if (t != NULL)
  {
    fgets(line, MAX_TASK, stdin);
    clean_str_end(line);
    strcpy(t->task, line);
    update_file(FILE_NAME);
    return 0;
  }
  else
  {
    printf("sorry task not found\n");
    return 1;
  }
}
// Work with file
void update_file(char *filename)
{
  char line[MAX_TASK];
  FILE *fp = fopen(filename, "w");

  fwrite(tasks, sizeof(struct task), tasks_i, fp);

  fclose(fp);
}

void load_file(char *filename)
{
  FILE *fp = fopen(filename, "r");
  int i = 0;

  i = fread(tasks, sizeof(struct task), MAX_SIZE, fp);
  if (i < 1)
    printf("No tasks in file\n");
  else
  {
    printf("Tasks found: %d\n", i);
    tasks_i = i;
  }

  fclose(fp);
}

// TASK VISUALISATION
void show_tasks(void)
{
  printf("All tasks:\n");
  for (int i = 0; i < tasks_i; i++)
  {
    printf("%d. %s. ID: %d\n", i + 1, tasks[i].task, tasks[i].id);
  }
}

void print_task(struct task *t)
{
  printf("ID: %d. Task: %s\n", t->id, t->task);
}

void clean_str_end(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  if (str[i - 1] == '\n')
    str[i - 1] = '\0';
}