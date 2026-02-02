#include <stdio.h>
int linear_search(int A[], int n, int VAL)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == VAL)
        {
            return i;
        }
    }
    return -1;
}
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
    int VAL;
    printf("Enter value to search: ");
    scanf("%d", &VAL);
    int result = linear_search(A, n, VAL);
    if (result != -1)
    {
        printf("element found at index: %d\n", result);
    }
    else
    {
        printf("element not found in the array.\n");
    }
    return 0;
}
