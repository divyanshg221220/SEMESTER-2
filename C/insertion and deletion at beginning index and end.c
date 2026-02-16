#include <stdio.h>
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
    int q, elements = 0;
    do
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &q);
        switch (q)
        {
        case 1:
            {
                if (elements == n)
                {
                    printf("Overflow\n");
                    break;
                }
                int val, q1;
                printf("Enter element to insert: ");
                scanf("%d", &val);
                printf("1. Insert at beginning\n");
                printf("2. Insert at index\n");
                printf("3. Insert at end\n");
                printf("Enter your choice : ");
                scanf("%d", &q1);
                switch (q1)
                {
                case 1:
                    for (int i = n - 1; i > 0; i--)
                    {
                        A[i] = A[i - 1];
                    }
                    A[0] = val;
                    elements++;
                    break;
                case 2:
                    {
                        int index;
                        printf("Enter index: ");
                        scanf("%d", &index);
                        for (int i = n - 1; i > index; i--)
                        {
                            A[i] = A[i - 1];
                        }
                        A[index] = val;
                        elements++;
                        break;
                    };
                case 3:
                    A[n - 1] = val;
                    elements++;
                    break;
                default:
                    printf("Invalid Input\n");
                    break;
                }
                break;
            };
        case 2:
            {
                if (elements == 0)
                {
                    printf("Underflow\n");
                    break;
                }
                int q2;
                printf("1. Delete at beginning\n");
                printf("2. Delete at index\n");
                printf("3. Delete at end\n");
                printf("Enter your choice : ");
                scanf("%d", &q2);
                switch (q2)
                {
                case 1:
                    for (int i = 0; i < n - 1; i++)
                    {
                        A[i] = A[i + 1];
                    }
                    A[n - 1] = 0;
                    elements--;
                    break;
                case 2:
                    {
                        int index;
                        printf("Enter index: ");
                        scanf("%d", &index);
                        for (int i = index; i < n - 1; i++)
                        {
                            A[i] = A[i + 1];
                        }
                        elements--;
                        break;
                    };
                case 3:
                    A[n - 1] = 0;
                    elements--;
                    break;
                default:
                    printf("Invalid Input\n");
                    break;
                }
                break;
            };
        case 3:
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    } while (q != 3);
    return 0;
}