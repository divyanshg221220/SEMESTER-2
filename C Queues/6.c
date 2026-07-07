// Write a program to create a queue using arrays which permits deletion from both the ends.
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        printf("OVERFLOW\n");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        queue[++rear] = val;
    }
}
void front_dequeue()
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
}
void rear_dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("UNDERFLOW\n");
        return;
    }
    else
    {
        rear--;
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
        printf("2. Dequeue at front\n");
        printf("3. Dequeue at rear\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
            front_dequeue();
            break;
        case 3:
            rear_dequeue();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 5);
    return 0;
}