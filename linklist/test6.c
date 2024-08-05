#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}*Node;

void printList(Node head);
void freeList(Node head);
void addList(Node* head, int value);
Node reverseList(Node head);

int main(){
    Node head = NULL;
    addList(&head, 1);
    addList(&head, 2);
    addList(&head, 3);
    addList(&head, 4);
    addList(&head, 5);
    head = reverseList(head);
    printList(head);
    freeList(head);
    return 0;
}

Node reverseList(Node head){
    Node current = head;
    Node next = NULL;
    Node prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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
        printf("%d--->",current->value);
        current = current->next;
    }
    printf("NULL");
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