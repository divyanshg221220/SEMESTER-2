#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("array: ");
    for (int i = 0; i < n; i++)    
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    int pos, val;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    val = A[pos];
    for (int i = pos; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }
    A[n - 1] = 0;
    printf("array: ");
    for (int i = 0; i < n; i++)    
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("deleted element: %d\n", val);
    return 0;
}