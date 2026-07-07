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
    struct stack *temp = top;
    if (temp -> next == NULL)
    {
        top = NULL;
        free(temp);
        return;
    }
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
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);
    return 0;
}