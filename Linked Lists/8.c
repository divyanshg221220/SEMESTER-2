// Write a program to sort the values stored in a doubly circular linked list.
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
    if (head == NULL)
    {
        head = new;
        new -> next = head;
        new -> prev = head;
        return;
    }
    struct node *temp = head;
    while (temp -> next != head)
    {
        temp = temp -> next;
    }
    temp -> next = new;
    new -> prev = temp;
    new -> next = head;
    head -> prev = new;
}
void sort()
{
    if (head == NULL || head -> next == head)
    {
        return;
    }
    struct node *i, *j;
    int temp;
    for (i = head; i -> next != head; i = i -> next)
    {
        for (j = i -> next; j != head; j = j -> next)
        {
            if (i -> data > j -> data)
            {
                temp = i -> data;
                i -> data = j -> data;
                j -> data = temp;
            }
        }
    }
}
void display()
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    struct node *temp = head;
    do
    {
        printf("%d <-> ", temp -> data);
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
        insert(val);
    }
    display();
    sort();
    printf("After sorting\n");
    display();
    return 0;
}