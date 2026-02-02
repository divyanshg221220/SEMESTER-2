#include <stdio.h>
void Linear_Search(int A[], int n, int VAL)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == VAL)
        {
            found = 1;
            printf("element found at index: %d\n", i);
        }
    }
    if (found == 0)
    {
        printf("element not found in the array.\n");
    }
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
    Linear_Search(A, n, VAL);
    return 0;
}