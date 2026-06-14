// Write a program that removes all nodes that have duplicate information.
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
void delete()
{
    struct node *temp1 = head;
    while (temp1 != NULL)
    {
        struct node *prev = temp1;
        struct node *temp2 = temp1 -> next;
        while (temp2 != NULL)
        {
            if (temp1 -> data == temp2 -> data)
            {
                prev -> next = temp2 -> next;
                free(temp2);
                temp2 = prev -> next;
            }
            else
            {
                prev = temp2;
                temp2 = temp2 -> next;
            }
        }
        temp1 = temp1 -> next;
    }
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
    delete();
    printf("After removing duplicates: ");
    display();
    return 0;
}