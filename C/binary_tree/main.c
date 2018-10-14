#include <stdio.h>
#include <malloc.h>
#include "fill.h"

void printTree(struct node* number){

    if(number->left != NULL){
        printf("%d\n", number->left->value);

        if (number->right != NULL){
            printf("%d\n",  number->right->value);
        }

        printTree(number->left);

        if (number->right != NULL){
            printTree(number->right);
        }
    }
}

int main() {
    int buffer[BUFLEN] = {4, 5, 2, 7, 44, 34, 2654, 235, 123, 2345};

    struct node* start = NULL;

    for (int i = 0; i < BUFLEN; ++i) {
        insert(&start, buffer[i]);
    }

    struct node* found = search(start, 44);
    if (found != NULL){
        printf("%d", found->value);
    } else{
        perror("Error in search!\n");
    }


    //printTree(&start);

    return 0;
}