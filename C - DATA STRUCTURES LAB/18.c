// Write a program to convert Infix expression to Prefix and Postfix
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
char stack[MAX];
int top =-1;
void push(char ch) {
    stack[++top] = ch;
}
char pop() {
    return stack[top--];
}
int precedence(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;
    for(i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if(isalnum(ch))
            postfix[k++] = ch;
        else if(ch == '(')
            push(ch);
        else if(ch == ')') {
            while(stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else {
            while(top !=-1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while(top !=-1)
        postfix[k++] = pop();
    postfix[k] = '\0';
}
void reverse(char exp[]) {
    int i, j;
    char temp;
    for(i = 0, j = strlen(exp)- 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}
void replaceBrackets(char exp[]) {
    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(')
            exp[i] = ')';
        else if(exp[i] == ')')
            exp[i] = '(';
    }
}
int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    printf("Enter Infix Expression: ");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    reverse(infix);
    replaceBrackets(infix);
    top =-1;
    infixToPostfix(infix, prefix);
    reverse(prefix);
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}