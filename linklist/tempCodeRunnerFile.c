#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}*link;

link reverseList(link head);
bool hasLoopList(link head);
link addList(link head, int value);
link addLoop(link head);
link removeLoop(link head);
void freeList(link head);
void printList(link head);

int main(){
    link head = NULL;
    head = addList(head, 10);
    head = addList(head, 20);
    head = addList(head, 30);
    head = addList(head, 40);
    head = addList(head, 50);
    printList(head);
    printf("\n");
    head = addLoop(head);
    printf("Has Loop: %s\n", hasLoopList(head) ? "true" : "false");
    head = removeLoop(head);
    printf("Has Loop: %s\n", hasLoopList(head) ? "true" : "false");
    head = reverseList(head);
    printList(head);
    freeList(head);
    return 0;
}

link reverseList(link head){
    int size = 1;
    link current = head;
    while(current->next != NULL){
        size++;
        current = current->next;
    }
    link tail = current;
    current = head;
    link prev = NULL;
    int i = 0;
    while(i < size){
        current = head;
        prev = NULL;
        int j = 0;
        while(j < size-i-1){
            prev = current;
            current = current->next;
            j++;
        }
        current->next = prev;
        i++;
    }
    head = NULL;
    return tail;
}

link removeLoop(link head){
    link current = head->next;
    link prev = head;
    while(current != head){
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    return head;
}

link addLoop(link head){
    link current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = head;
    return head;
}

bool hasLoopList(link head){
    bool hasLoop = false;
    link current = head->next;
    while(current != NULL){
        if(current == head){
            hasLoop = true;
            break;
        }
        current = current->next;
    }
    return hasLoop;
}

link addList(link head, int value){
    link newList = (link)malloc(sizeof(struct node));
    newList->data = value;
    newList->next = head;
    return newList;
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

void printList(link head){
    link current = head;
    while(current != NULL){
        printf("%d->", current->data);
        current = current->next;
    }
}