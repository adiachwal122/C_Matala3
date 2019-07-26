#include <stdio.h>
#include <stdbool.h>
#include "CheckWin.h"
#include "Undo.h"
#include "Input.h"
#include "Matrix.h"


#define row 6
#define column 7
#define EMPTY ' '

void main() {
    
    printf("Welcome!\n");
    
    int turn = 1; //X turn
    int play = 0; //for index
    int count = 0; //to count until possible win
    bool win = true;
    //for undo
    int arr [42];
    for(int i = 0; i<42;i++){
        arr[i] = 0;
    }
    
   //to check for win
    int tRow = row-1;
    int tColumn = column-1; 

    char mat [row][column];
    initializeMat(mat);
    printMat(mat);
    
    while(win){
        
        if (turn == 1){//X turn
            printf("Player X, please enter a column number (or 0 to undo):\n");
            play = getInput(mat,play);
            undoArr(arr, play);
            putPlay(mat, play, turn, arr,&tRow);
            tColumn = play-1;
            count++;
            printMat(mat);
            if (count >= 7){
                winRow(mat,tRow,turn);
                winColumn(mat,tColumn,turn);
                winSubDiagonal(mat, turn);
                winMainDiagonal(mat, turn);
            }
            turn = 0;
        }
      
        if (turn == 0){ //O turn
            printf("Player O, please enter a column number (or 0 to undo):\n");
            play = getInput(mat,&play);
            undoArr(arr, play);
            putPlay(mat, play, turn, arr,&tRow);
            tColumn = play-1;
            count++;
            printMat(mat);
            if (count >= 7){
                winRow(mat,tRow,turn);
                winColumn(mat,tColumn,turn);
                winSubDiagonal(mat, turn);
                winMainDiagonal(mat, turn);
            }
            turn = 1;
        }
        
       if (fullMat(mat)){
            printf("It's a tie!\n");
            exit(0);
        }
        win = true;
    }
}