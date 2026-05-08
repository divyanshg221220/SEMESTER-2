// Write a program to implement Circular Queue using Array and Linked List
// (Circular Queue Using Array)
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front =-1, rear =-1;
void enqueue(int val) {
    if((front == (rear + 1) % MAX))
        printf("Queue Overflow\n");
    else {
        if(front ==-1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;
        queue[rear] = val;
    }
}
void dequeue() {
    if(front ==-1)
        printf("Queue Underflow\n");
    else if(front == rear)
        front = rear =-1;
    else
        front = (front + 1) % MAX;
}
void display() {
    if(front ==-1)
        printf("Queue is empty\n");
    else {
        int i = front;
        while(1) {
            printf("%d ", queue[i]);
            if(i == rear)
                break;
            i = (i + 1) % MAX;
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