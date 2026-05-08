// Write a program to implement AVL Tree using Array and Linked List
// (AVL Tree Using Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(struct node *n) {
    if(n == NULL)
        return 0;
    return n->height;
}
struct node* createNode(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->left = new->right = NULL;
    new->height = 1;
    return new;
}
struct node* rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
struct node* leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int getBalance(struct node *n) {
    if(n == NULL)
        return 0;
    return height(n->left)- height(n->right);
}
struct node* insert(struct node *node, int key) {
    if(node == NULL)
        return createNode(key);
    if(key < node->data)
        node->left = insert(node->left, key);
    else if(key > node->data)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if(balance > 1 && key < node->left->data)
        return rightRotate(node);
    if(balance <-1 && key > node->right->data)
        return leftRotate(node);
    if(balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance <-1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    struct node *root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Inorder Traversal (AVL Tree): ");
    inorder(root);
    return 0;
}