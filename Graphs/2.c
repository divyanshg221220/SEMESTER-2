// Write a program to determine whether there is at least one path from the source to the destination.
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
int path(struct node *Adj[], int visited[], int src, int dest)
{
    if (src == dest)
    {
        return 1;
    }
    visited[src] = 1;
    struct node *temp = Adj[src];
    while (temp != NULL)
    {
        if (!visited[temp -> vertex])
        {
            if (path(Adj, visited, temp -> vertex, dest))
            {
                return 1;
            }
        }
        temp = temp -> next;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int v, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    struct node *Adj[v];
    int visited[v];
    for(int i = 0; i < v; i++)
    {
        Adj[i] = NULL;
        visited[i] = 0;
    }
    create(Adj, v);
    printf("Enter source vertex: ");
    scanf("%d", &src);
    printf("Enter destination vertex: ");
    scanf("%d", &dest);
    if (path(Adj, visited, src, dest))
    {
        printf("Path exists");
    }
    else
    {
        printf("No path exists");
    }
    return 0;
}