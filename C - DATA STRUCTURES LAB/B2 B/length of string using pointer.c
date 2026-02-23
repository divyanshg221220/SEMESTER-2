// Write a program to calculate the length of string using pointer.
#include <stdio.h>
void string_length(char *str)
{
    int l = 0;
    while (*str != '\0')
    {
        l++;
        str++;
    }
    printf("length: %d\n", l);
}
int main(int argc, char const *argv[])
{
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    string_length(str);
    return 0;
}