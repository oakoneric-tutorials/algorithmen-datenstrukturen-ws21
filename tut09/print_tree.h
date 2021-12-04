#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree;
struct node
{
    int key;
    tree left, right;
};

// int _height(tree t);

// int _print_t(tree t, int is_left, int offset, int depth, char s[20][255]);

void print_t(tree t);
