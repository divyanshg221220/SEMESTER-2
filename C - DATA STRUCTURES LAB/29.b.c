// Write a program to implement B+ Tree using Array and Linked List
// (B+ Tree Using Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->next = NULL;
    if(head == NULL || head->data > val) {
        new->next = head;
        head = new;
    } else {
        struct node *temp = head;
        while(temp->next != NULL && temp->next->data < val)
            temp = temp->next;
        new->next = temp->next;
        temp->next = new;
    }
}
void traverse() {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    int n, val;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter keys:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(val);
    }
    printf("Traversal of B+ Tree (Linked List): ");
    traverse();
    return 0;
}