// Write a program to multiply a polynomial with a given number.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coefficient;
    int exponent;
    struct node *next;
};
struct node *head = NULL;
void insert(int val, int i)
{
    struct node *new = malloc(sizeof(struct node));
    new -> coefficient = val;
    new -> exponent = i;
    new -> next = NULL;
    if (head == NULL)
    {
        head = new;
        return;
    }
    struct node *temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = new;
}
void multiply(int val)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        temp -> coefficient *= val;
        temp = temp -> next;
    }
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d x ^ %d", temp -> coefficient, temp -> exponent);
        if (temp -> next != NULL)
        {
            printf(" + ");
        }
        temp = temp -> next;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the degree of polynomial: ");
    scanf("%d", &n);
    int val;
    for (int i = n; i >= 0; i--)
    {
        printf("Enter the element x ^ %d: ", i);
        scanf("%d", &val);
        insert(val, i);
    }
    display();
    printf("Enter the number to multiply: ");
    scanf("%d", &val);
    multiply(val);
    display();
    return 0;
}