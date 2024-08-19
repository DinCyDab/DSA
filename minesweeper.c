#include <stdio.h>
#include <stdlib.h>

#define BF_MAX 5

void printMine(char mine_field[BF_MAX][BF_MAX]);
void countProx(char mine_field[BF_MAX][BF_MAX], char guess_field[BF_MAX][BF_MAX]);
void putGuessField(char mine_field[BF_MAX][BF_MAX], char guess_field[BF_MAX][BF_MAX], int row, int col);

int main(){
    char mine_field[BF_MAX][BF_MAX] = {
        {'0', '0', '0', '0', '0'},
        {'0', 'B', 'B', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    char guess_field[BF_MAX][BF_MAX] = {
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'} 
    };

    countProx(mine_field, guess_field);
    printMine(guess_field);
    return 0;
}

void countProx(char mine_field[BF_MAX][BF_MAX], char guess_field[BF_MAX][BF_MAX]){
    for(int row = 0; row < BF_MAX; row++){
        for(int col = 0; col < BF_MAX; col++){
            if(mine_field[row][col] == 'B'){
                putGuessField(mine_field, guess_field, row, col);
            }
        }
    }
}

void putGuessField(char mine_field[BF_MAX][BF_MAX], char guess_field[BF_MAX][BF_MAX], int row, int col){
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(mine_field[row+i][col+j] == 'B'){
                continue;
            }

            if(guess_field[row+i][col+j] != '-'){
                guess_field[row+i][col+j]++;
            }
            else{
                guess_field[row+i][col+j] = '1';
            }
        }                   
    }
}

void printMine(char mine_field[BF_MAX][BF_MAX]){
    for(int i = 0; i < BF_MAX; i++){
        for(int j = 0; j < BF_MAX; j++){
            printf("[%c]", mine_field[i][j]);
        }
        printf("\n");
    }
}