#include <stdio.h>

void mergeSort(int* arr, int start, int end);
void merge(int* arr, int start, int mid, int end);

int main(){
    int arr[] = {3,4,2,1,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);

    for(int i = 0; i < size; i++){
        printf("%d->", arr[i]); 
    }

    return 0;
}

void mergeSort(int* arr, int start, int end){
    //Check if the start is still less than the end
    if(start < end){
        //Get the mid
        int mid = (start + end) / 2;
        //Call the mergeSort recursively
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        //Call the merge function to merge all of the divided function and sort it
        merge(arr, start, mid, end);
    }
}

void merge(int* arr, int start, int mid, int end){
    int i, j, k;
    //Get the size of the array
    int n1 = mid - start + 1;
    int n2 = end - mid;
    //initialize the array
    int L[n1];
    int R[n2];
    //Put the left and right array inside L[n1] and R[n2]
    for(i = 0; i < n1; i++){
        L[i] = arr[start + i];
    }
    for(i = 0; i < n2; i++){
        R[i] = arr[mid + i + 1];
    }
    //Reset the counters
    i = 0;
    j = 0;
    //let k be the starting point so that if the array starts at half we will go mid from the whole array with it
    k = start;
    //Put the divided arrays into group again
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //Put in the array on what's left inside the L side
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    //Put in the array on what's left inside the R side
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}