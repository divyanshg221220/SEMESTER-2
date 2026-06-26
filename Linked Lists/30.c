// Use the linked list of Question 28 and insert information about a new employee.
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
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("Id: %d, Name: %s\n", temp -> id, temp -> name);
        temp = temp -> next;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    int id;
    char name[25];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the id of employee %d: ", i + 1);
        scanf("%d", &id);
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", name);
        insert(id, name);
    }
    display();
    printf("Enter the id of new employee: ");
    scanf("%d", &id);
    printf("Enter the name of new employee: ");
    scanf("%s", name);
    insert(id, name);
    display();
    return 0;
}