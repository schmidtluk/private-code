//
// Created by tyroc on 13.10.2018.
//

#include <malloc.h>
#include "fill.h"

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void fillSort(struct node* start, const int buffer[]){

    struct node* number;
    short end = 0;

    for (int i = 0; i < BUFLEN; ++i) {
        number = start;

        while (end != 1){
            if (number->left == 0){
                number->left = malloc(sizeof(struct node));
                number->left->value = buffer[i];
                number->left->left = 0;
                number->left->right = 0;

                end = 1;
            } else if (number->right == 0){
                number->right = malloc(sizeof(struct node));
                number->right->value = buffer[i];
                number->right->left = 0;
                number->right->right = 0;

                end = 1;
            } else{
                if (buffer[i] < number->right->value){
                    number = number->left;
                } else{
                    number = number->right;
                }
            }
        }

        end = 0;
    }
}

void fillNormal(struct node* start, const int buffer[]){
    struct node* number = start;

    for (int i = 0; i < BUFLEN; ++i) {
        if (number->left == NULL){
            number->left = malloc(sizeof(struct node));
            number->left->value = buffer[i];
            number->left->left = NULL;
            number->left->right = NULL;

        } else if (number->right == NULL) {
            number->right = malloc(sizeof(struct node));
            number->right->value = buffer[i];
            number->right->left = NULL;
            number->right->right = NULL;

            number = number->left;
        }
    }

    //TODO: not done
}

struct node* insert(struct node **ppk, int d){

    struct node* pnew = NULL;

    if(*ppk == NULL){
        if((pnew = (struct node*) malloc (sizeof(struct node)))){
            pnew->value = d;
            pnew->left = NULL;
            pnew->right = NULL;
            *ppk = pnew;
        }
    }
    else if(d < (*ppk)->value){
        pnew = insert((&(*ppk)->left), d);
    }
    else pnew = insert((&(*ppk)->right), d);

    return pnew;
}

struct node* search(struct node* number, int x){
    for (int i = 0; i < BUFLEN; ++i) {
        if(number->value == x){
            return number;
        } else if(x > number->value){
            number = number->right;
        } else{
            number = number->left;
        }
    }
}
