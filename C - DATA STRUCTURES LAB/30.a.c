// Write a program to perform Graph Traversals (BFS and DFS)
// (BFS using Adjacency Matrix)
#include <stdio.h>
int adj[10][10], visited[10], queue[10];
int front = 0, rear =-1;
void bfs(int start, int n) {
    visited[start] = 1;
    queue[++rear] = start;
    while(front <= rear) {
        int v = queue[front++];
        printf("%d ", v);
        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}
int main() {
    int n, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    bfs(start, n);
    return 0;
}