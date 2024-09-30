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
show moves+
make moves+

make players
check for win cindition
congrats player on win
or show draw
*/

/*
BUGS
player can take already checked place
*/

#include <stdio.h>

#define F_SIZE 3

enum
{
  X = 'X',
  O = 'O'
};

void print_field(void);
void clean_field(void);
void make_field(void);

void game_cycle(void);

int make_a_move(char);

int check_win_condition(void);

char field[F_SIZE][F_SIZE];

int main(void)
{
  make_field();
  print_field();
  game_cycle();
  // check_win_condition();
}

void print_field(void)
{
  printf("----------------------------\n");
  for (int i = 0; i < F_SIZE; i++)
  {
    for (int j = 0; j < F_SIZE; j++)
    {

      printf("|%c|", field[i][j]);
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

void make_field(void)
{
  for (int i = 0; i < F_SIZE; i++)
  {
    for (int j = 0; j < F_SIZE; j++)
    {
      field[i][j] = '-';
    }
  }
}

int make_a_move(char player_c)
{
  int x;
  int y;
  printf("Please enter coordsto make a move(str row):\n");
  scanf("%d %d", &x, &y);
  if ((x > F_SIZE || x < 0) || (y > F_SIZE || y < 0))
  {
    printf("move: sorry wrong coords, try somting more than 0, and less that %d\n", F_SIZE + 1);
    return make_a_move(player_c);
  }
  field[x - 1][y - 1] = player_c;
  return 0;
}

void game_cycle(void)
{
  int player_1 = X;
  int player_2 = O;
  int main_pl = player_1;
  int cond = 1;
  do
  {
    make_a_move(main_pl);
    cond = check_win_condition();
    if (cond != 0)
      main_pl = (main_pl == player_1) ? player_2 : player_1;
    print_field();
  } while (cond != 0);
  printf("Congrats player: %c\n", main_pl);
  /*
  player 1 make a move
  if move succesfull change player
  if not player 1 make a move
  check for win condition
  check draw condition

  another player make a move
  ...
  if someone win
  make a cingratulations print
  */
}

int check_win_condition(void)
{
  printf("checked\n");
  int beacon;
  int changed = 0;
  for (int i = 0; i < F_SIZE; i++)
  {
    if (i == 0)
      beacon = field[0][i];
    if (field[0][i] == beacon)
      continue;
    else
      changed++;
  }
  if (changed > 0)
  {
    printf("changed\n");
    return 1;
  }
  printf("check win: won cond!\n");
  return 0;
}