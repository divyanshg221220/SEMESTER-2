// Write a program to compute Lambda(n) for all positive values of n where Lambda(n) can be recursively defined as:
//   Lambda(n) = Lambda(n/2) + 1 if n>1
// and Lambda(n) = 0 if n =1
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
int push(int val)
{
    struct stack *new = malloc(sizeof(struct stack));
    new -> data = val;
    new -> next = top;
    top = new;
    return 0;
}
int pop()
{
    if (top == NULL)
    {
        return 0;
    }
    int val;
    struct stack *temp = top;
    val = temp -> data;
    top = top -> next;
    free(temp);
    return val;
}
int Lambda(int n)
{
    if (n > 1)
    {
        push(Lambda(n / 2) + 1);
        int result = pop();
        return result;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Lambda(%d) = %d\n", n, Lambda(n));
    return 0;
}