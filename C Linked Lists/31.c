// Use the linked list of Question 28 and delete information about an existing employee.
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
    if (new == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
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
void delete(int id)
{
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL)
    {
        if (temp -> id == id)
        {
            if (prev == NULL)
            {
                head = temp -> next;
            }
            else
            {
                prev -> next = temp -> next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp -> next;
    }
    printf("Not found\n");
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
    printf("Enter the id of employee to delete: ");
    scanf("%d", &id);
    delete(id);
    display();
    return 0;
}