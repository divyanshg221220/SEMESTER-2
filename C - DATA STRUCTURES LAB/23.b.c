// Write a program to implement Threaded Binary Tree using Array and Linked List
// (Threaded Binary Tree Using Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
    int rthread;
};
struct node* createNode(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->left = new->right = NULL;
    new->rthread = 0;
    return new;
}
struct node* leftmost(struct node *n) {
    while(n && n->left != NULL)
        n = n->left;
    return n;
}
void inorder(struct node *root) {
    struct node *cur = leftmost(root);
    while(cur != NULL) {
        printf("%d ", cur->data);
        if(cur->rthread)
            cur = cur->right;
        else
            cur = leftmost(cur->right);
    }
}
int main() {
    struct node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->left->right->right = root;
    root->left->right->rthread = 1;
    printf("Inorder Traversal using Threaded Binary Tree (Linked List): ");
    inorder(root);
    return 0;
}