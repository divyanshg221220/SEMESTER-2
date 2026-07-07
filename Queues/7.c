// Write a program to create a queue using arrays which permits insertion and deletion at both the ends.
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
        printf("1. Enqueue at front\n");
        printf("2. Enqueue at rear\n");
        printf("3. Dequeue at front\n");
        printf("4. Dequeue at rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &value);
            front_enqueue(value);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &value);
            rear_enqueue(value);
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
    return 0;
}