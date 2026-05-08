// Write a program to implement 2–3 Tree using Array and Linked List
// (2–3 Tree Using Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int key1, key2;
    int count;
    struct node *left, *middle, *right;
};
struct node* createNode(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->key1 = val;
    new->count = 1;
    new->left = new->middle = new->right = NULL;
    return new;
}
void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->key1);
        inorder(root->middle);
        if(root->count == 2) {
            printf("%d ", root->key2);
            inorder(root->right);
        }
    }
}
int main() {
    struct node *root = createNode(10);
    root->key2 = 20;
    root->count = 2;
    printf("Inorder Traversal (Linked List 2--3 Tree): ");
    inorder(root);
    return 0;
}