// Write a program to implement B-Tree using Array and Linked List
// (B-Tree Using Linked List)
#include <stdio.h>
#include <stdlib.h>
#define T 2 /* Minimum degree */
struct node {
    int keys[2*T-1];
    struct node *child[2*T];
    int n;
    int leaf;
};
struct node* createNode(int leaf) {
    struct node *new = malloc(sizeof(struct node));
    new->leaf = leaf;
    new->n = 0;
    for(int i = 0; i < 2*T; i++)
        new->child[i] = NULL;
    return new;
}
void traverse(struct node *root) {
    int i;
    for(i = 0; i < root->n; i++) {
        if(!root->leaf)
            traverse(root->child[i]);
        printf("%d ", root->keys[i]);
    }
    if(!root->leaf)
        traverse(root->child[i]);
}
int main() {
    struct node *root = createNode(1);
    root->keys[0] = 10;
    root->keys[1] = 20;
    root->keys[2] = 30;
    root->n = 3;
    printf("Traversal of B-Tree (Linked List): ");
    traverse(root);
    return 0;
}