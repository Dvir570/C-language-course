
#include <stdbool.h>
#define MATRIX_SIZE 4
bool isWord(char* s);
int addChar(char matrix[MATRIX_SIZE][MATRIX_SIZE], bool bmatrix[MATRIX_SIZE][MATRIX_SIZE],char* str);
int findWord(char matrix[MATRIX_SIZE][MATRIX_SIZE], bool bmatrix[MATRIX_SIZE][MATRIX_SIZE], char* str);
int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]);