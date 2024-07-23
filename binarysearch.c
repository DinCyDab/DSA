#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* arr, int low, int high, int numToFind);

int main(){
    int size = 10;
    int* arr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    binarySearch(arr, 0, size-1, 9);
    free(arr);
    return 0;
}

int binarySearch(int* arr, int low, int high, int numToFind){
    if(high >= low){
        int mid = low + (high - low) / 2;
        if(arr[mid] == numToFind){
        printf("Number Has Been Found at index %d", mid);
        }
        else if(arr[mid] > numToFind){
            binarySearch(arr, low, mid-1, numToFind);
        }
        else{
            binarySearch(arr, mid+1, high, numToFind);
        }
    }
    return -1;
}