#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b);
void quickSort(int* arr, int low, int high);
int partition(int* arr, int low, int high);
void printSort(int* arr, int size);

int main(){
    srand(time(NULL));
    int size = 10;
    int* arr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
    printSort(arr, 10);
    quickSort(arr, 0, size - 1);
    free(arr);
    return 0;
}

void quickSort(int* arr, int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printSort(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("|%d| ", arr[i]);
    }
    printf("\n");
}

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[high], &arr[i+1]);
    printSort(arr, 10);
    return i + 1;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}