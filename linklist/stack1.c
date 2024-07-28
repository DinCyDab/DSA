#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int arr_stack[MAX];
int top = -1;

void push(int value);
void printStack();
void pop();
bool isFull();
bool isEmpty();
void printTop();

int main(){
    int choice;
    while(1){
        printf("1.)Push a value\n");
        printf("2.)Pop a value\n");
        printf("3.)Check if Empty Stack\n");
        printf("4.)Check if Full Stack\n");
        printf("5.)Check Top Value\n");
        printf("6.)Exit\n\n");
        printStack();
        printf("Enter Your Choice:");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice){
            case 1:
                printf("Enter a value to add:");
                scanf("%d", &choice);
                push(choice);
                break;
            case 2:
                pop();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                printTop();
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Please choose a correct value\n");
                break;
        }
    }
    return 0;
}

void printTop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    printf("The top Value is: %d\n", arr_stack[top]);
}

bool isFull(){
    if(top >= MAX){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if(top <= -1){
        return true;
    }
    else{
        return false;
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    printf("Deleted: %d\n", arr_stack[top]);
    top--;
}

void push(int value){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    arr_stack[top] = value;
}

void printStack(){
    printf("Current Stack:\n");
    if(top == -1){
        printf("|____|\n");
        return;
    }
    for(int i = top; i >= 0; i--){
        printf("|_%d_|\n", arr_stack[i]);
    }
}