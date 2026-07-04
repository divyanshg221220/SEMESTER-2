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
int InfixToPostfix(char *infix, char *postfix)
{
    int i = 0, j = 0;
    int expectOperand = 1;
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            if (!expectOperand)
            {
                postfix[j] = '\0';
                return 1;
            }
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            if (expectOperand)
            {
                postfix[j] = '\0';
                return 1;
            }
            while (top != NULL && top -> data != '(')
            {
                postfix[j++] = top -> data;
                pop();
            }
            if (top == NULL)
            {
                postfix[j] = '\0';
                return 1;
            }
            pop();
            expectOperand = 0;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
        {
            if (expectOperand)
            {
                postfix[j] = '\0';
                return 1;
            }
            while (top != NULL && top -> data != '(' && getPriority(top -> data) >= getPriority(infix[i]))
            {
                postfix[j++] = top -> data;
                pop();
            }
            push(infix[i]);
            expectOperand = 1;
        }
        else if (isdigit(infix[i]) || isalpha(infix[i]))
        {
            if (!expectOperand)
            {
                postfix[j] = '\0';
                return 1;
            }
            postfix[j++] = infix[i];
            expectOperand = 0;
        }
        else
        {
            postfix[j] = '\0';
            return 1;
        }
        i++;
    }
    if (expectOperand)
    {
        postfix[j] = '\0';
        return 1;
    }
    while (top != NULL)
    {
        if (top -> data == '(')
        {
            postfix[j] = '\0';
            return 1;
        }
        postfix[j++] = top -> data;
        pop();
    }
    postfix[j] = '\0';
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