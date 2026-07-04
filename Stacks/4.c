// Write a program to implement a stack that stores names of students in the class.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    char data[25];
    struct stack *next;
};
struct stack *top = NULL;
void push(char *val)
{
    struct stack *new = malloc(sizeof(struct stack));
    strcpy(new -> data, val);
    new -> next = top;
    top = new;
}
void display()
{
    struct stack *temp = top;
    while (temp != NULL)
    {
        printf("%s -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char val[25];
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", &val);
        push(val);
    }
    printf("Students: ");
    display();
    return 0;
}