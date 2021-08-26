/* 
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze
Github: https://github.com/oakoneric/algorithmen-datenstrukturen-ws20
Website: https://oakoneric.github.io/aud20.html
------------------------------------------------------------------------------
Aufgabe 1
------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct element *list;
struct element { int value; list next; };

typedef struct node *tree;
struct node { int key; tree left, right; };

int numberOfNodes(tree t){
    if (t == NULL) return 0;
    return 1 + numberOfNodes(t->left) + numberOfNodes(t->right);
}
int maximum(int a, int b){
    int res;
    if (a> b) res = a;
    if (a<=b) res = b;
    return res;
}
int height(tree t){
    if (t == NULL) return 0;
    return 1 + maximum(height(t->left), height(t->right));
}

/* ----------------------------------------- */
tree createNode(int n, tree l, tree r) {
    tree t   = malloc(sizeof(struct node));
    t->left  = l;
    t->right = r;
    t->key   = n;
    return t;
}
/* ----------------------------------------- */

void printTree(tree t, int depth) { /* ausgabe eines baumes */
    if (t) {
        for (int i = 0; i < depth; i++) printf("\t");
        printf("%d\n", t->key);
        printTree(t->left, depth+1);
        printTree(t->right, depth+1);
    }
}
int length(list l){
    if (l==NULL) return 0;
    return 1 + length(l->next);
}
void append(list *lp, int n){
    while(*lp != NULL)
        lp = &((*lp)->next) ;
    (*lp) = malloc(sizeof(struct element));
    (*lp)->value  = n;
    (*lp)->next = NULL;
}
void treeToList_rec(tree t, list *lp){
    if (t == NULL) return;
    append(lp, t->key);
    treeToList_rec(t->left, lp);
    treeToList_rec(t->right, lp);
}
list treeToList(tree t){
    list l = NULL;
    treeToList_rec(t,&l);
    return l;
}
void listToArray(list l, int *arr[]){
    int len = length(l);
    int i = 0;
    while(l && i<len){
        *arr[i] = l->value;
        l = l->next;
    }    
}
void printTabs(int k){
    for (int i=1; i<=k; i++) printf("\t");
}
/*
void printTree2(tree t) { /* ausgabe eines baumes 
    int h = height(t);
    int n = numberOfNodes(t);
    int leaves = 2^h;
    
    printf(t->key)
    printTree2(t->left);
    printTree2(t-right);
    }

void printLevel(tree t, int level, int leaves){
    int tabs = leaves / (level+1)
    
    
}    
    
    
    if (t) {
        for (int i = 0; i < depth; i++) printf("\t");
        printf("%d\n", t->key);
        printTree(t->left, depth+1);
        printTree(t->right, depth+1);
    }
}
*/

void printList(list l) { /* ausgabe einer liste */
    printf("[");
    while(l) {                      
        printf("%d", l->value);       
        if(l->next) printf(", ");   
        l = l->next;           
    }
    printf("]\n");
}


int main() {
     
    // zu Teil (a)
    printf("\n============ Teil (a) ========================\n");
    tree bsp = 
		createNode(4,
			createNode(5, NULL, NULL),
			createNode(2,
				createNode(0, NULL, NULL),
				NULL));
    printTree(bsp, 0);
    printf("Hoehe: %d", height(bsp));
    
    list treeList = treeToList(bsp);
    printList(treeList);
    int len = length(treeList);
    int arr[len];
    listToArray(treeList,  &arr);
    for(int i=0;i<len;i++) printf("%d, ", arr[i]);
    /*
    // zu Teil (e)
    printf("\n============ Teil (e) ========================\n");
    tree s = createNode(2, createNode(3, createNode(2, NULL, NULL), createNode(4, NULL, NULL)), createNode(1, NULL, NULL));
    tree t = createNode(2, createNode(2, NULL, NULL), createNode(3, NULL, NULL));
    
    tree monster = createNode(2, createNode(3, createNode(2, createNode(4, createNode(6, NULL, NULL), createNode(3, NULL, NULL)), createNode(6, NULL, NULL)), createNode(1, createNode(7, createNode(6, NULL, NULL), createNode(3, NULL, NULL)), createNode(9, createNode(7, NULL, NULL),createNode(8, NULL, NULL)))), createNode(1, createNode(6, createNode(2, NULL, NULL), createNode(5, NULL, NULL)), createNode(3, createNode(4, NULL, NULL), createNode(1, NULL, NULL) )));
    
    printf("\n---------------------------\n");
    printTree(s, 0);
    printf("\n");

    printf("\n---------------------------\n");
    printTree(t, 0);
    printf("\n"); 
    
    printf("\n---------------------------\n");
    printTree(monster, 0);
    printf("\n");
    */
    return 0;
}