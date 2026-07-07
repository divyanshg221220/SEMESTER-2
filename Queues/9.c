// Write a program to create a queue from a stack.
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
void push(int val)
{
    struct stack *new = malloc(sizeof(struct stack));
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    new -> data = val;
    new -> next = top;
    top = new;
}
void pop()
{
    if (top == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct stack *temp = top;
    top = top -> next;
    free(temp);
}
void enqueue(int val)
{
    push(val);
}
void dequeue()
{
    if (top == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    if (top -> next == NULL)
    {
        free(top);
        top = NULL;
        return;
    }
    struct stack *temp = top;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    struct stack *prev = top;
    while (prev -> next != temp)
    {
        prev = prev -> next;
    }
    prev -> next = NULL;
    free(temp);
}
void display()
{
    struct stack *temp = top;
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
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Enqueue\n");
        printf("4. Dequeue\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Enter the element: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 4:
            dequeue();
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