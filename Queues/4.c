// Write a program to implement a dequeue with the help of a linked list.
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;
void front_enqueue(int val)
{
    struct queue *new = malloc(sizeof(struct queue));
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    new -> data = val;
    new -> next = front;
    if (rear == NULL)
    {
        front = rear = new;
    }
    front = new;
}
void rear_enqueue(int val)
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
void front_dequeue()
{
    if (front == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct queue *temp = front;
    front = front -> next;
    free(temp);
}
void rear_dequeue()
{
    if (rear == NULL)
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
        printf("1. Insertion at front\n");
        printf("2. Insertion at rear\n");
        printf("3. Deletion at front\n");
        printf("4. Deletion at rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &val);
            front_enqueue(val);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &val);
            rear_enqueue(val);
            break;
        case 3:
            front_dequeue();
            break;
        case 4:
            rear_dequeue();
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
    
}