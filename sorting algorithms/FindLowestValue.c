#include <stdio.h>
#include <stdlib.h>

void findMinValue(int* arr, int size);
void findMaxValue(int* arr, int size);

int main(){
    int* arr = (int*)malloc(sizeof(int) * 10);
    int i = 0;
    for(i; i < 10; i++){
        arr[i] = i;
    }
    int size = i;
    printf("%d", size);
    findMinValue(arr, 10);
    findMaxValue(arr, size);
    free(arr);
    return 0;
}

void findMinValue(int* arr, int size){
    int min = arr[0];
    for(int i = 0; i < size; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    printf("The Minimum Value is: %d\n", min);
}

void findMaxValue(int* arr, int size){
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    printf("The Maximum Value is: %d", max);
}