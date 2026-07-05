// Write a program to compute F(x, y), where
//   F(x, y) = F(x-y, y) + 1 if y≤x
// And F(x, y) = 0 if x<y
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
int F(int x, int y)
{
    if (y <= x)
    {
        push(F(x - y, y) + 1);
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
    int x, y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("F(%d, %d) = %d\n", x, y, F(x, y));
    return 0;
}