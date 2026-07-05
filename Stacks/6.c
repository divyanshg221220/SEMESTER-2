// Write a program to compute F(x, y), where
//   F(x, y) = F(x-y, y) + 1 if y<=x
// And F(x, y) = 0 if x<y
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
int F(int x, int y)
{
    if (y <= x)
    {
        push(x);
        int result = F(x - y, y) + 1;
        pop();
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