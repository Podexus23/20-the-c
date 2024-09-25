/*
  ### **Stage 5: Structures, Unions, and Enums**
  #### Topics:
  - **Structures:**
    - Defining and using `struct` to group data
    - Pointers to structures
  - **Unions:**
    - Understanding the difference between `struct` and `union`
  - **Enums:**
    - Declaring and using enumerations

  #### **Practice Project: Student Record System**
  Create a simple student management system using `struct`. The system should store student details (name, roll number, grades), allow the user to add, delete, or update student information.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SYS_SIZE 100
#define NAME_SIZE 20

union Grade
{
  int i;
  char c;
};

struct grades
{
  union Grade math;
  union Grade lang;
};

struct student
{
  char name[NAME_SIZE];
  int id;
  struct grades grades;
};

struct student library[SYS_SIZE];
int lbr_i = 0;

void add_student(char *name, int id, int math, int lang);
void update_student(char *name, int id, int math, int lang);
void print_data(void);
struct student *search_student(int id);
void remove_student(int id);

int main(int argc, char **argv)
{

  add_student("Josh", 123, 5, 4);
  add_student("Jack", 3, 1, 4);
  update_student("Josh", 55, 3, 4);
  add_student("Dimon", 1233, 5, 4);
  add_student("Dimon", 31, 5, 4);
  remove_student(66);
  print_data();

  return 0;
}

void add_student(char *name, int id, int math, int lang)
{
  if (lbr_i < SYS_SIZE - 1)
  {
    library[lbr_i].id = (lbr_i + 5) * 11;
    strcpy(library[lbr_i].name, name);
    library[lbr_i].grades.math.i = math;
    library[lbr_i].grades.lang.i = lang;
    lbr_i++;
  }
}

void update_student(char *name, int id, int math, int lang)
{
  if (search_student(id) != NULL)
  {
    struct student *n1 = search_student(id);
    strcpy(n1->name, name);
    n1->grades.math.i = math;
    n1->grades.lang.i = lang;
  }
}

void remove_student(int id)
{
  struct student *n1 = search_student(id);
  if (n1 != NULL)
  {
    n1->id = library[lbr_i - 1].id;
    strcpy(n1->name, library[lbr_i - 1].name);
    n1->grades.math = library[lbr_i - 1].grades.math;
    n1->grades.lang = library[lbr_i - 1].grades.lang;
    lbr_i--;
  }
}

void print_data(void)
{
  for (int i = 0; i < lbr_i; i++)
  {
    struct student n1 = library[i];

    // printf("Student: %s\n ID: %d\n Grades:\n  Math: %d\n  Lang: %d\n", n1.name, n1.id, n1.grades.math, n1.grades.lang);
    printf("Student: %s\n ID: %d\n", n1.name, n1.id);
  }
}

struct student *search_student(int id)
{
  for (int i = 0; i < lbr_i; i++)
  {
    struct student n1 = library[i];
    if (n1.id != id)
      continue;
    else
    {

      return &library[i];
    }
  }
  return NULL;
}