#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

void radixSort(int* arr);
void printSort(int* arr);

int main(){
    srand(time(NULL));
    int arr[size];
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
    radixSort(arr);
    printSort(arr);
    return 0;
}

void radixSort(int* arr){
    int max_value = arr[0];
    for(int i = 0; i < size; i++){
        if(max_value < arr[i]){
            max_value = arr[i];
        }
    }

    int exp = 1;
    int radixArray[10][size];
    int count[10] = {0};
    while(max_value / exp > 0){
        //Put the unsorted to the bucket
        for(int i = 0; i < size; i++){
            int radixIndex = (arr[i] / exp) % 10;
            radixArray[radixIndex][count[radixIndex]] = arr[i];
            count[radixIndex]++;
        }

        //Put the bucket back to the array
        int pos = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < count[i]; j++){
                arr[pos] = radixArray[i][j]; 
                pos++;
            }
            count[i] = 0;
        }
        exp *= 10;
    }

}

void printSort(int* arr){
    for(int i = 0; i < size; i++){
        printf("|%d| ", arr[i]);
    }
}