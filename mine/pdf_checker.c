#include <stdio.h>
// for uint8_t
#include <stdint.h>

// This function checks if the file passed in command line is a valid PDF
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./pdf <file.pdf>\n");
        return 1;
    }

    // we open the file in read mode
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    // we read the first 4 bytes of the file
    uint8_t buffer[4];

    char seq[] = {0x25, 0x50, 0x44, 0x46};

    // here we do not use &buffer, as buffer is an array and arrays are nothing but address to the first element of the array
    fread(buffer, 1, 4, file);

    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != seq[i])
        {
            printf("Not a PDF\n");
            fclose(file);
            return 1;
        }
    }

    // we close the file
    fclose(file);

    printf("It is a PDF\n");
}