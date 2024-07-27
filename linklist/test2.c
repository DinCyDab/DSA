#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}*link;

link addList(link head, int value);
void freeList(link head);
void printList(link head);

int main(){
    link head = NULL;
    head = addList(head, 10);
    head = addList(head, 20);
    head = addList(head, 30);
    printList(head);
    freeList(head);
    return 0;
}

link addList(link head, int value){
    link newList = (link)malloc(sizeof(struct node));
    newList->data = value;
    newList->next = head;
    return newList;
}

void printList(link head){
    link current = head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

void freeList(link head){
    link current = head;
    link nextNode = NULL;
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}