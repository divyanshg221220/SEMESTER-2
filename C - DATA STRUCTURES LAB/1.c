// Write a program to perform insertion and deletion operations on an array
#include <stdio.h>
int main() {
    int a[50], n, i, pos, val, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("1. Insertion\n2. Deletion\nEnter choice: ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("Enter position and value: ");
        scanf("%d %d", &pos, &val);
        for(i = n; i >= pos; i--)
            a[i] = a[i-1];
        a[pos-1] = val;
        n++;
    }
    else if(choice == 2) {
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        for(i = pos-1; i < n-1; i++)
            a[i]=a[i+1];
        n--;
        }
    printf("Resultant array:\n");
    for(i = 0; i<n; i++)
        printf("%d ", a[i]);
    return 0;
}