#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}*link;

link addList(link head, int value);
link insertList(link head, int value, int pos);
link deleteList(link head, int value);
void freeList(link head);
void printList(link head);

int main(){
    link head = NULL;
    head = addList(head, 10);
    head = addList(head, 20);
    head = addList(head, 30);
    printList(head);
    head = insertList(head, 40, 2);
    head = insertList(head, 50, 1);
    head = insertList(head, 60, 7);
    printf("\n");
    printList(head);
    head = deleteList(head, 20);
    head = deleteList(head, 50);
    printf("\n");
    printList(head);
    freeList(head);
    return 0;
}

link deleteList(link head, int value){
    link current = head;
    link prev = NULL;
    int found = false;
    while(current != NULL){
        if(current->data == value){
            found = true;
            break;
        }
        prev = current;
        current = current->next;
    }

    if(found){
        if(prev == NULL){
            prev = current->next;
            free(current);
            return prev;
        }
        else{
            prev->next = current->next;
            free(current);
        }
    }
    return head;
}

link insertList(link head, int value, int pos){
    link current = head;
    link prev = NULL;
    int ctr = 1;
    while(ctr < pos && current != NULL){
        prev = current;
        current = current->next;
        ctr++;
    }
    link newList = (link)malloc(sizeof(struct node));
    newList->data = value;

    if(prev == NULL){
        newList->next = current;
        return newList;
    }
    else{
        newList->next = prev->next;
        prev->next = newList;
    }
    return head;
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