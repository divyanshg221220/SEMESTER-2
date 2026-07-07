// Write a program to create a stack from a queue.
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;
void enqueue(int val)
{
    struct queue *new = malloc(sizeof(struct queue));
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    new -> data = val;
    new -> next = NULL;
    if (rear == NULL)
    {
        front = rear = new;
        return;
    }
    rear -> next = new;
    rear = new;
}
void push(int val)
{
    enqueue(val);
}
void pop()
{
    if (front == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct queue *temp = front;
    if (front == rear)
    {
        front = rear = NULL;
        free(temp);
        return;
    }
    while (temp -> next != rear)
    {
        temp = temp -> next;
    }
    free(rear);
    rear = temp;
    rear -> next = NULL;
}
void display()
{
    struct queue *temp = front;
    while (temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
int main(int argc, char const *argv[])
{
    int choice, val;
    do
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break; 
        case 3:
            display();
            break;
        case 4:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);
    return 0;
}