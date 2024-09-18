#include <stdio.h>
#include <stdlib.h>

unsigned char unionChar(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char insertFirst(unsigned char A);
unsigned char insertLast();
unsigned char insertPosition();
unsigned char deleteFirst();
unsigned char deleteLast();
unsigned char deletePosition();

int main(){
	unsigned char A = 1;
	unsigned char B = 3;
	
	unsigned char C = insertFirst(A);
	
	
	
	int i;
	unsigned char mask = 1 << (sizeof(char) * 8 - 1);
	for(i = 0; mask > 0; mask >>= 1, i++){
		printf("%u", (C & mask) != 0) ? 1 : 0;
	}
	
	return 0;
}

unsigned char unionChar(unsigned char A, unsigned char B){
	return A | B;
}
unsigned char difference(unsigned char A, unsigned char B){
	return A & (~B);
}
unsigned char intersection(unsigned char A, unsigned char B){
	return A & B;
}
unsigned char insertFirst(unsigned char A){
	return << 1;
}
