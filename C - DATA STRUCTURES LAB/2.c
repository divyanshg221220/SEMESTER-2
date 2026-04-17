// Write a program to check whether a matrix is a sparse matrix or not
#include <stdio.h>
int main() {
    int row, col, i, j, a[10][10], count = 0;
    printf("Enter number of rows:\n");
    scanf("%d", &row);
    printf("Enter number of columns:\n");
    scanf("%d", &col);
    printf("Enter elements of the matrix:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Elements of the matrix are:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(a[i][j] == 0)
                count++;
        }
    }
    if(count > (row * col) / 2)
        printf("Matrix is a sparse matrix\n");
    else
        printf("Matrix is not a sparse matrix\n");
    return 0;
}