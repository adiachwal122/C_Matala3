#include <stdio.h>
#include <stdbool.h>

#define row 6
#define column 7
#define EMPTY ' '

void putPlay(char mat [row][column] ,int play , int turn, int arr [42],int* tRow){
    
    int i = 0;
        
    if(play==0){
        doundo(mat,arr);
    }
    
    else{
        while(mat[i][play-1] == EMPTY && i<=row){
            i++;
        }
            
        if (turn == 0){
            mat[i-1][play-1] = 'O';
            *tRow = i-1;
        }
            
        else{
            mat[i-1][play-1] = 'X';
            *tRow = i-1;
        }
    }
}

int getInput(char mat[row][column], int play){//get the players choice

    if (scanf("%d", &play) != 1){
        char temp;
        scanf("%c",&temp);  
        if(temp == '.'){
            exit(0);
        }
        else{
            printf("Invalid input, bye-bye!\n");
            exit(0);
        }
    }
    
    else{
        if (play == 0){
            if(!undo(mat)){
                printf("Board is empty - can't undo!\n");
                return getInput(mat,play);
            }
            else return play;
        }
    
        else if (play < 0 || play > column){
            char temp;
            scanf("%c",&temp);
            if(temp == '.'){
                printf("Invalid input, bye-bye!\n");
                exit(0);
            }
            else{
                printf("Invalid input, the number must be between 1 to 7:\n");
                return getInput(mat,play);
            }
        }
    
        else if (mat[0][play-1] != EMPTY){
            printf("Invalid input, this column is full. Please choose another one:\n");
            return getInput(mat,play);
        }
    }
    return play;
}