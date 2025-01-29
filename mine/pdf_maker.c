#include <stdio.h>

// !This code will not create a correct PDF as there is more to a PDF structure than just PDF magic number. So, this is just a try to add magic PDF number or %PDF to the file

// Magic PDF number
char seq[] = {0x25, 0x50, 0x44, 0x46};

// This function creates PDF files with the magic PDF number
int main(void)
{
    FILE *file = fopen("test.pdf", "w");

    if (!file)
    {
        printf("Could not open the file");
        return 1;
    }

    // we write the magic PDF number
    fwrite(seq, sizeof(char), sizeof(seq), file);

    fclose(file);
    printf("PDF magic number added successfully");
}