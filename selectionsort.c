#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int* arr, int size);

int main(){
    srand(time(NULL));
    int size = 10;
    int* arr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
    selectionSort(arr, size);
    free(arr);
    return 0;
}

void selectionSort(int* arr, int size){
    int temp;
    for(int i = 0; i < size-1; i++){
        int minVal = i;
        for(int j = i+1; j < size; j++){
            if(arr[minVal] > arr[j]){
                minVal = j;
            }
        }
        if(minVal != arr[i]){
            temp = arr[minVal];
            arr[minVal] = arr[i];
            arr[i] = temp;
        }
    }

    for(int i = 0; i < size; i++){
        printf("|%d|\t", arr[i]);
    }
}