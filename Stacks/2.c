// Write a program to convert the expression “a+b” into “ab+”.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct stack
{
    char data;
    struct stack *next;
};
struct stack *top = NULL;
void push(char val)
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
        return;
    }
    struct stack *temp = top;
    top = top -> next;
    free(temp);
}
int getPriority(char op)
{
    if (op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    if (op == '+' || op == '-')
    {
        return 1;
    }
    return 0;
}
void InfixToPostfix(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (top != NULL && top -> data != '(')
            {
                printf("%c", top -> data);
                pop();
            }
            if (top == NULL)
            {
                printf("\nInvalid");
                return;
            }
            pop();
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%')
        {
            while (top != NULL && top -> data != '(' && getPriority(top -> data) >= getPriority(exp[i]))
            {
                printf("%c", top -> data);
                pop();
            }
            push(exp[i]);
        }
        else if (isdigit(exp[i]) || isalpha(exp[i]))
        {
            printf("%c", exp[i]);
        }
        else
        {
            printf("\nInvalid");
            return;
        }
        i++;
    }
    while (top != NULL)
    {
        if (top -> data == '(')
        {
            printf("\nInvalid");
            return;
        }
        printf("%c", top -> data);
        pop();
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s", exp);
    printf("Postfix expression: ");
    InfixToPostfix(exp);
    return 0;
}