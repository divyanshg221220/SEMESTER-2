// Write a program to form a linked list of floating point numbers. Display the sum and mean of these numbers.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    float data;
    struct node *next;
};
struct node *head = NULL;
void insert(float val)
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
        return;
    }
    struct node *temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = new;
}
void sum_and_mean(int n)
{
    if (n == 0)
    {
        printf("Mean: 0.00");
    }
    struct node *temp = head;
    float sum = 0;
    while (temp != NULL)
    {
        sum += temp -> data;
        temp = temp -> next;
    }
    printf("Sum: %.2f\n", sum);
    printf("Mean: %.2f", sum / n);
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%f -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%f", &val);
        insert(val);
    }
    display();
    sum_and_mean(n);
    return 0;
}