// Write a program to interchange the value of the first element with the last element, second element with second last element, so on and so forth of a doubly linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
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
        new -> prev = NULL;
        return;
    }
    struct node *temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = new;
    new -> prev = temp;
}
void interchange()
{
    if (head == NULL)
    {
        return;
    }
    struct node *start = head;
    struct node *end = head;
    while (end -> next != NULL)
    {
        end = end -> next;
    }
    while (start != end && start -> prev != end)
    {
        int temp = start -> data;
        start -> data = end -> data;
        end -> data = temp;
        start = start -> next;
        end = end -> prev;
    }
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp -> data);
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
    interchange();
    printf("After interchanging\n");
    display();
    return 0;
}