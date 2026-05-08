// Write a program to implement B-Tree using Array and Linked List
// (B-Tree Using Array)
#include <stdio.h>
int keys[10];
int n = 0;
void insert(int val) {
    int i;
    for(i = n - 1; i >= 0 && keys[i] > val; i--)
        keys[i + 1] = keys[i];
    keys[i + 1] = val;
    n++;
}
void traverse() {
    for(int i = 0; i < n; i++)
        printf("%d ", keys[i]);
}
int main() {
    int m, val;
    printf("Enter number of keys: ");
    scanf("%d", &m);
    printf("Enter keys:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &val);
        insert(val);
    }
    printf("Traversal of B-Tree (Array): ");
    traverse();
    return 0;
}