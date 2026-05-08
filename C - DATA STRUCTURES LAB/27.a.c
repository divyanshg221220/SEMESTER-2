// Write a program to implement 2–3 Tree using Array and Linked List
// (2–3 Tree Using Array)
#include <stdio.h>
int keys[20][2];
int count[20];
void inorder(int i) {
    if(count[i] == 1)
        printf("%d ", keys[i][0]);
    else if(count[i] == 2)
        printf("%d %d ", keys[i][0], keys[i][1]);
}
int main() {
    int n, val;
    for(int i = 0; i < 20; i++)
        count[i] = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        if(count[0] == 0) {
            keys[0][0] = val;
            count[0] = 1;
        } else if(count[0] == 1) {
            if(val < keys[0][0]) {
                keys[0][1] = keys[0][0];
                keys[0][0] = val;
            } else
                keys[0][1] = val;
            count[0] = 2;
        }
    }
    printf("Inorder Traversal (Array 2--3 Tree): ");
    inorder(0);
    return 0;
}