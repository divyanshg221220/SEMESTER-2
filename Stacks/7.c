// Write a program to compute F(n, r) where F(n, r) can be recursively defined as:
//   F(n, r) = F(n–1, r) + F(n–1, r–1)
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
int F(int n, int r)
{
    if (r == 0 || r == n)
    {
        return 1;
    }
    else
    {
        push(F(n - 1, r) + F(n - 1, r - 1));
        int result = pop();
        return result;
    }
}
int main(int argc, char const *argv[])
{
    int n, r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);
    printf("F(%d, %d) = %d\n", n, r, F(n, r));
    return 0;
}