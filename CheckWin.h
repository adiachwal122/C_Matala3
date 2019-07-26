#include <stdio.h>
#include <stdbool.h>

#define row 6
#define column 7
#define EMPTY ' '


bool winMainDiagonal(char mat[row][column], int turn){//incase of win \ 
    
    int j = 0; //columns
    int i = 0;
    int count  = 0;
    
    if (turn == 1){
        
        while(i < row && j < column){
            if (mat[i][j] == 'X'){
                count++;
                j++;
            }
            else {
                count = 0;
            }
            if(count == 4){
                printf("Player X wins!\n");
                exit(0);
            }
            i++;
            if (i == row-1 && count != 3){
                j++;
                i = 0;
            }
        }
    }
    
    else{
        while(i < row && j < column){
            if (mat[i][j] == 'O'){
                count++;
                j++;
            }
            else {
                count = 0;
            }
            if(count == 4){
                printf("Player O wins!\n");
                exit(0);
            }
            i++;
            if (i == row-1 && count != 3){
                j++;
                i = 0;
            }
        }
    }
    
    return false;
}

bool winSubDiagonal(char mat[row][column], int turn){//incase of win / 
   
    int j = 0; //columns
    int i = row-1;
    int count  = 0;
    
    if (turn == 1){
        while( i >= 0 && j < column ){
       
            if (mat[i][j] == 'X'){
                count++;
                j++;
            }
            else {
                count = 0;
            }
            if(count == 4){
                printf("Player X wins!\n");
                exit(0);
            }
            i--;
            if (i == 0 && count != 3){
                j++;
                i = row-1;
            }
        }
    }
    
    else{
        while( i >= 0 && j < column ){
            if (mat[i][j] == 'O'){
                count++;
                j++;
            }
            else {
                count = 0;
            }
            if(count == 4){
                printf("Player O wins!\n");
                exit(0);
            }
            i--;
            if (i == 0 && count != 3){
                j++;
                i = row-1;
            }
        }
    }
 return false;
}

bool winRow(char mat [row][column],int tRow, int turn){//check for possible row win

    if (turn == 0){
        int counter = 0;
        for(int i = 0; i <column; i++){
            if (mat[tRow][i]=='O'){
                counter++;
            }
            if (mat[tRow][i]!='O'){
                counter = 0;
            }
            if (counter == 4){
                printf("Player O wins!\n");
                exit(0);
            }
        }
    }
    else /*if (turn ==1)*/{
        int counter = 0;
        for(int i = 0; i <column; i++){
            if (mat[tRow][i]=='X'){
                counter++;
            }
            if (mat[tRow][i]!='X'){
                counter = 0;
            }
            if (counter == 4){
                printf("Player X wins!\n");
                exit(0);
            }
        }
    }
    return false;
}

bool winColumn(char mat [row][column],int tColumn, int turn){//check for possible column win
    if (turn == 0){
        int counter = 0;
        for(int i = 0; i <row; i++){
           
            if (mat[i][tColumn]=='O'){
                counter++;
            }
            if (mat[i][tColumn]!='O'){
                counter = 0;
            }
            if (counter == 4){
                printf("Player O wins!\n");
                exit(0);
            }
        }
    }
    else{
        int counter = 0;
        for(int i = 0; i <row; i++){
            if (mat[i][tColumn]=='X'){
                counter++;
            }
            if (mat[i][tColumn]!='X'){
                counter = 0;
            }
            if (counter == 4){
                printf("Player X wins!\n");
                exit(0);
            }
        }
    }
    return false;
}

bool fullMat(char mat[row][column]){//returns true if mat is full

    int i = 0;
    while(i < column){
        if(mat[0][i] != EMPTY){
            i++;
        }
        else return false;

    }
    if (i = column-1){
        return true;
    }
    else return false;
}
