// Write a program to interchange the kth and the (k+1)th node of a circular doubly linked list.
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
void interchange(int k)
{
    if (head == NULL || head -> next == head)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct node *temp = head;
    if (k <= 0)
    {
        printf("Invalid\n");
        return;
    }
    for (int i = 1; i < k; i++)
    {
        temp = temp -> next;
        if (temp == head)
        {
            printf("Invalid\n");
            return;
        }
    }
    struct node *temp1 = temp;
    struct node *temp2 = temp -> next;
    if (temp2 == head)
    {
        printf("Invalid\n");
        return;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next -> prev = temp1;
    temp2 -> prev = temp1 -> prev;
    temp1 -> prev -> next = temp2;
    temp2 -> next = temp1;
    temp1 -> prev = temp2;
    if (temp1 == head)
    {
        head = temp2;
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
    int k;
    printf("Enter the position of the node to interchange: ");
    scanf("%d", &k);
    interchange(k);
    display();
    return 0;
}