#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int arr_stack[MAX];
int top = -1;

void push();
void printStack();
void pop();
void isFull();
void isEmpty();
void printTop();

int main(){
    int choice;
    while(1){
        choice = 10;
        system("cls");
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
                push();
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
                system("pause");
                break;
        }
    }
    return 0;
}

void printTop(){
    if(top <= -1){
        printf("Stack Underflow\n");
        system("pause");
        return;
    }
    printf("The top Value is: %d\n", arr_stack[top]);
    system("pause");
}

void isFull(){
    if(top >= MAX){
        printf("Stack is Full\n");
    }
    else{
        printf("Stack is not Full\n");
    }
    system("pause");
}

void isEmpty(){
    if(top <= -1){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is not Empty\n");
    }
    system("pause");
}

void pop(){
    if(top <= -1){
        printf("Stack Underflow\n");
        system("pause");
        return;
    }
    printf("Deleted: %d\n", arr_stack[top]);
    system("pause");
    top--;
}

void push(){
    if(top >= MAX){
        printf("Stack Overflow\n");
        system("pause");
        return;
    }
    int value;
    bool input;
    printf("Enter Value to Add:");
    input = scanf("%d", &value);
    fflush(stdin);
    if(input){
        top++;
        arr_stack[top] = value;
    }
    else{
        printf("Please enter a number\n");
        system("pause");
    }
}

void printStack(){
    printf("Current Stack:\n");
    for(int i = 0; i < MAX - top; i++){
        printf("|____|\n");
    }
    for(int i = top; i >= 0; i--){
        printf("|_%d_|\n", arr_stack[i]);
    }
}