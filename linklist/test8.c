#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

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
void detectLoop(Node head);
void removeLoop(Node head);
void addLoop(Node* head);
Node mergeList(Node head1, Node head2);
void printList(Node head);
void freeList(Node head);
void bubbleSort(Node head);
void swap(int* a, int* b);

int main(){
    srand(time(NULL));
    Node head = NULL;
    Node head2 = NULL;

    insertEnd(&head, rand() % 10);
    insertEnd(&head, rand() % 10);
    insertEnd(&head, rand() % 10);
    insertFirst(&head, rand() % 10);
    insertFirst(&head, rand() % 10);
    insertFirst(&head, rand() % 10);
    insertEnd(&head2, rand() % 10);
    insertEnd(&head2, rand() % 10);
    insertEnd(&head2, rand() % 10);
    // insertFirst(&head2, 8);
    // insertFirst(&head2, 3);
    // insertFirst(&head2, 4);

    bubbleSort(head);
    bubbleSort(head2);
    printList(head);
    printList(head2);

    head = mergeList(head, head2);

    printList(head);

    freeList(head);
    // freeList(head2);
    return 0;
}

Node mergeList(Node head1, Node head2){
    Node current = (Node)malloc(sizeof(struct node));
    Node initVal = NULL;
    Node list1 = head1;
    Node list2 = head2;

    if(list1->value < list2->value){
        initVal = list1;
    }
    else{
        initVal = list2;
    }

    while(list1 != NULL && list2 != NULL){
        if(list1->value < list2->value){
            current->next = list1;
            current = list1;
            list1 = list1->next;
        }
        else{
            current->next = list2;
            current = list2;
            list2 = list2->next;
        }
        
    }

    if(list1 == NULL){
        current->next = list2;
    }
    else{
        current->next = list1;
    }

    return initVal;
}

void bubbleSort(Node head){
    Node current;
    bool stillSorting = true;
    while(stillSorting){
        stillSorting = false;
        current = head;
        while(current->next != NULL){
            if(current->value > current->next->value){
                stillSorting = true;
                swap(&current->value, &current->next->value);
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

void removeLoop(Node head){
    Node current = head;
    Node prev = NULL;
    while(current != NULL){
        prev = current;
        current = current->next;
        if(current == head){
            printf("Removing loop\n");
            printf("The starting node of the loop is: %d\n", current->value);
            prev->next = NULL;
            break;
        }
    }
}

void addLoop(Node* head){
    Node current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = *head;
}

void detectLoop(Node head){
    Node slow = head;
    Node fast = head;
    bool isLoop = false;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            printf("There is a loop in the link list\n");
            removeLoop(head);
            isLoop = true;
            break;
        }
    }
    if(!isLoop){
        printf("There is no loop in the link list\n");
    }
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