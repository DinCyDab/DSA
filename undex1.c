#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **vec;
    int m, n;
}matrix_st;

matrix_st initializeMatrix(int **A, int size, int row, int col) {
    matrix_st data;
    data.m = row;
    data.n = col;

    data.vec = (int **) calloc(row, sizeof(int *));

    int i = 0;
    for(i = 0; i < row; i++) {
        data.vec[i] = (int *) calloc(col,sizeof(int));
        memmove(data.vec[i], A[i], size);
    }

    return data;
}


int main(){
    int size = 2;
    int num[][size] = {
        {1,2},
        {3,4}
    };
    matrix_st lambda = initializeMatrix((int[]){1,2,3,4}, size*size, size, size);

    return 0;
}