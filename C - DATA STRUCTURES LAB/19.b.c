// Write a program to implement Linear Queue using Array and Linked List
// (Linear Queue Using Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;
void enqueue(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->next = NULL;
    if(rear == NULL)
        front = rear = new;
    else {
        rear->next = new;
        rear = new;
    }
}
void dequeue() {
    if(front == NULL)
        printf("Queue Underflow\n");
    else {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}
void display() {
    struct node *temp = front;
    if(temp == NULL)
        printf("Queue is empty\n");
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
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}