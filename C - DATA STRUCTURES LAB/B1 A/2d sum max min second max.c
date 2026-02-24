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
            printf("Enter (%d, %d) element: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    int sum = 0, max = A[0][0], min = A[0][0];
    printf("array: \n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", A[i][j]);
            sum += A[i][j];
            if (max < A[i][j])
            {
                max = A[i][j];
            }
            if (min > A[i][j])
            {
                min = A[i][j];
            }
        }
        printf("\n");
    }
    int secondMax = A[0][0];
    for (int  i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (secondMax < A[i][j] && A[i][j] < max)
            {
                secondMax = A[i][j];
            }
        }
    }
    printf("sum of all elements: %d\n", sum);
    printf("max: %d\n", max);
    printf("min: %d\n", min);
    printf("second max: %d\n", secondMax);
    return 0;
}