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
    head = addList(head, 60);
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
    link current = head;
    link prev = NULL;
    link next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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
    link slow = head;
    link fast = head;
    while(fast != NULL && fast->next != NULL && slow != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            hasLoop = true;
            break;
        }
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