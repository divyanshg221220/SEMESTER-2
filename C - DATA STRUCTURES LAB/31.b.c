// Write a program to find Minimum Spanning Tree using Kruskal and Prim Algorithms
// (Kruskal’s Algorithm)
#include <stdio.h>
int parent[10];
int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
int main() {
    int n, cost[10][10], min, a, b, u, v;
    int ne = 1, mincost = 0;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    while(ne < n) {
        min = 999;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
        u = find(u);
        v = find(v);
        if(uni(u,v)) {
            printf("Edge %d-%d : %d\n", a, b, min);
            mincost += min;
            ne++;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Total cost of MST = %d\n", mincost);
    return 0;
}