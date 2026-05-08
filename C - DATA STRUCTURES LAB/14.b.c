// Write a program to perform operations on Circular Linked List
// (Doubly Circular Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void insertEnd(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    if(head == NULL) {
        new->next = new;
        new->prev = new;
        head = new;
        return;
    }
    struct node *last = head->prev;
    last->next = new;
    new->prev = last;
    new->next = head;
    head->prev = new;
}
void display() {
    if(head == NULL)
        return;
    struct node *temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("(HEAD)\n");
}
int main() {
    int choice, val;
    while(1) {
        printf("\n1.Insert End\n2.Display\n3.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 2:
            display();
            break;
        case 3:
            return 0;
        }
   }
}