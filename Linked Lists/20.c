// Write a program to make the first element of singly linked list as the last element of the list.
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
void first_to_last()
{
    if (head == NULL || head -> next == NULL)
    {
        return;
    }
    struct node *first = head;
    struct node *last = head;
    head = head -> next;
    while (last -> next != NULL)
    {
        last = last -> next;
    }
    last -> next = first;
    first -> next = NULL;
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
    first_to_last();
    printf("After replacing\n");
    display();
    return 0;
}