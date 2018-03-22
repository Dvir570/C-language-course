#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define COLUMNS_BOARD 7
#define ROWS_BOARD 6
struct place {int row; int column;};

void printBoard(char board[ROWS_BOARD][COLUMNS_BOARD]){
    int i, j;
    for(i = 0;i<ROWS_BOARD;i++){
        for(j = 0;j<COLUMNS_BOARD;j++){
            printf("|%c", (char)board[i][j]);
        }
        printf("|\n");
    }
    for(j=1;j<=COLUMNS_BOARD;j++){
        printf(" %d", j);
    }
    printf("\n");
}

bool checkWin(char board[ROWS_BOARD][COLUMNS_BOARD], struct place lastTurn){
    //row
    int sequence = 1;
    char player;
    memcpy(&player, &board[lastTurn.row][lastTurn.column], 1);
    struct place pivot;
    //right
    pivot.row = lastTurn.row;
    pivot.column = lastTurn.column + 1;
    while(sequence!=4 && pivot.column<COLUMNS_BOARD && board[pivot.row][pivot.column] == player){
        sequence++;
        pivot.column+=1;
    }
    //left
    pivot.row = lastTurn.row;
    pivot.column = lastTurn.column - 1;
    while(sequence!=4 && pivot.column>=0 && board[pivot.row][pivot.column] == player){
        sequence++;
        pivot.column--;
    }
    if(sequence == 4){
       printf("Player %c wins!\n", player);
       return true;  
    } 
    //column
    sequence = 1;
    //down
    pivot.row = lastTurn.row + 1;
    pivot.column = lastTurn.column;
    while(sequence!=4 && pivot.row<ROWS_BOARD && board[pivot.row][pivot.column] == player){
        sequence++;
        pivot.row++;
    }
    if(sequence == 4){
       printf("Player %c wins!\n", player);
       return true;  
    } 
    //slant one
    sequence = 1;
    pivot.row = lastTurn.row - 1;
    pivot.column = lastTurn.column - 1;
    while(sequence!=4 && pivot.row>=0 && pivot.column>=0 && board[pivot.row][pivot.column] == player){
        sequence++;
        pivot.row--;
        pivot.column--;
    }
    pivot.row = lastTurn.row + 1;
    pivot.column = lastTurn.column + 1;
    while(sequence!=4 && pivot.row<ROWS_BOARD && pivot.column<COLUMNS_BOARD && board[pivot.row][pivot.column] == player){
        sequence++;
        pivot.row++;
        pivot.column++;
    }
    if(sequence == 4){
       printf("Player %c wins!\n", player);
       return true;  
    }
    //slant two
    sequence = 1;
    pivot.row = lastTurn.row - 1;
    pivot.column = lastTurn.column + 1;
    while(sequence!=4 && pivot.row>=0 && pivot.column<COLUMNS_BOARD && board[pivot.row][pivot.column] == player){
        sequence++;
        pivot.row--;
        pivot.column++;
    }
    pivot.row = lastTurn.row + 1;
    pivot.column = lastTurn.column - 1;
    while(sequence!=4 && pivot.row<ROWS_BOARD && pivot.column>=0 && board[pivot.row][pivot.column] == player){
        sequence++;
        pivot.row++;
        pivot.column--;
    }
    if(sequence == 4){
       printf("Player %c wins!\n", player); 
       return true;  
    }
    return false;
}


void turn(char player, char board[ROWS_BOARD][COLUMNS_BOARD],struct place operations[42], int *countOfOperations){
    struct place p;
    int column;
    int input = scanf("%d", &column);
    if(input!=1){
        printf("Invalid input, bye-bye!\n");
        exit(1);
    }
    while(column>7 || column<0 || (column==0 && *countOfOperations ==-1) || (column!=0 && board[0][column-1] != ' ')){
        printBoard(board);
        if(column>7 || column<0){
            printf("Invalid input, the number must be between 1 to 7:\n");
        }
        else if(column==0 && *countOfOperations ==-1){
            printf("Board is empty - can't undo!\n");
        }
        else if (board[0][column-1] != ' '){
            printf("Invalid input, this column is full. Please choose another one:\n");
        }
        input = scanf("%d", &column);
        if(input!=1){
            printf("Invalid input, bye-bye!\n");
            exit(1);
        }
    }
    if(column == 0 && *countOfOperations != -1){
        memcpy(&p, &operations[*countOfOperations], sizeof(operations[*countOfOperations]));
        board[p.row][p.column]= ' ';
        memset(&operations[*countOfOperations], '\0', sizeof(operations[*countOfOperations]));
        *countOfOperations-=1;
        printBoard(board);
        return;
    }
    int i;
    for(i = ROWS_BOARD;i>0;i--){
        if(board[i-1][column-1] == ' '){
            memcpy(&board[i-1][column-1], &player, 1);
            *countOfOperations+=1;
            p.row = i-1;
            p.column = column-1;
            memcpy(&operations[*countOfOperations], &p, sizeof(p));
            printBoard(board);
            return;
        }
    }
}