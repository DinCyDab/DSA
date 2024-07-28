#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}*link;

void printList(link head);
void printTail(link tail);
void freeList(link head);
link addList(link head, int value);
link findTail(link head);

int main(){
    link head = NULL;
    link tail = NULL;
    head = addList(head, 1);
    head = addList(head, 2);
    head = addList(head, 3);
    head = addList(head, 4);
    head = addList(head, 5);
    head = addList(head, 6);
    tail = findTail(head);
    printList(head);
    printf("\n");
    printTail(tail);
    freeList(head);
    return 0;
}

void printTail(link tail){
    link current = tail;
    while(current != NULL){
        printf("%d->", current->data);
        current = current->prev;
    }
}

link findTail(link head){
    link current = head;
    while(current->next != NULL){
        current = current->next;
    }
    return current;
}

link addList(link head, int value){
    link newList = (link)malloc(sizeof(struct node));
    newList->data = value;
    newList->next = head;
    newList->prev = NULL;
    if(head != NULL){
        head->prev = newList;
    }
    return newList;
}

void printList(link head){
    link current = head;
    while(current != NULL){
        printf("%d->", current->data);
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