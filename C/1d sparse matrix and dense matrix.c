#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("array: ");
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        if (arr[i] == 0)
        {
            count++;
        }
    }
    printf("\n");
    if (n/2 < count)
    {
        printf("sparse matrix");
    }
    else
    {
        printf("dense matrix");
    }
    return 0;
}
