// Write a program to delete the kth node from a linked list.
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
void delete(int k)
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct node *temp1 = head; 
    if (k == 1)
    {
        head = temp1 -> next;
        free(temp1);
        return;
    }
    for (int i = 1; temp1 != NULL && i < k - 1; i++)
    {
        temp1 = temp1 -> next;
    }
    if (temp1 == NULL || temp1 -> next == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    else
    {

        struct node *next = temp1 -> next -> next;
        struct node *temp2 = temp1 -> next;
        free(temp2);
        temp1 -> next = next;
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
    int k;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &k);
    display();
    delete(k);
    printf("After removing kth node\n");
    display();
    return 0;
}