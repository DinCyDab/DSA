#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node* next;
}*Node;

void printList(Node head);
void freeList(Node head);
void addList(Node* head, int value);
Node mergeList(Node list1, Node list2);
void bubbleSort(Node head);
void swap(int* a, int* b);

int main(){
    Node list1 = NULL;
    Node list2 = NULL;

    addList(&list1, 1);
    addList(&list1, 2);
    addList(&list1, 3);
    addList(&list2, 2);
    addList(&list2, 3);
    addList(&list2, 4);

    list1 = mergeList(list1, list2);

    bubbleSort(list1);

    printList(list1);
    printList(list2);

    freeList(list1);
    return 0;
}

void bubbleSort(Node head){
    bool isSort = true;
    Node current = head;
    while(isSort){
        isSort = false;
        current = head;
        while(current->next != NULL){
            if(current->value > current->next->value){
                swap(&current->value, &current->next->value);
                isSort = true;
            }
            current = current->next;
        }
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

Node mergeList(Node list1, Node list2){
    Node trav = list1;
    while(trav->next != NULL){
        trav = trav->next;
    }
    trav->next = list2;
    return list1;
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