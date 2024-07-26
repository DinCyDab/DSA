#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}list;

list* addList(list* head, int value);
list* deleteList(list* head, int value);
list* insertList(list* head, int pos, int value);
void printList(list* head);
void freeList(list* head);


int main(){
    list* head = NULL;
    head = addList(head, 1);
    head = addList(head, 2);
    head = addList(head, 4);
    head = addList(head, 5);
    printList(head);
    // printf("\n");
    // head = deleteList(head, 1);
    // printList(head);
    printf("\n");
    head = insertList(head, 3, 3);
    head = insertList(head, 1, 7);
    head = insertList(head, 20, 10);
    printList(head);
    freeList(head);
    return 0;
}

list* insertList(list* head, int pos, int value){
    int counter = 1;
    list* newList = (list*)malloc(sizeof(list));
    list* current = head;
    list* prev = NULL;
    newList->data = value;
    while(counter < pos && current != NULL){
        prev = current;
        current = current->next;
        counter++;
    }
    if(prev == NULL){
        prev = newList;
        newList->next = head;
        return prev;
    }
    else{
        prev->next = newList;
        newList->next = current;
    }
    return head;
}

list* deleteList(list* head, int value){
    list* current = head;
    list* prev = NULL;
    while(current != NULL && current->data != value){
        prev = current;
        current = current->next;
    }
    if(prev == NULL){
        prev = head->next;
    }
    else{
        prev->next = current->next;
    }
    free(current);
    return prev;
}

list* addList(list* head, int value){
    list* newList = (list*)malloc(sizeof(list));
    newList->data = value;
    newList->next = NULL;
    if(head == NULL){
        head = newList;
    }
    else{
        list* trav = head;
        while(trav->next != NULL){
            trav = trav->next;
        }
        trav->next = newList;
    }
    return head;
}

void printList(list* head){
    list* current = head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

void freeList(list* head){
    list* current = head;
    list* nextNode = NULL;
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}