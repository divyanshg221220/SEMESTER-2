// Write a program to implement Threaded Binary Tree using Array and Linked List
// (Threaded Binary Tree Using Array)
#include <stdio.h>
int tree[50], right[50], isThread[50];
int leftmost(int i) {
    while(tree[2*i] != -1)
        i = 2*i;
    return i;
}
void inorder() {
    int i = leftmost(1);
    while(i !=-1) {
        printf("%d ", tree[i]);
        if(isThread[i])
            i = right[i];
        else
            i = leftmost(2*i + 1);
    }
}
int main() {
    for(int i = 0; i < 50; i++)
        tree[i] =-1;
    tree[1] = 10;
    tree[2] = 5;
    tree[3] = 15;
    tree[6] = 12;
    tree[7] = 20;
    isThread[2] = 1;
    right[2] = 1;
    printf("Inorder Traversal using Threaded Binary Tree (Array): ");
    inorder();
    return 0;
}