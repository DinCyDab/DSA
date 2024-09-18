#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 15

typedef struct{
	int elem[MAX];
	int count;
}*Set, set;

Set unionSet(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void insert(Set s, int data);
void deleteElem(Set s, int data);
bool isElem(Set s, int data);
bool isFull(Set s);
Set init();
void printSet(Set s);

int main(){
	srand(time(NULL));
	Set A = init();
	Set B = init();
	
	
	int i;
	for(i = 0; i < 5; i++){
		insert(A, rand() % 15);
	}
	
	for(i = 0; i < 5; i++){
		insert(B, rand() % 15);
	}
	
	printf("\n");
	
	printf("Set A: \n");
	printf("Count: %d\n", A->count);
	printSet(A);
	
	printf("Set B: \n");
	printf("Count: %d\n", B->count);
	printSet(B);
	
	Set C = difference(A, B);
	printf("Difference Set C = (A - B): \n");
	printf("Count: %d\n", C->count);
	printSet(C);
	
	free(C);
	C = difference(B, A);
	printf("Difference Set C = (B - A): \n");
	printf("Count: %d\n", C->count);
	printSet(C);
	
	free(C);
	C = unionSet(A, B);
	printf("Union Set C = (A U B): \n");
	printf("Count: %d\n", C->count);
	printSet(C);
	
	free(C);
	C = intersection(A, B);
	printf("Intersection Set C = (A n B): \n");
	printf("Count: %d\n", C->count);
	printSet(C);
	
	free(A);
	free(B);
	free(C);
	return 0;
}

Set unionSet(Set A, Set B){
	Set C = init();
	int i = 0;
	for(i; i < MAX; i++){
		if(A->elem[i] == 1 || B->elem[i] == 1){
			C->elem[i]++;
			C->count++;
		}
	}
	return C;
}

Set intersection(Set A, Set B){
	Set C = init();
	int i = 0;
	for(; i < MAX; i++){
		if(A->elem[i] == 1 && B->elem[i] == 1){
			C->elem[i]++;
			C->count++;
		}
	}
	return C;
}

Set difference(Set A, Set B){
	Set C = init();
	int i = 0;
	for(; i < MAX; i++){
		if(A->elem[i] == 1 && !B->elem[i]){
			C->elem[i]++;
			C->count++;
		}
	}
	return C;
}

void insert(Set s, int data){
	if(data > MAX - 1 || data < 0){
		printf("Invalid input\n");
		return;
	}
	if(isFull(s)){
		printf("Invalid insert. Set is full\n");
		return;
	}
	if(isElem(s, data)){
		printf("%d is already inside the set\n", data);
		return;
	}
	
	s->elem[data]++;
	s->count++;
}

void deleteElem(Set s, int data){
	if(data > MAX - 1 || data < 0){
		printf("Invalid input\n");
		return;
	}
	s->elem[data]--;
	s->count--;
}

bool isElem(Set s, int data){
	return s->elem[data] == 1;
}

bool isFull(Set s){
	return s->count == MAX;
}

Set init(){
	Set s = (Set)malloc(sizeof(set));
	s->count = 0;
	int i = 0;
	for(i; i < MAX; i++){
		s->elem[i] = 0;
	}
	return s;
}

void printSet(Set s){
	int i = 0;
	for(i; i < MAX; i++){
		printf((s->elem[i] == 1) ? "[%d]" : "", i);
	}
	printf("\n\n");
}
