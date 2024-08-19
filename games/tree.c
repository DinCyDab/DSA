#include <stdio.h>
#include <stdlib.h>

void treeMaker(int height);

int main(){
    treeMaker(5);
    return 0;
}

void treeMaker(int height){
    int stars = 1;
    int spaces = height;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < spaces; j++){
            printf(" ");
        }
        for(int j = 0; j < stars; j++){
            printf("*");
        }
        printf("\n");
        stars += 2;
        spaces--;
    }
    spaces = height;
    for(int j = 0; j < spaces; j++){
        printf(" ");
    }
    printf("*");
}