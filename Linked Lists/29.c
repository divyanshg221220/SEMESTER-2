// Use the linked list of Question 28 so that it displays the record of a given employee only.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int id;
    char name[25];
    struct node *next;
};
struct node *head = NULL;
void insert(int id, char name[])
{
    struct node *new = malloc(sizeof(struct node));
    new -> id = id;
    strcpy(new -> name, name);
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
void display(int id)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp -> id == id)
        {
            printf("Id: %d, Name: %s\n", temp -> id, temp -> name);
            return;
        }
        temp = temp -> next;
    }
    printf("Not found\n");
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int id;
        char name[25];
        printf("Enter the id of employee %d: ", i + 1);
        scanf("%d", &id);
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", name);
        insert(id, name);
    }
    int id;
    printf("Enter the id of employee to display: ");
    scanf("%d", &id);
    display(id);
    return 0;
}