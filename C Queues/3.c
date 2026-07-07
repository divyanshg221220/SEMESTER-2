// Write a program to create a queue using arrays which permits insertion at both the ends.
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void front_enqueue(int val)
{
    if (front == 0)
    {
        printf("OVERFLOW\n");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            front--;
        }
        queue[front] = val;
    }
}
void rear_enqueue(int val)
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
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = val;
    }
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
    int choice, val;
    do
    {
        printf("1. Enqueue at front\n");
        printf("2. Enqueue at rear\n");
        printf("3. Dequeue\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
            dequeue();
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