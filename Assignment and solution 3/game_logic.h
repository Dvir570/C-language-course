#include <stdbool.h>
#include "game_logic.c"
#define COLUMNS_BOARD 7
#define ROWS_BOARD 6
struct place;

void printBoard(char board[ROWS_BOARD][COLUMNS_BOARD]);

bool checkWin(char board[ROWS_BOARD][COLUMNS_BOARD], struct place lastTurn);

void turn(char player, char board[ROWS_BOARD][COLUMNS_BOARD],struct place operations[42], int *countOfOperations);

