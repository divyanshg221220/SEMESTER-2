// Write a program to count the number of non-zero values in a circular linked list.
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
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    new -> data = val;
    if (head == NULL)
    {
        head = new;
        new -> next = head;
        return;
    }
    struct node *temp = head;
    while (temp -> next != head)
    {
        temp = temp -> next;
    }
    temp -> next = new;
    new -> next = head;
}
void count()
{
    struct node *temp = head;
    int count = 0;
    do
    {
        if (temp -> data != 0)
        {
            count++;
        }
        temp = temp -> next;
    } while (temp != head);
    
    printf("Number of non-zero elements: %d", count);
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
        insert(val);
    }
    display();
    count();
    return 0;
}