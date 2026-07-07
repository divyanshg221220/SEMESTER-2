// Write a program to merge two linked lists.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *head1 = NULL;
struct node *head2 = NULL;
void insert(struct node **head, int val)
{
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    new -> data = val;
    new -> next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    struct node *temp = *head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = new;
}
void merge()
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    while (temp1 != NULL)
    {
        insert(&head, temp1 -> data);
        temp1 = temp1 -> next;
    }
    while (temp2 != NULL)
    {
        insert(&head, temp2 -> data);
        temp2 = temp2 -> next;
    }
}
void display(struct node *head)
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
    printf("Enter the number of elements to insert in first linked list: ");
    scanf("%d", &n);
    int val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &val);
        insert(&head1, val);
    }
    printf("Enter the number of elements to insert in second linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &val);
        insert(&head2, val);
    }
    printf("Linked List 1: ");
    display(head1);
    printf("Linked List 2: ");
    display(head2);
    printf("Before merging\n");
    display(head);
    merge();
    printf("After merging\n");
    display(head);
    return 0;
}