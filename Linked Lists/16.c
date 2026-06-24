// Write a program to input an n digit number. Now, break this number into its individual digits and then store every single digit in a separate node thereby forming a linked list. For example, if you enter 12345, then there will 5 nodes in the list containing nodes with values 1, 2, 3, 4, 5.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert(int val)
{
    struct node *new = malloc(sizeof(struct node));
    new -> data = val;
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
void digit(int n, int val)
{
    int divisor = 1;
    for (int i = 0; i < n - 1; i++)
    {
        divisor *= 10;
    }
    for (int i = n-1; i >= 0; i--)
    {
        insert(val / divisor);
        val %= divisor;
        divisor /= 10;
    }
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of digits: ");
    scanf("%d", &n);
    int val;
    printf("Enter the number: ");
    scanf("%d", &val);
    digit(n, val);
    display();
    return 0;
}