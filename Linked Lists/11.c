// Write a program to create a linked list from an already given list. The new linked list must contain every alternate element of the existing linked list.
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
void alternate()
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    while (temp1 != NULL)
    {
        insert(&head2, temp1 -> data);
        temp1 = temp1 -> next;
        if (temp1 != NULL)
        {
            temp1 = temp1 -> next;
        }
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
    alternate();
    printf("Linked List 2: ");
    display(head2);
    return 0;
}