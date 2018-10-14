//
// Created by tyroc on 14.10.2018.
//
#include <malloc.h>
#include "stdio.h"

#include "stack.h"

int isEmpty(struct book* stptr){
    if(stptr == NULL){
        return 1;
    } else{
        return 0;
    }
}

int push(struct book** stptr, struct book* b){
    struct book* new;
    if ((new = malloc(sizeof(struct book)))){
        new->title = b->title;
        new->pages = b->pages;
        new->release = b->release;

        new->prev = (*stptr);
        *stptr = new;
        return 1;
    } else{
        printf("Error malloc: %d", errno);
        return NULL;
    }
}

struct book pop(struct book** stptr){
    struct book b = **stptr;
    *stptr = (*stptr)->prev;

    return b;
}

