#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

void swap(int* a, int* b);
void quicksort(int* arr, int low, int high);
int partition(int* arr, int low, int high);

int main(){
    srand(time(NULL));
    int* arr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) arr[i] = rand() % 100;
    quicksort(arr, 0, size-1);
    for(int i = 0; i < size; i++) printf("|%d| ", arr[i]);
    free(arr);
    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low;
    for(int j = low; j < high; j++){
        if(pivot > arr[j]){
            swap(&arr[j], &arr[i]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void quicksort(int* arr, int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, pivotIndex + 1, high);
        quicksort(arr, low, pivotIndex - 1);
    }
}