// Write a program to check whether an expression has Balanced Parenthesis
#include <stdio.h>
#include <string.h>
#define MAX 50
char stack[MAX];
int top =-1;
void push(char ch) {
    stack[++top] = ch;
}
char pop() {
    return stack[top--];
}
int isMatching(char open, char close) {
    if(open == '(' && close == ')') return 1;
    if(open == '{' && close == '}') return 1;
    if(open == '[' && close == ']') return 1;
    return 0;
}
int main() {
    char exp[MAX];
    int i;
    printf("Enter expression: ");
    gets(exp);
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == -1) {
                printf("Expression is NOT Balanced\n");
                return 0;
            }
            if(!isMatching(pop(), exp[i])) {
                printf("Expression is NOT Balanced\n");
                return 0;
            }
        }
    }
    if(top == -1)
        printf("Expression is Balanced\n");
    else
        printf("Expression is NOT Balanced\n");
    return 0;
}