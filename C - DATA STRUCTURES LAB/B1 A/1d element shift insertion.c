#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("array: ");
    for (int i = 0; i < n; i++)    
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    int pos, val;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (int i = n - 1; i >= pos; i--)
    {
        A[i + 1] = A[i];
    }
    A[pos] = val;
    printf("array: ");
    for (int i = 0; i < n; i++)    
    {
        printf("%d ", A[i]);
    }
    return 0;
}