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
void push(int val)
{
    struct stack *new = malloc(sizeof(struct stack));
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
int F(int n, int r)
{
    if (r == 0 || r == n)
    {
        return 1;
    }
    else
    {
        push(n);
        push(r);
        int result = F(n - 1, r) + F(n - 1, r - 1);
        pop();
        pop();
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