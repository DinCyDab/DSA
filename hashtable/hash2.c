#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct node{
    char* value;
    struct node* next;
}*Node;

void initialize(Node hashtable[MAX]);
int getIndex(char* value);
void addIntoTable(Node hashtable[MAX], char* value, int index);
void printTable(Node hashtable[MAX]);
void freeTable(Node hashtable[MAX]);
Node add(Node head, char* value);
bool contains(Node hashtable[MAX], char* value);

int main(){
    int index;
    Node hashtable[MAX];
    initialize(hashtable);
    addIntoTable(hashtable, "Bob", getIndex("Bob"));
    addIntoTable(hashtable, "Adele", getIndex("Adele"));
    printf(contains(hashtable, "Adele") ? "True" : "False");
    printTable(hashtable);
    freeTable(hashtable);
    return 0;
}

bool contains(Node hashtable[MAX], char* value){
    Node current = hashtable[getIndex(value)];
    if(getIndex(value)){
        while(current != NULL){
            if(strcmp(current->value, value) == 0){
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

Node add(Node head, char* value){
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->value = (char*)malloc(sizeof(char) * strlen(value) + 1);
    strcpy(newNode->value, value);
    newNode->next = head;
    return newNode;
}

void addIntoTable(Node hashtable[MAX], char* value, int index){
    hashtable[index] = add(hashtable[index], value);
}

void freeTable(Node hashtable[MAX]){
    Node current;
    Node next = NULL;
    for(int i = 0; i < MAX; i++){
        current = hashtable[i];
        while(current != NULL){
            next = current->next;
            free(current->value);
            free(current);
            current = next;
        }
    }
}

void printTable(Node hashtable[MAX]){
    Node current = NULL;
    for(int i = 0; i < MAX; i++){
        printf("%d.)", i);
        current = hashtable[i];
        while(current != NULL){
            printf("[%s]->", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

int getIndex(char* value){
    int index = 0;
    for(int i = 0; i < strlen(value); i++){
        index += (int) value[i];
    }
    return index % 10;
}

void initialize(Node hashtable[MAX]){
    for(int i = 0; i < MAX; i++){
        hashtable[i] = NULL;
    }
}