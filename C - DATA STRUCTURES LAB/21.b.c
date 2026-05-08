// Write a program to implement Deque using Array and Linked List
// (Deque Using Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;
void insertFront(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->prev = NULL;
    new->next = front;
    if(front == NULL)
        rear = new;
    else
        front->prev = new;
    front = new;
}
void insertRear(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->next = NULL;
    new->prev = rear;
    if(rear == NULL)
        front = new;
    else
        rear->next = new;
    rear = new;
}
void deleteFront() {
    if(front == NULL)
        printf("Underflow\n");
    else {
        struct node *temp = front;
        front = front->next;
        if(front != NULL)
            front->prev = NULL;
        else
            rear = NULL;
        free(temp);
    }
}
void deleteRear() {
    if(rear == NULL)
        printf("Underflow\n");
    else {
        struct node *temp = rear;
        rear = rear->prev;
        if(rear != NULL)
            rear->next = NULL;
        else
            front = NULL;
        free(temp);
    }
}
void display() {
    struct node *temp = front;
    if(temp == NULL)
        printf("Deque is empty\n");
    else {
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int choice, val;
    while(1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front");
        printf("\n4.Delete Rear\n5.Display\n6.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            scanf("%d", &val);
            insertFront(val);
            break;
        case 2:
            scanf("%d", &val);
            insertRear(val);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        }
    }
}