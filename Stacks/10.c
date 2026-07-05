// Write a program to reverse a string using recursion.
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    char data;
    struct stack *next;
};
struct stack *top = NULL;
char push(char val)
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
    return '\0';
}
char pop()
{
    if (top == NULL)
    {
        return '\0';
    }
    struct stack *temp = top;
    char val;
    val = temp -> data;
    top = top -> next;
    free(temp);
    return val;
}
void reverse(char *str, int i)
{
    if (str[i] == '\0')
    {
        return;
    }
    push(str[i]);
    reverse(str, i + 1);
    static int j = 0;
    str[j++] = pop();
}
int main(int argc, char const *argv[])
{
    char str[25];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse(str, 0);
    printf("Reversed string: %s", str);
    return 0;
}