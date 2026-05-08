// Write a program to find Minimum Spanning Tree using Kruskal and Prim Algorithms
// (Prim’s Algorithm)
#include <stdio.h>
#define INF 999
int main() {
    int n, cost[10][10], visited[10]={0};
    int min, u=0, v=0, total=0;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    visited[0]=1;
    for(int count=0; count<n-1; count++) {
        min = INF;
        for(int i=0;i<n;i++) {
            if(visited[i]) {
                for(int j=0;j<n;j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v]=1;
        total += min;
        printf("Edge %d-%d : %d\n", u, v, min);
    }
    printf("Total cost of MST = %d\n", total);
    return 0;
}