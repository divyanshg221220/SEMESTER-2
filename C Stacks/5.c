// Write a program to input two stacks and compare their contents.
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top1 = NULL;
struct stack *top2 = NULL;
void push(struct stack **top, int val)
{
    struct stack *new = malloc(sizeof(struct stack));
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    new -> data = val;
    new -> next = *top;
    *top = new;
}
void pop(struct stack **top)
{
    if (*top == NULL)
    {
        return;
    }
    struct stack *temp = *top;
    *top = (*top) -> next;
    free(temp);
}
void compare()
{
    while (top1 != NULL && top2 != NULL)
    {
        if (top1 -> data != top2 -> data)
        {
            printf("Not equal");
            return;
        }
        pop(&top1);
        pop(&top2);
    }
    if (top1 == NULL && top2 == NULL)
    {
        printf("Equal");
    }
    else
    {
        printf("Not equal");
    }
}
void display(struct stack *top)
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
    int n;
    printf("Enter the number of elements to insert in first stack: ");
    scanf("%d", &n);
    int val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &val);
        push(&top1, val);
    }
    printf("Enter the number of elements to insert in second stack: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &val);
        push(&top2, val);
    }
    printf("Stack 1: ");
    display(top1);
    printf("Stack 2: ");
    display(top2);
    compare();
    return 0;
}