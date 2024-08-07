#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

int size = 0;

typedef struct node{
    int value;
    struct node* next;
}*Node;

void insertEnd(Node* head, int value);
void insertFirst(Node* head, int value);
void deleteNode(Node* head, int value);
int search(Node head, int value);
void reverseList(Node* head);
void searchMid(Node head);
void printList(Node head);
void freeList(Node head);

int main(){
    Node head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertFirst(&head, 3);
    insertFirst(&head, 4);
    insertFirst(&head, 5);
    deleteNode(&head, 3);
    printf("Size: %d\n", size);
    searchMid(head);
    printList(head);
    reverseList(&head);
    printList(head);
    freeList(head);
    return 0;
}

void reverseList(Node* head){
    Node prev = NULL;
    Node next = NULL;
    Node current = *head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void searchMid(Node head){
    if(size > 0){
        int div = size % 2;
        Node current = head;
        Node prev = NULL;
        for(int i = 0; i < size / 2; i++){
            prev = current;
            current = current->next;
        }
        if(div == 0){
            printf("The middle value is: %d and %d\n", prev->value, current->value);
        }
        else{
            printf("The middle value is: %d\n", current->value);
        }
    }
}

int search(Node head, int value){
    Node current = head;
    while(current != NULL && current->value != value){
        current = current->next;
    }
    if(current != NULL){
        return value;
    }
    return ERROR;
}

void deleteNode(Node* head, int value){
    Node prev = NULL;
    Node current = *head;
    while(current != NULL && current->value != value){
        prev = current;
        current = current->next;
    }
    if(prev == NULL){
        *head = current->next;
        size--;
    }
    else{
        prev->next = current->next;
        size--;
    }
    free(current);
}

void insertEnd(Node* head, int value){
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
    size++;
}

void insertFirst(Node* head, int value){
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
    size++;
}

void printList(Node head){
    Node current = head;
    while(current != NULL){
        printf("%d--->", current->value);
        current = current->next;
    }
    printf("NULL\n");
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