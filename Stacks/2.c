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
int InfixToPostfix(char *exp, char *result)
{
    int i = 0;
    int j = 0;
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
                result[j++] = top -> data;
                pop();
            }
            if (top == NULL)
            {
                result[j] = '\0';
                return 1;
            }
            pop();
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%')
        {
            while (top != NULL && top -> data != '(' && getPriority(top -> data) >= getPriority(exp[i]))
            {
                result[j++] = top -> data;
                pop();
            }
            push(exp[i]);
        }
        else if (isdigit(exp[i]) || isalpha(exp[i]))
        {
            result[j++] = exp[i];
        }
        else
        {
            result[j] = '\0';
            return 1;
        }
        i++;
    }
    while (top != NULL)
    {
        if (top -> data == '(')
        {
            result[j] = '\0';
            return 1;
        }
        result[j++] = top -> data;
        pop();
    }
    result[j] = '\0';
    return 0;
}
int main(int argc, char const *argv[])
{
    char infix[100];
    char postfix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    if (InfixToPostfix(infix, postfix))
    {
        printf("Invalid");
    }
    else
    {
        printf("Postfix expression: %s", postfix);
    }
    return 0;
}