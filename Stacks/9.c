// Write a program to compute F(M, N) where F(M, N) can be recursively defined as:
//   F(M,N) = 1 if M=0 or M≥N≥1
// and F(M,N) = F(M–1,N) + F(M–1, N–1), otherwise
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
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
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
int F(int M, int N)
{
    if (M == 0 || (M >= N && N >= 1))
    {
        return 1;
    }
    else
    {
        push(F(M - 1, N) + F(M - 1, N - 1));
        int result = pop();
        return result;
    }
}
int main(int argc, char const *argv[])
{
    int M, N;
    printf("Enter M: ");
    scanf("%d", &M);
    printf("Enter N: ");
    scanf("%d", &N);
    printf("F(%d, %d) = %d", M, N, F(M, N));
    return 0;
}