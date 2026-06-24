// Write a program to add the values of the nodes of a linked list and then calculate the mean.
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
float mean(int n)
{
    if (n == 0)
    {
        return 0;
    }
    struct node *temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        sum += temp -> data;
        temp = temp -> next;
    }
    return (float)sum / n;
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
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insert(val);
    }
    display();
    printf("Mean: %.2f", mean(n));
    return 0;
}