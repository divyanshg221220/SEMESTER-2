// Write a program for Polynomial representation and arithmetic
#include <stdio.h>
int main() {
    int p1[20]={0}, p2[20]={0};
    int sum[40]={0}, diff[40]={0}, prod[40]={0};
    int deg1, deg2, i, j;
    int first;
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients:\n");
    for(i = 0; i <= deg1; i++)
        scanf("%d", &p1[i]);
    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients:\n");
    for(i = 0; i <= deg2; i++)
        scanf("%d", &p2[i]);
    for(i = 0; i <= deg1 || i <= deg2; i++) {
        sum[i] = p1[i] + p2[i];
        diff[i] = p1[i] - p2[i];
    }
    for(i = 0; i <= deg1; i++)
        for(j = 0; j <= deg2; j++)
            prod[i + j] += p1[i] * p2[j];
    printf("Addition Result:\n");
    first = 1;
    for(i = (deg1 > deg2 ? deg1 : deg2); i >= 0; i--) {
        if(sum[i] != 0) {
            if(!first)
                printf(" + ");
            printf("%dx^%d", sum[i], i);
            first = 0;
        }
    }
    printf("\nSubtraction Result:\n");
    first = 1;
    for(i = (deg1 > deg2 ? deg1 : deg2); i >= 0; i--) {
        if(diff[i] != 0) {
            if(!first)
                printf(" + ");
            printf("%dx^%d", diff[i], i);
            first = 0;
        }
    }
    printf("\nMultiplication Result:\n");
    first = 1;
    for(i = deg1 + deg2; i >= 0; i--) {
        if(prod[i] != 0) {
            if(!first)
                printf(" + ");
            printf("%dx^%d", prod[i], i);
            first = 0;
        }
    }
    return 0;
}