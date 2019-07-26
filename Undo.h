#include <stdio.h>
#include <stdbool.h>

#define row 6
#define column 7
#define EMPTY ' '

bool undo(char mat[row][column]){//cheks if u can undo, returns false if mat is empty and u cannot undo
    for (int i = 0; i < column; i++){
        if (mat[row-1][i] != EMPTY)
            return true;
    }
    return false;
}

void undoArr(int arr [42],int play){
    for(int i = 0; i<42;i++){
        if(arr[i] == 0){
            arr[i] = play;
            break;
        }
    }
}

int Array(int arr [42]){
    
    int i = 42;
    while(i<=42){
        if(arr[i] == 0)
            i--;
        else break;
    }
    
    int temp = arr[i];
    arr[i] = 0;
    return temp;
    
}

void doundo(char mat[row][column], int arr [42]){
    int t = Array(arr);
    int i = row;
    while(i<=row){
        if (mat[i][t-1] != EMPTY && i>=0)
        i--;
        else break;
        
    }
    mat[i+1][t-1] = EMPTY;
}
