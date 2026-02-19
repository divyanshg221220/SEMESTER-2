#include <stdio.h>
int main(int argc, char const *argv[])
{
    int x, y;
    printf("Enter number of rows: ");
    scanf("%d", &x);
    printf("Enter number of columns: ");
    scanf("%d", &y);
    int matrix[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("Enter (%d, %d) element: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    int count_zero = 0;
    printf("matrix: \n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", matrix[i][j]);
            if (matrix[i][j] == 0)
            {
                count_zero++;
            }
        }
        printf("\n");
    }
    if (count_zero > (x*y)/2)
    {
        printf("sparse matrix");
    }
    else
    {
        printf("dense matrix");
    }
    return 0;
}