// Write a program to create a queue using arrays which permits insertion at both the ends.
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
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &val);
        rear_enqueue(val);
    }
    display();
    printf("Enter the elements to insert: ");
    scanf("%d", &val);
    int choice;
    printf("1. Insertion at front\n");
    printf("2. Insertion at rear\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        front_enqueue(val);
        printf("After insertion at front\n");
        break;
    case 2:
        rear_enqueue(val);
        printf("After insertion at rear\n");
        break;
    default:
        printf("Invalid choice\n");
        return 1;
    }
    display();
    return 0;
}