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
    int index, found = 0;
    printf("Enter index: ");
    scanf("%d", &index);
    for (int i = 0; i < n; i++)
    {
        if (i == index)
        {
            found = 1;
            printf("Enter value: ");
            scanf("%d", &A[i]);
        }
    }
    if (found == 0)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("new array: ");
        for (int i = 0; i < n; i++)    
        {
            printf("%d ", A[i]);
        }
    }
    return 0;
}