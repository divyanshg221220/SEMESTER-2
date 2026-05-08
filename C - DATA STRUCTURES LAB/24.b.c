// Write a program to implement Binary Search Tree using Array and Linked List
// (BST Using Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* createNode(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->left = new->right = NULL;
    return new;
}
struct node* insert(struct node *root, int val) {
    if(root == NULL)
        return createNode(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
struct node* findMin(struct node *root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}
struct node* deleteNode(struct node *root, int val) {
    if(root == NULL)
        return root;
    if(val < root->data)
        root->left = deleteNode(root->left, val);
    else if(val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if(root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct node *root = NULL;
    int n, val, del;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\nEnter element to delete: ");
    scanf("%d", &del);
    root = deleteNode(root, del);
    printf("Inorder after deletion: ");
    inorder(root);
    return 0;
}