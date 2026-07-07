// Write a program to create a linear queue of 10 values.
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
    int val;
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &val);
        enqueue(val);
    }
    display();
    return 0;
}