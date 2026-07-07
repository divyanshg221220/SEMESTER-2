// Write a program to create a queue which permits insertion at any vacant location at the rear end.
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        if (front <= 0)
        {
            printf("OVERFLOW\n");
            return;
        }
        int i, j;
        for (i = 0, j = front; j <= rear; i++, j++)
        {
            queue[i] = queue[j];
        }
        rear = rear - front;
        front = 0;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = val;
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("UNDERFLOW\n");
        return;
    }
    else
    {
        front++;
    }
    if (front > rear)
    {
        front = rear = -1;
    }
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("NULL\n");
        return;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    int choice, value;
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
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit\n");
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);
    return 0;
}