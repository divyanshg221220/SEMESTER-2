// Write a program that prints minimum and maximum values in a linked list that stores integer values.
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
void min(int n)
{
    if (n == 0)
    {
        return 0;
    }
    struct node *temp = head;
    int min = temp -> data;
    while (temp != NULL)
    {
        if (temp -> data < min)
        {
            min = temp -> data;
        }
        temp = temp -> next;
    }
    printf("Minimum: %d\n", min);
}
void max(int n)
{
    if (n == 0)
    {
        return 0;
    }
    struct node *temp = head;
    int max = temp -> data;
    while (temp != NULL)
    {
        if (temp -> data > max)
        {
            max = temp -> data;
        }
        temp = temp -> next;
    }
    printf("Maximum: %d\n", max);
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
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insert(val);
    }
    display();
    min(n);
    max(n);
    return 0;
}