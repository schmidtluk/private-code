//
// Created by tyroc on 13.10.2018.
//

#ifndef BINARY_TREE_FILL_H
#define BINARY_TREE_FILL_H

#define BUFLEN 10

struct node{
    int value;

    struct node* left;
    struct node* right;
};

void fillSort(struct node* number, const int buffer[]);
struct node* insert(struct node **ppk, int d);
struct node* search(struct node* number, int x);

#endif //BINARY_TREE_FILL_H
