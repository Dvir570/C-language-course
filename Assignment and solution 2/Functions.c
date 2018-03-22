#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MATRIX_SIZE 4

int i,j;

bool isWord(char* s){
		return (!strcmp(s,"CAT") |
			!strcmp(s,"CATS") |
			!strcmp(s,"TRAM") |
			!strcmp(s,"TRAMS") |
			!strcmp(s,"TAME") |
			!strcmp(s,"CAR") |
			!strcmp(s,"CARS") |
			!strcmp(s,"RAT") |
			!strcmp(s,"RATS") |
			!strcmp(s,"RAMP") |
			!strcmp(s,"ART") |
			!strcmp(s,"CART") |
			!strcmp(s,"STAMP") |
			!strcmp(s,"TAKEN") |
			!strcmp(s,"MEN") |
			!strcmp(s,"MAKE") |
			!strcmp(s,"TAKE") |
			!strcmp(s,"ATE") |
			!strcmp(s,"SELL") |
			!strcmp(s,"STEEL") |
			!strcmp(s,"RAKE") );
}

int addChar(char matrix[MATRIX_SIZE][MATRIX_SIZE], bool bmatrix[MATRIX_SIZE][MATRIX_SIZE],char* str){
    char newstr[5];
    char temp;
    int countwords=0;
    bmatrix[i][j]=false;
    temp = matrix[i][j];
    memcpy(newstr,str, strlen(str));
    newstr[strlen(str)] = temp;
    newstr[strlen(str)+1] = '\0';
    countwords+=findWord(matrix, bmatrix, newstr);
    bmatrix[i][j]=true;
    return countwords;
}

int findWord(char matrix[MATRIX_SIZE][MATRIX_SIZE], bool bmatrix[MATRIX_SIZE][MATRIX_SIZE], char* str){
    int countwords = 0;
    if(strlen(str)>2 && strlen(str)<6 && isWord(str)){
        printf("%s\n",str);
        countwords++;
    }

    if(strlen(str)<5){
        if(j!=3&&bmatrix[i][j+1]==true){
            j++;
            countwords+=addChar(matrix, bmatrix, str);
            j--;
        }
        if(j!=0&&bmatrix[i][j-1]==true){
            j--;
            countwords+=addChar(matrix, bmatrix, str);
            j++;
        }
        if(i!=3&&bmatrix[i+1][j]==true){
            i++;
            countwords+=addChar(matrix, bmatrix, str);
            i--;
        }
        if(i!=0&&bmatrix[i-1][j]==true){
            i--;
            countwords+=addChar(matrix, bmatrix, str);
            i++;
        }
    }
    return countwords;
}

int printWords(char matrix[MATRIX_SIZE][MATRIX_SIZE]){
    bool bmatrix[4][4] = {
        {true,true,true,true},
        {true,true,true,true},
        {true,true,true,true},
        {true,true,true,true}
    };
    int countwords =0;
    char temp;
    char str[5];
    memset( str, '\0', sizeof(str));
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            countwords+=addChar(matrix, bmatrix, str);
        }
    }
    return countwords;
}