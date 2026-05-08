// Write a program to create and traverse Binary Tree using Array and Linked List
// (Binary Tree Using Array)
#include <stdio.h>
int tree[50];
void inorder(int i) {
    if(tree[i] !=-1) {
        inorder(2*i);
        printf("%d ", tree[i]);
        inorder(2*i + 1);
    }
}
void preorder(int i) {
    if(tree[i] !=-1) {
        printf("%d ", tree[i]);
        preorder(2*i);
        preorder(2*i + 1);
    }
}
void postorder(int i) {
    if(tree[i] !=-1) {
        postorder(2*i);
        postorder(2*i + 1);
        printf("%d ", tree[i]);
    }
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 1; i <= 50; i++)
        tree[i] =-1;
    printf("Enter tree elements:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &tree[i]);
    printf("Inorder Traversal: ");
    inorder(1);
    printf("\nPreorder Traversal: ");
    preorder(1);
    printf("\nPostorder Traversal: ");
    postorder(1);
    return 0;
}