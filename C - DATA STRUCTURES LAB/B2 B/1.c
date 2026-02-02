// Write a program to calculate the length of string using pointer.
#include <stdio.h>
void string_length(char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    printf("length: %d\n", length);
}
int main(int argc, char const *argv[])
{
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    string_length(str);
    return 0;
}