// WAP to check whether a matrix is a Sparse or not, Also WAP to check balanced paranthesis.
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
    int row, col, i, j, a[10][10], count = 0;
    printf("Enter number of rows:\n");
    scanf("%d", &row);
    printf("Enter number of columns:\n");
    scanf("%d", &col);
    printf("Enter elements of the matrix:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Elements of the matrix are:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(a[i][j] == 0)
                count++;
        }
    }
    if(count > (row * col) / 2)
        printf("Matrix is a sparse matrix\n");
    else
        printf("Matrix is not a sparse matrix\n");
    getchar();
    char exp[MAX];
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