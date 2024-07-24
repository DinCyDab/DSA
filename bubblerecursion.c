#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int* arr, int size, int i);
void swap(int* a, int* b);

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
                swap(&arr[j], &arr[j+1]);
            }
        }
        bubbleSort(arr, size, i+1);
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}