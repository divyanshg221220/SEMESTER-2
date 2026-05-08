// Write a program to implement Binary Search Tree using Array and Linked List
// (BST Using Array)
#include <stdio.h>
int tree[100];
void inorder(int i) {
    if(tree[i] !=-1) {
        inorder(2*i);
        printf("%d ", tree[i]);
        inorder(2*i + 1);
    }
}
int main() {
    int n, val;
    for(int i = 0; i < 100; i++)
        tree[i] =-1;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int k = 0; k < n; k++) {
        scanf("%d", &val);
        int i = 1;
        while(tree[i] != -1) {
            if(val < tree[i])
                i = 2*i;
            else
                i = 2*i + 1;
        }
        tree[i] = val;
    }
    printf("Inorder Traversal: ");
    inorder(1);
    return 0;
}