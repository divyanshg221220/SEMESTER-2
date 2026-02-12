#include <stdio.h>
int main(int argc, char const *argv[])
{
    int x, y;
    printf("Enter number of rows: ");
    scanf("%d", &x);
    printf("Enter number of columns: ");
    scanf("%d", &y);
    int A[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("Enter (%d, %d) element: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("array: \n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}