// Write a program to perform operations on Doubly Linked List
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void insertBegin(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->prev = NULL;
    new->next = head;
    if(head != NULL)
        head->prev = new;
    head = new;
}
void insertEnd(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->next = NULL;
    if(head == NULL) {
        new->prev = NULL;
        head = new;
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
}
void insertPos(int val, int pos) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    struct node *temp = head;
    for(int i = 1; i < pos- 1; i++)
        temp = temp->next;
    new->next = temp->next;
    new->prev = temp;
    temp->next->prev = new;
    temp->next = new;
}
void deleteBegin() {
    struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}
void deleteEnd() {
    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}
void deletePos(int pos) {
    struct node *temp = head;
    for(int i = 1; i < pos; i++)
        temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
void display() {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, val, pos;
    while(1) {
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Position");
        printf("\n4.Delete Begin\n5.Delete End\n6.Delete Position");
        printf("\n7.Display\n8.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            scanf("%d", &val);
            insertBegin(val);
            break;
        case 2:
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            scanf("%d%d", &val, &pos);
            insertPos(val, pos);
            break;
        case 4:
            deleteBegin();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            scanf("%d", &pos);
            deletePos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            return 0;
        }
    }
}