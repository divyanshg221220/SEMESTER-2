// Write a program that prints the nth element from the end of a linked list in a single pass.
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
void display_kth(int k)
{
    struct node *temp1 = head;
    struct node *temp2 = head;
    for (int i = 0; i < k; i++)
    {
        if (temp1 == NULL)
        {
            printf("Invalid\n");
            return;
        }
        temp1 = temp1 -> next;
    }
    while (temp1 != NULL)
    {
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    printf("%d\n",temp2 -> data);
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
    int k;
    printf("Enter the position of the node to display: ");
    scanf("%d", &k);
    display_kth(k);
    return 0;
}