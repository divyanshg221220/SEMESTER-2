// Write a program to delete a node from a circular header linked list.
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
    header -> data = 0;
    header -> next = header;
}
void insert(int val)
{
    struct node *new = malloc(sizeof(struct node));
    new -> data = val;
    new -> next = header;
    struct node *temp = header;
    while (temp -> next != header)
    {
        temp = temp -> next;
    }
    temp -> next = new;
}
void delete(int pos)
{
    if (header -> next == header)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct node *prev = header;
    if (pos <= 0)
    {
        printf("Invalid\n");
        return;
    }
    for (int i = 1; i < pos; i++)
    {
        prev = prev -> next;
        if (prev == header)
        {
            printf("Invalid\n");
            return;
        }
    }
    struct node *temp = prev -> next;
    if (temp == header)
    {
        printf("Invalid\n");
        return;
    }
    prev -> next = temp -> next;
    free(temp);
}
void display()
{
    printf("HEADER -> ");
    struct node *temp = header -> next;
    while (temp != header)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("HEADER\n");
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
    int pos;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);
    delete(pos);
    display();
    return 0;
}