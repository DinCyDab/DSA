#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int* arr, int size, int i);

int main(){
    srand(time(NULL));
    int size = 10;
    int* arr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
    bubbleSort(arr, size, 0);
    for(int i = 0; i < size; i++){
        printf("|%d| ", arr[i]);
    }
    free(arr);
    return 0;
    
}

void bubbleSort(int* arr, int size, int i){

    if(i < size - 1){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        bubbleSort(arr, size, i+1);
    }
}