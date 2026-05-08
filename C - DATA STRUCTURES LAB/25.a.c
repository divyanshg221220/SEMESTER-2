// Write a program to implement AVL Tree using Array and Linked List
// (AVL Tree Using Array)
#include <stdio.h>
int tree[100], height[100];
int max(int a, int b) {
    return (a > b) ? a : b;
}
int getHeight(int i) {
    if(tree[i] == -1)
        return 0;
    return height[i];
}
void updateHeight(int i) {
    height[i] = 1 + max(getHeight(2*i), getHeight(2*i+1));
}
void inorder(int i) {
    if(tree[i] != -1) {
        inorder(2*i);
        printf("%d ", tree[i]);
        inorder(2*i + 1);
    }
}
int main() {
    int n, val;
    for(int i = 0; i < 100; i++) {
        tree[i] = -1;
        height[i] = 0;
    }
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
        height[i] = 1;
    }
    printf("Inorder Traversal (Array AVL): ");
    inorder(1);
    return 0;
}