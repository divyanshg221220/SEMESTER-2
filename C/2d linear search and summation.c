#include <stdio.h>
int main(int argc, char const *argv[])
{
    int x, y;
    printf("Enter number of rows: ");
    scanf("%d", &x);
    printf("Enter number of columns: ");
    scanf("%d", &y);
    int matrix[x][y], sum = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("Enter (%d, %d) element: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
            sum += matrix[i][j];
        }
    }
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (matrix[i][j] == val)
            {
                printf("value found at index: (%d, %d)\n", i+1, j+1);
                found = 1;
            }
        }
    }
    if (!found)
    {
        printf("value not found\n");
    }
    printf("sum: %d\n", sum);
    return 0;
}