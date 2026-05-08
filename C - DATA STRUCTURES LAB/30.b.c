// Write a program to perform Graph Traversals (BFS and DFS)
// (DFS using Adjacency Matrix)
#include <stdio.h>
int adj[10][10], visited[10];
int n;
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i])
            dfs(i);
    }
}
int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    dfs(start);
    return 0;
}