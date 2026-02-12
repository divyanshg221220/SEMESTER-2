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
    printf("array: ");
    for (int i = 0; i < n; i++)    
    {
        printf("%d ", A[i]);
    }
    return 0;
}