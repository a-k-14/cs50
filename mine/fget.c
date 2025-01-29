#include <stdio.h>

// This program reads a file char by char and prints the char to the terminal
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: .\\fgetc <file>\n");
        return 1;
    }

    // we open the file user has inputed
    FILE *file = fopen(argv[1], "r");

    char c;
    // we get char by char from the file and print it until ir is EOF - End Of File
    while ((c = fgetc(file)) != EOF)
    {
        printf("%c", c);
    }
}