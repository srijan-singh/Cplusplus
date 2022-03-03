#include <stdio.h>
#include <conio.h>
#include <string.h>

#define key_size 15

int main()
{
    char str[key_size];

    printf("Enter the Key: ");
    gets(str);
    
    printf("%s", str);

    printf("%d", key_size);

    return 0;
}