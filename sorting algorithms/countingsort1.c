#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

void swap(int* a, int* b);
void countingSort(int* arr);

int main(){
    srand(time(NULL));
    int* arr = (int*)malloc(sizeof(int) * 10);
    for(int i = 0; i < size; i++) arr[i] = rand() % 100;
    countingSort(arr);
    for(int i = 0; i < size; i++) printf("|%d| ", arr[i]);
    free(arr);
    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void countingSort(int* arr){
    int max_value = arr[0];
    for(int i = 0; i < size; i++){
        if(max_value < arr[i]){
            max_value = arr[i];
        }
    }

    max_value++;
    int count[max_value];
    for(int i = 0; i < max_value; i++){
        count[i] = 0;
    }

    for(int i = 0; i < size; i++){
        count[arr[i]]++;
    }

    int index = 0;
    for(int i = 0; i < max_value; i++){
        while(count[i] > 0){
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}