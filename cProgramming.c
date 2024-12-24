#include <stdio.h>
#include <conio.h>

int main()
{
    char name[30];
    printf("Enter your name = ");
    fgets(name, sizeof(name), stdin);
    printf("hello %s", name);
    return 0;
}