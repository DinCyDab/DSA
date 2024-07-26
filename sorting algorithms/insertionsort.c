#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int* arr, int size);

int main(){
    srand(time(NULL));
    int size = 10;
    int* arr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
    insertionSort(arr, size);
    free(arr);
    return 0;
}

void insertionSort(int* arr, int size){
    // for(int i = 1; i < size; i++){
    //     for(int j = i; j > 0 && arr[j-1] > arr[j]; j--){
    //         int temp = arr[j-1];
    //         arr[j-1] = arr[j];
    //         arr[j] = temp;
    //     }
    // }

    for(int i = 1; i < size; i++){
        int currentValue = arr[i];
        int insertindex = i;
        int j = i - 1;
        for(; j >= 0 && currentValue < arr[j]; j--){
            arr[j+1] = arr[j];
            insertindex = j;
        }
        arr[insertindex] = currentValue;
    }

    for(int i = 0; i < size; i++){
        printf("|%d| ", arr[i]);
    }
}