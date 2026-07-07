// Write a program to reverse the elements of a queue.
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
void reverse()
{
    if (front == NULL)
    {
        return;
    }
    struct queue *temp = front;
    int val;
    val = temp -> data;
    front = front -> next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    reverse();
    enqueue(val);
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
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &val);
        enqueue(val);
    }
    display();
    reverse();
    printf("After reversing\n");
    display();
    return 0;
}