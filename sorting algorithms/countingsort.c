#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

void countsort(int* arr);

int main(){
    srand(time(NULL));
    int arr[size];
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 5;
        printf("%d, ", arr[i]);
    }
    printf("\n");
    countsort(arr);
    for(int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}

void countsort(int* arr){
    int max_value = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max_value){
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
            arr[index++] = i;
            count[i]--;
        }
    }
}