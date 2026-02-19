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
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            printf("value found at index: %d\n", i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("value not found\n");
    }
    return 0;
}
