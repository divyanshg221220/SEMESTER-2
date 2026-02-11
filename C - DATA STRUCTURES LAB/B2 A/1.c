#include <stdio.h>
void Insert(int LA[], int N, int K, int item)
{
    for (int i = N - 1; i > K; i--)
    {
        LA[i] = LA[i - 1];
    }
    LA[K] = item;
}
void Delete(int LA[], int N, int K, int item)
{
    item = LA[K];
    for (int i = K; i < N - 1; i++)
    {
        LA[i] = LA[i + 1];
    }
    LA[N - 1] = 0;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = 0;
    }
    int q;
    do
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from specific position\n");
        printf("7. Traversing / Display\n");
        printf("8. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &q);
        int val;
        if (q == 1 || q == 2 || q == 3)
        {
            printf("Enter element to insert: ");
            scanf("%d", &val);
        }
        switch (q)
        {
        case 1:
            Insert(A, n, 0, val);
            break;
        case 2:
            Insert(A, n, n - 1, val);
            break;
        case 3:
            {
                int K;
                printf("Enter index to insert at: ");
                scanf("%d", &K);
                Insert(A, n, K, val);
                break;
            }
        case 4:
            Delete(A, n, 0, val);
            break;
        case 5:
            Delete(A, n, n - 1, val);
            break;
        case 6:
            {
                int K;
                printf("Enter index to delete from: ");
                scanf("%d", &K);
                Delete(A, n, K, val);
                break;
            }
        case 7:
            for (int i = 0; i < n; i++)
                printf("%d ", A[i]);
            printf("\n");
            break;
        case 8:
            break;
        default:
            printf("Invalid Input\n");
        }
    } while (q != 8);
    return 0;
}
