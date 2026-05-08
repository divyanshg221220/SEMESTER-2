// Write a program to implement Red-Black Tree using Array and Linked List
// (Red-Black Tree Using Linked List)
#include <stdio.h>
#include <stdlib.h>
enum color { RED, BLACK };
struct node {
    int data;
    enum color color;
    struct node *left, *right, *parent;
};
struct node* createNode(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->color = RED;
    new->left = new->right = new->parent = NULL;
    return new;
}
void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d(%c) ", root->data, root->color == RED ? 'R' : 'B');
        inorder(root->right);
    }
}
struct node* insertBST(struct node *root, struct node *pt) {
    if(root == NULL)
        return pt;
    if(pt->data < root->data) {
        root->left = insertBST(root->left, pt);
        root->left->parent = root;
    } else {
        root->right = insertBST(root->right, pt);
        root->right->parent = root;
    }
    return root;
}
void fixViolation(struct node **root, struct node *pt) {
    (*root)->color = BLACK;
}
int main() {
    struct node *root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct node *pt = createNode(val);
        root = insertBST(root, pt);
        fixViolation(&root, pt);
    }
    printf("Inorder Traversal (Red-Black Tree): ");
    inorder(root);
    return 0;
}