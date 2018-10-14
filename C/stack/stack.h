//
// Created by tyroc on 14.10.2018.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

struct book{
    char* title;
    char* release;
    int pages;

    struct book* prev;
};

int isEmpty(struct book* stptr);
int push(struct book** stptr, struct book* b);
struct book pop(struct book** stptr);

#endif //STACK_STACK_H
