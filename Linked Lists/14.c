// Write a program to
// (a) Delete the first occurrence of a given character in a linked list
// (b) Delete the last occurrence of a given character
// (c) Delete all the occurrences of a given character
#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
};
struct node *head = NULL;
void insert(char val)
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
void delete_first_occurrence(char val)
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL)
    {
        if (temp -> data == val)
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
}
void delete_last_occurrence(char val)
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct node *temp1 = head;
    struct node *prev1 = NULL;
    struct node *temp2 = NULL;
    struct node *prev2 = NULL;
    while (temp1 != NULL)
    {
        if (temp1 -> data == val)
        {
            prev2 = prev1;
            temp2 = temp1;
        }
        prev1 = temp1;
        temp1 = temp1 -> next;
    }
    if (temp2 != NULL)
    {
        if (prev2 == NULL)
        {
            head = temp2 -> next;
        }
        else
        {
            prev2 -> next = temp2 -> next;
        }
        free(temp2);
    }
}
void delete_all_occurrences(char val)
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL)
    {
        if (temp -> data == val)
        {
            if (prev == NULL)
            {
                head = temp -> next;
                free(temp);
                temp = head;
            }
            else
            {
                prev -> next = temp -> next;
                free(temp);
                temp = prev -> next;
            }
        }
        else
        {
            prev = temp;
            temp = temp -> next;
        }
    }
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%c -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    char val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf(" %c", &val);
        insert(val);
    }
    display();
    int choice;
    printf("1. Delete first occurrence\n");
    printf("2. Delete last occurrence\n");
    printf("3. Delete all occurrences\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter the character to delete: ");
    scanf(" %c", &val);
    switch (choice)
    {
        case 1:
            delete_first_occurrence(val);
            printf("After deleting first occurrence of a given character '%c' in a linked list\n", val);
            break;
        case 2:
            delete_last_occurrence(val);
            printf("After deleting last occurrence of a given character '%c' in a linked list\n", val);
            break;
        case 3:
            delete_all_occurrences(val);
            printf("After deleting all occurrences of a given character '%c' in a linked list\n", val);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    display();
    return 0;
}