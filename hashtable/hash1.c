#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10


int getIndex(char* value);
void printTable(char hashtable[MAX][MAX]);
void initialize(char hashtable[MAX][MAX]);

int main(){
    char hashtable[MAX][MAX];
    char input[MAX];
    int index;
    int choice;
    initialize(hashtable);
    while(1){
        system("cls");
        printf("1.)Add\n");
        printf("2.)Exit\n");
        printTable(hashtable);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Input: ");
                scanf("%s", &input);
                index = getIndex(input);
                strcpy(hashtable[index], input);
                break;
            case 3:
                exit(1);
                break;
            default:
                break;
        }
    }
    return 0;
}

int getIndex(char* value){
    int sum = 0;
    for(int i = 0; i < strlen(value); i++){
        sum += (int) value[i];
    }
    return sum % 10;
}

void printTable(char hashtable[MAX][MAX]){
    printf("Current Table:\n");
    for(int i = 0; i < MAX; i++){
        printf("%d.) %s\n", i, hashtable[i]);
    }
}

void initialize(char hashtable[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        strcpy(hashtable[i], "\0");
    }
}