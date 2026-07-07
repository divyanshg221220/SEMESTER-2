// Write a program to implement a priority queue.
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data;
    int priority;
    struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;
void enqueue(int val, int priority)
{
    struct queue *new = malloc(sizeof(struct queue));
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    new -> data = val;
    new -> priority = priority;
    new -> next = NULL;
    if (rear == NULL)
    {
        front = rear = new;
        return;
    }
    struct queue *temp = front;
    if (new -> priority < temp -> priority)
    {
        new -> next = front;
        front = new;
        return;
    }
    while (temp -> next != NULL && temp -> next -> priority <= new -> priority)
    {
        temp = temp -> next;
    }
    new -> next = temp -> next;
    temp -> next = new;
    if (new -> next == NULL)
    {
        rear = new;
    }
}
void dequeue()
{
    if (front == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct queue *temp = front;
    front = front -> next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
}
void display()
{
    struct queue *temp = front;
    while (temp != NULL)
    {
        printf("%d (%d) -> ", temp -> data, temp -> priority);
        temp = temp -> next;
    }
    printf("NULL\n");
}
int main(int argc, char const *argv[])
{
    int choice, val, priority;
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &val);
            printf("Enter the priority: ");
            scanf("%d", &priority);
            enqueue(val, priority);
            break;
        case 2:
            dequeue();
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