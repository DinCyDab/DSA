#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* arr, int start, int end);
void merge(int* arr, int start, int mid, int end);

int main(){
    int arr[] = {4,2,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    for(int i = 0; i < size; i++){
        printf("%d->", arr[i]);
    }
    return 0;
}

void mergeSort(int* arr, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int* arr, int start, int mid, int end){
    int i, j, k;
    
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[start + i]; 
    }

    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + i + 1];
    }

    i = 0;
    j = 0;
    k = start;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j < n2){
        arr[k++] = R[j++];
    }
}