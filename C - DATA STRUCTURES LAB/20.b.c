// Write a program to implement Circular Queue using Array and Linked List
// (Circular Queue Using Linked List)
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
    if(front == NULL) {
        front = rear = new;
        rear->next = front;
    } else {
        rear->next = new;
        rear = new;
        rear->next = front;
    }
}
void dequeue() {
    if(front == NULL)
        printf("Queue Underflow\n");
    else if(front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct node *temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
void display() {
    if(front == NULL)
        printf("Queue is empty\n");
    else {
        struct node *temp = front;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != front);
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