// Write a program to input two queues and compare their contents.
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
struct queue *front1 = NULL;
struct queue *rear1 = NULL;
struct queue *front2 = NULL;
struct queue *rear2 = NULL;
void enqueue(struct queue **front, struct queue **rear, int val)
{
    struct queue *new = malloc(sizeof(struct queue));
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    new -> data = val;
    new -> next = NULL;
    if (*rear == NULL)
    {
        *front = *rear = new;
        return;
    }
    (*rear) -> next = new;
    *rear = new;
}
void dequeue(struct queue **front, struct queue **rear)
{
    if (*front == NULL)
    {
        return;
    }
    struct queue *temp = *front;
    *front = (*front) -> next;
    if (*front == NULL)
    {
        *rear = NULL;
    }
    free(temp);
}
void compare()
{
    while (front1 != NULL && front2 != NULL)
    {
        if (front1 -> data != front2 -> data)
        {
            printf("Not equal");
            return;
        }
        dequeue(&front1, &rear1);
        dequeue(&front2, &rear2);
    }
    if (front1 == NULL && front2 == NULL)
    {
        printf("Equal");
    }
    else
    {
        printf("Not equal");
    }
}
void display(struct queue *front, struct queue *rear)
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
    int n;
    printf("Enter the number of elements to insert in first queue: ");
    scanf("%d", &n);
    int val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element to insert: ");
        scanf("%d", &val);
        enqueue(&front1, &rear1, val);
    }
    printf("Enter the number of elements to insert in second queue: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element to insert: ");
        scanf("%d", &val);
        enqueue(&front2, &rear2, val);
    }
    printf("Queue 1: ");
    display(front1, rear1);
    printf("Queue 2: ");
    display(front2, rear2);
    compare();
    return 0;
}