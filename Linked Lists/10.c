// Write a program to delete the first, last, and middle node of a header linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *header = NULL;
__attribute__((constructor))
void init()
{
    header = malloc(sizeof(struct node));
    header -> data = -1;
    header -> next = NULL;
}
void insert(int val)
{
    struct node *new = malloc(sizeof(struct node));
    new -> data = val;
    new -> next = NULL;
    struct node *temp = header;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = new;
}
void delete(int pos)
{
    if (header -> next == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct node *prev = header;
    for (int i = 0; i < pos; i++)
    {
        prev = prev -> next;
    }
    struct node *temp = prev -> next;
    prev -> next = temp -> next;
    free(temp);
}
void display()
{
    printf("HEADER -> ");
    struct node *temp = header -> next;
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
    delete(0);
    printf("After deleting first\n");
    display();
    n--;
    delete(n - 1);
    printf("After deleting last\n");
    display();
    n--;
    delete(n / 2);
    printf("After deleting middle\n");
    display();
    return 0;
}