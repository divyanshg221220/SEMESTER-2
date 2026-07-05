// Write a program to delete the first element of a doubly linked list. Add this node as the last node of the list.
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
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
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
void delete_and_add()
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    int val = head -> data;
    struct node *temp = head;
    head = head -> next;
    if (head != NULL)
    {
        head -> prev = NULL;
    }
    free(temp);
    insert(val);
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
    delete_and_add();
    printf("After deleting and adding\n");
    display();
    return 0;
}