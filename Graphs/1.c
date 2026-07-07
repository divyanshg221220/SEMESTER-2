// Write a program to create and print a graph.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
void create(struct node *Adj[], int v)
{
    struct node *new, *prev;
    int e, val;
    for(int i = 0; i < v; i++) 
    {
        prev = NULL;
        printf("Enter the number of edges of %d: ", i);
        scanf("%d", &e);
        for(int j = 0; j < e; j++)
        {
            printf("Enter the element %d of %d: ", j + 1, i);
            scanf("%d", &val);
            new = malloc(sizeof(struct node));
            if (new == NULL)
            {
                printf("OVERFLOW\n");
                return;
            }
            new -> vertex = val;
            new -> next = NULL;
            if (Adj[i] == NULL)
            {
                Adj[i] = new;
            }
            else
            {
                prev -> next = new;
            }
            prev = new;
        }
    }
}
void display(struct node *Adj[], int v)
{
    struct node *temp;
    for(int i = 0; i < v; i++)
    {
        temp = Adj[i];
        printf("%d: ", i);
        while(temp != NULL)
        {
            printf("%d -> ", temp -> vertex);
            temp = temp -> next;
        }
        printf("NULL\n");
    }
}
int main(int argc, char const *argv[])
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    struct node *Adj[v];
    for(int i = 0; i < v; i++)
    {
        Adj[i] = NULL;
    }
    create(Adj, v);
    display(Adj, v);
    return 0;
}