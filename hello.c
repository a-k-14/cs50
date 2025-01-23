#include "cs50.h"
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    // we get the name of the user to greet
    string name = get_string("What is your name: ");

    // we check if the first character in name is lower and change it to upper case
    if (islower(name[0]))
    {
        name[0] = toupper(name[0]);
    }

    int age = get_int("What is your age: ");

    printf("\n-----x-----\n");
    printf("Hello, %s!\n", name);
    printf("Welcome to CS50.\n");
    printf("No matter if you are %i years or 15 years or 50 years, it's never too late :)\n", age);
    printf("-----x-----\n\n");
}