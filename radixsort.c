#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define size 10
#define decimalsize 10
#define randomsize 100000000

int main(){
    srand(time(NULL));
    int arr[size];
    int radix[decimalsize][decimalsize];
    for(int i = 0; i < size; i++){
        arr[i] = rand() % randomsize;
    }

    for(int i = 0; i < decimalsize; i++){
        for(int j = 0; j < decimalsize; j++){
            radix[i][j] = -1;
        }
    }

    for(int i = 0; i < size; i++){
        printf("|%d| ", arr[i]);
    }
    printf("\n");
    
    int a = 10;
    int c = 0;
    int digits = (int)log10(randomsize);
    while(c < digits){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < decimalsize; j++){
                int k = 0;
                while(radix[j][k] != -1){
                    k++;
                }
                if(arr[i] % a/(a/10) == j){
                    radix[j][k] = arr[i];
                }
            }
        }

        int index = size - 1;
        for(int i = decimalsize - 1; i >= 0; i--){
            for(int j = decimalsize - 1; j >= 0; j--){
                if(radix[i][j] != -1){
                    arr[index] = radix[i][j];
                    radix[i][j] = -1;
                    index--;
                }
            }
        }
        c++;
        a*= 10;
    }
    for(int i = 0; i < size; i++){
        printf("|%d| ", arr[i]);
    }
    return 0;
}