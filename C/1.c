// Write a program to perform insertion and deletion operations on an array
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    int choice;
    do
    {
        printf("Array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            {
                int index, element;
                printf("Enter the index: ");
                scanf("%d", &index);
                printf("Enter the element: ");
                scanf("%d", &element);
                for (int i = n; i > index; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[index] = element;
                break;
            }
        case 2:
            {
                int index;
                printf("Enter the index: ");
                scanf("%d", &index);
                for (int i = index; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                arr[n - 1] = 0;
                break;
            }
        case 3:
            printf("Exit");
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    } while (choice != 3);
    
    return 0;
}