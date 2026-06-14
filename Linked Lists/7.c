// Write a program to merge two linked lists.
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
    if (head1 == NULL)
    {
        head1 = head2;
        return;
    }
    struct node *temp = head1;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = head2;
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
    display(head1);
    display(head2);
    merge();
    display(head1);
    return 0;
}