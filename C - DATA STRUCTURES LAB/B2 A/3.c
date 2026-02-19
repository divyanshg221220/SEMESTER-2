#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n1;
    printf("Enter the degree of first polynomial: ");
    scanf("%d", &n1);
    int coefficients1[n1 + 1];
    for (int i = n1; i >= 0; i--)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &coefficients1[i]);
    }
    printf("polynomial: ");
    for (int i = n1; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d", coefficients1[i]);
        }
        else if (i == 1)
        {
            printf("%dx", coefficients1[i]);
        }
        else
        {
            printf("%dx^%d", coefficients1[i], i);
        }
        if (i > 0)            
        {
            printf(" + ");
        }
    }
    int n2;
    printf("\nEnter the degree of the second polynomial: ");
    scanf("%d", &n2);
    int coefficients2[n2 + 1];
    for (int i = n2; i >= 0; i--)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &coefficients2[i]);
    }
    printf("polynomial: ");
    for (int i = n2; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d", coefficients2[i]);
        }
        else if (i == 1)
        {
            printf("%dx", coefficients2[i]);
        }
        else
        {
            printf("%dx^%d", coefficients2[i], i);
        }
        if (i > 0)
        {
            printf(" + ");
        }
    }
    printf("\n");
    int choice;
    printf("1. ADDITION\n");
    printf("2. SUBTRACTION\n");
    printf("3. MULTIPLICATION\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        {
            int result_degree = (n1 > n2) ? n1 : n2;
            int result_coefficients[result_degree + 1];
            for (int i = 0; i <= result_degree; i++)
            {
                int coeff1 = (i <= n1) ? coefficients1[i] : 0;
                int coeff2 = (i <= n2) ? coefficients2[i] : 0;
                result_coefficients[i] = coeff1 + coeff2;
            }
            printf("Result of addition: ");
            for (int i = result_degree; i >= 0; i--)
            {
                if (i == 0)
                {
                    printf("%d", result_coefficients[i]);
                }
                else if (i == 1)
                {
                    printf("%dx", result_coefficients[i]);
                }
                else
                {
                    printf("%dx^%d", result_coefficients[i], i);
                }
                if (i > 0)
                {
                    printf(" + ");
                }
            }
        }
        break;
    case 2:
        {
            int result_degree = (n1 > n2) ? n1 : n2;
            int result_coefficients[result_degree + 1];
            for (int i = 0; i <= result_degree; i++)
            {
                int coeff1 = (i <= n1) ? coefficients1[i] : 0;
                int coeff2 = (i <= n2) ? coefficients2[i] : 0;
                result_coefficients[i] = coeff1 - coeff2;
            }
            printf("Result of subtraction: ");
            for (int i = result_degree; i >= 0; i--)
            {
                if (i == 0)
                {
                    printf("%d", result_coefficients[i]);
                }
                else if (i == 1)
                {
                    printf("%dx", result_coefficients[i]);
                }
                else
                {
                    printf("%dx^%d", result_coefficients[i], i);
                }
                if (i > 0)
                {
                    printf(" + ");
                }
            }
        }
        break;
    case 3:
        {
            int result_degree = n1 + n2;
            int result_coefficients[result_degree + 1];
            for (int i = 0; i <= result_degree; i++)
            {
                result_coefficients[i] = 0;
            }
            for (int i = 0; i <= n1; i++)
            {
                for (int j = 0; j <= n2; j++)
                {
                    result_coefficients[i + j] += coefficients1[i] * coefficients2[j];
                }
            }
            printf("Result of multiplication: ");
            for (int i = result_degree; i >= 0; i--)
            {           
                    if (i == 0)
                    {
                        printf("%d", result_coefficients[i]);
                    }
                    else if (i == 1)
                    {
                        printf("%dx", result_coefficients[i]);
                    }
                    else
                    {
                        printf("%dx^%d", result_coefficients[i], i);
                    }
                    if (i > 0)
                    {
                        printf(" + ");
                    }
            }
        }
        break;
    default:
        printf("Invalid Input\n");
        break;
    }
    return 0;
}