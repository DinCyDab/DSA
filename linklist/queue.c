#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 4
#define ERROR -1

int arr[MAX];
int size = -1;

int enqueue(int value);
int dequeue();
int peek();
int isEmpty();
int sizeOf();
void printQueue();

int main(){
    int data, choice;
    bool isInt;
    while(1){
        system("cls");
        printf("1.)Enqueue\n");
        printf("2.)Dequeue\n");
        printf("3.)Peek\n");
        printf("4.)Check if the queue is Empty\n");
        printf("5.)Check the size of the queue\n");
        printf("6.)Exit\n");
        printQueue();
        printf("Enter your choice: ");
        fflush(stdin);
        isInt = scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter your number value: ");
                scanf("%d", &data);
                data = enqueue(data);
                if(data != -1){
                    printf("Added: %d SUCCESSFULLY\n", data);
                }
                else{
                    printf("Adding a value is UNSUCCESSFUL\n", data);
                }
                break;
            case 2:
                data = dequeue();
                if(data != -1){
                    printf("Dequeued Value: %d\n", data);
                }
                else{
                    printf("Empty Queue\n");
                }
                break;
            case 3:
                data = peek();
                if(data != -1){
                    printf("Peek Value: %d\n", data);
                }
                else{
                    printf("Empty Queue\n");
                }
                break;
            case 4:
                data = isEmpty();
                if(data){
                    printf("Queue is not Empty\n");
                }
                else{
                    printf("Queue is Empty\n");
                }
                break;
            case 5:
                data = sizeOf();
                printf("Size of queue: %d\n", data);
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Please choose a right choice\n");
                break;
        }
        system("pause");
    }
    return 0;
}

int isEmpty(){
    if(size > -1){
        return 1;
    }
    else{
        return 0;
    }
}

int sizeOf(){
    return size + 1;
}

int peek(){
    if(size == -1){
        return ERROR;
    }
    return arr[0];
}

int dequeue(){
    if(size == -1){
        return ERROR;
    }
    int data = arr[0];
    for(int i = 0; i < size; i++){
        arr[i] = arr[i+1];
    }
    size--;
    return data;
}

int enqueue(int value){
    if(size >= MAX){
        return ERROR;
    }
    size++;
    arr[size] = value;
    return value;
}

void printQueue(){
    printf("Current Queue\n");
    for(int i = 0; i <= size; i++){
        printf("%d ", arr[i]);
    }
    for(int i = 0; i < MAX - size; i++){
        printf("_ ");
    }
    printf("\n");
}