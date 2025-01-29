#include <cs50.h>
#include <stdio.h>
// #include <string.h>

int main(int argc, char *argv[])
{
    // we open the file on write - w mode
    // FILE *file = fopen("phonebook.csv", "w");

    // we open the file on append - a mode
    FILE *file = fopen("phonebook.csv", "a");

    // we exit if the file is null
    if (file == NULL)
    {
        return 1;
    }

    // we get the name and number from the user
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // we write the name and number to the file along with their addresses in the parentheses ()
    fprintf(file, "%s (%p), %s (%p)\n", name, name, number, number);

    fclose(file);
}