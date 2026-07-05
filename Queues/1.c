// Write a program to calculate the number of items in a queue.
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
void count()
{
    struct queue *temp = front;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    printf("Number of items in a queue: %d\n", count);
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &val);
        enqueue(val);
    }
    display();
    count();    
    return 0;
}