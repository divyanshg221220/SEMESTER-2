// Write a program that creates a singly linked list. Use a function isSorted that returns 1 if the list is sorted and 0 otherwise.
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
int isSorted()
{
    struct node *temp = head;
    while (temp != NULL && temp -> next != NULL)
    {
        if (temp -> data > temp -> next -> data)
        {
            return 0;
        }
        temp = temp -> next;
    }
    return 1;
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
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &val);
        insert(val);
    }
    display();
    if (isSorted())
    {
        printf("Sorted");
    }
    else
    {
        printf("Not sorted");
    }
    return 0;
}