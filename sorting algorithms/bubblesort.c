#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void bubbleSort(int* arr, int size);

int main(){
    int size = 10;
    int* arr = (int*)malloc(sizeof(int) * size);
    int i = 0;
    for(i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
    bubbleSort(arr, size);
    free(arr);
    return 0;
}

void bubbleSort(int* arr, int size){
    int temp;
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
}