// Write a program to implement Deque using Array and Linked List
// (Deque Using Array)
#include <stdio.h>
#define MAX 5
int deque[MAX];
int front =-1, rear =-1;
void insertFront(int val) {
    if(front == 0)
        printf("Overflow\n");
    else {
        if(front ==-1)
            front = rear = 0;
        else
            front--;
        deque[front] = val;
    }
}
void insertRear(int val) {
    if(rear == MAX-1)
        printf("Overflow\n");
    else {
        if(rear ==-1)
            front = rear = 0;
        else
            rear++;
        deque[rear] = val;
    }
}
void deleteFront() {
    if(front ==-1)
        printf("Underflow\n");
    else if(front == rear)
        front = rear =-1;
    else
        front++;
}
void deleteRear() {
    if(rear ==-1)
        printf("Underflow\n");
    else if(front == rear)
        front = rear =-1;
    else
        rear--;
}
void display() {
    if(front ==-1)
        printf("Deque is empty\n");
    else {
        for(int i = front; i <= rear; i++)
            printf("%d ", deque[i]);
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