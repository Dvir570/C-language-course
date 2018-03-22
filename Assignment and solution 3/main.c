#include <stdio.h>
#include <string.h>
#include "game_logic.h"
#define COLUMNS_BOARD 7
#define ROWS_BOARD 6

char board[ROWS_BOARD][COLUMNS_BOARD];
struct place operations[42];
int countOfOperations = -1;

int main(){
    memset(board, ' ', sizeof(board));
    memset(operations, '\0', sizeof(operations));
    printf("Welcome!\n");
    printBoard(board);
    bool flag = true;
    while(countOfOperations<41){
        if(flag){
            printf("Player %c, please enter a column number (or 0 to undo):\n", 'X');
            turn('X', board, operations, &countOfOperations);
            flag = false;
            if(countOfOperations != -1 && checkWin(board, operations[countOfOperations])){
                break;
            }
        }
        else{
            printf("Player %c, please enter a column number (or 0 to undo):\n", 'O');
            turn('O', board, operations, &countOfOperations);
            flag = true;
            if(countOfOperations != -1 && checkWin(board, operations[countOfOperations])){
                break;
            }
        }
    }
    if(countOfOperations == 41)
        printf("It's a tie!\n");
}