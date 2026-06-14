// Write a program that copies a circular linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
void insert(struct node **head, int val)
{
    struct node *new = malloc(sizeof(struct node));
    new -> data = val;
    new -> next = NULL;
    if (*head == NULL)
    {
        *head = new;
        new -> next = *head;
        return;
    }
    struct node *temp = *head;
    while (temp -> next != *head)
    {
        temp = temp -> next;
    }
    temp -> next = new;
    new -> next = *head;
}
void copy()
{
    if (head1 == NULL)
    {
        return;
    }
    struct node *temp = head1;
    do
    {
        insert(&head2, temp -> data);
        temp = temp -> next;
    } while (temp != head1);
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    struct node *temp = head;
    do
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    } while (temp != head);
    printf("HEAD\n");
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
        insert(&head1, val);
    }
    printf("Linked List 1: ");
    display(head1);
    printf("Linked List 2: ");
    display(head2);
    copy();
    printf("After copying\n");
    printf("Linked List 2: ");
    display(head2);
    return 0;
}