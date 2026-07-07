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
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Enter the element: ");
            scanf("%d", &val);
            push(val);
            break;
        case 4:
            pop();
            break; 
        case 5:
            display();
            break;
        case 6:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 6);
    return 0;
}