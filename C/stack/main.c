#include <stdio.h>
#include <malloc.h>

#include "stack.h"
int main() {

    struct book* stptr = NULL;
    struct book* b = malloc(sizeof(struct book));
    b->release = "04.03.2001";
    b->title = "Kritik der reinen Vernunft";
    b->pages = 300;

    push(&stptr, b);
    *b = pop(&stptr);

    return 0;
}