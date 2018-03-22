#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MATRIX_SIZE 4

int main(void){
    char matrix[4][4] = {
        {'C','A','R','T'},
        {'E','T','A','K'},
        {'E','S','M','E'},
        {'L','L','P','N'}
    };
    int countwords = printWords(matrix);
    printf("count of words: %d\n",countwords);
    return 0;
}