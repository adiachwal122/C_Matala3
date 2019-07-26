#include <stdio.h>
#include <stdbool.h>

#define row 6
#define column 7
#define EMPTY ' '

void initializeMat(char mat[row][column]){
     for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            mat[i][j] = EMPTY; 
        }
    } 
}

void printMat (char mat[row][column] ){
    for(int i = 0; i < row; i++){
        printf("|");
        for(int j = 0; j < column; j++){
            printf("%c|", mat[i][j]);  
        }
        printf("\n");
    }
    printf("_______________\n 1 2 3 4 5 6 7\n");
}