// Write a program to perform operations on Circular Linked List
// (Singly Circular Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertEnd(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    if(head == NULL) {
        head = new;
        new->next = head;
        return;
    }
    struct node *temp = head;
    while(temp->next != head)
        temp = temp->next;
    temp->next = new;
    new->next = head;
}
void deleteBegin() {
    if(head == NULL)
        return;
    struct node *temp = head;
    struct node *last = head;
    while(last->next != head)
        last = last->next;
    head = head->next;
    last->next = head;
    free(temp);
}
void display() {
    if(head == NULL)
        return;
    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("(HEAD)\n");
}
int main() {
    int choice, val;
    while(1) {
        printf("\n1.Insert End\n2.Delete Begin\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 2:
            deleteBegin();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}