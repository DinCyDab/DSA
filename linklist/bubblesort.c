#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node* next;
}*Node;

void addList(Node* head, int value);
void freeList(Node head);
void printList(Node head);
Node bubbleSort(Node head);
void swap(int* a, int* b);

int main(){
    Node list = NULL;
    addList(&list, 20);
    addList(&list, 5);
    addList(&list, 4);
    bubbleSort(list);
    printList(list);
    freeList(list);
    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

Node bubbleSort(Node head){
    bool isSwap = true;
    Node current = head;
    Node next = NULL;
    Node prev = NULL;
    while(isSwap){
        isSwap = false;
        while(current->next != NULL){
            next = current->next;
            if(current->value > next->value){
                current->next = next->next;
                next->next = current;
                prev = next;
                isSwap = true;
            }
            if(!isSwap){
                prev = current;
            }
            current = current->next;
        }
    }
}

void addList(Node* head, int value){
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        Node trav = *head;
        while(trav->next != NULL){
            trav = trav->next;
        }
        trav->next = newNode;
    }
}

void printList(Node head){
    Node current = head;
    while(current != NULL){
        printf("%d->", current->value);
        current = current->next;
    }
}

void freeList(Node head){
    Node current = head;
    Node next = NULL;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}