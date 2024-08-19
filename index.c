#include <stdio.h>
#include <stdlib.h>

int main(){
    int answerField[4][4] = {
    //  0   1   2
        {-1, -1, 0, 0}, //  0 
        {0, 0, 0, 0}, //   1 
        {0, 0, 0, 0}, //    2
        {-1, 0, 0, 0}
    };

    int guessField[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    // while(1){
        int row = 3;
        int col = 1;

        if(answerField[row][col] == 0){
            int num = -1;
            for(int i = -1; answerField[row+i][col] == 0; i++){
                answerField[row+i][col] = 1;
            }
            //  for(int i = -1; answerField[row][col+i] == 0; i++){
            //     guessField[row+i][col] = 1;
            // }
        }
        else{
            //Game Over
        }

        //Print
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                printf("\t%d\t", guessField[i][j]);
            }
            printf("\n");
        }
    // }

    return 0;
}