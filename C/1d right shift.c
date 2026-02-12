#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i+1);
        scanf("%d", &A[i]);
    }
    printf("old array: ");
    for (int i = 0; i < n; i++)    
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    int temp = A[n-1];
    for (int i = n-1; i > 0; i--)
    {
        A[i] = A[i-1];
    }
    A[0] = temp;
    printf("new array: ");
    for (int i = 0; i < n; i++)    
    {
        printf("%d ", A[i]);
    }
    return 0;
}