/**
 *
 * ### **Stage 7: Advanced Pointers (Pointer to Pointer)**
#### Topics:
- **Pointer to Pointer:**
  - Double pointers (pointer to pointer)
  - Pointers with multi-dimensional arrays
  - Pointer to functions

#### **Practice Project: Tic-Tac-Toe Game**
Write a tic-tac-toe game that uses a pointer to pointer (2D array) to manage the game board.
Allow two players to play and determine the winner.

 */

/*
  - Double pointers (pointer to pointer)
  - Pointers with multi-dimensional arrays
  - Pointer to functions
*/

/*
tic tac toe

make field+
renew field+

make players
make moves
show moves
check for win cindition
congrats player on win
or show draw
*/

/*

*/

#include <stdio.h>

#define F_SIZE 3

enum
{
  X = 1,
  O = 2
};

void print_field(void);
void clean_field(void);

int make_a_move(void);

int field[F_SIZE][F_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

int main(void)
{

  print_field();
  make_a_move();
  print_field();
}

void print_field(void)
{
  printf("----------------------------\n");
  for (int i = 0; i < F_SIZE; i++)
  {
    for (int j = 0; j < F_SIZE; j++)
    {

      printf("|%d|", field[i][j]);
    }
    printf("\n");
  }
}

void clean_field(void)
{
  for (int i = 0; i < F_SIZE; i++)
  {
    for (int j = 0; j < F_SIZE; j++)
    {
      field[i][j] = 0;
    }
  }
}

int make_a_move(void)
{
  int x;
  int y;
  printf("did you wash your ass today? please answer yes(y) or no(n)\n");
  scanf("%d %d", &x, &y);
  if ((x > F_SIZE && x < 0) || (y > F_SIZE && x < 0))
  {
    printf("move: sorry wrong coords, try somting more than 0, and less that %d\n", F_SIZE);
  }
  field[y - 1][x - 1] = 1;
  return 0;
}