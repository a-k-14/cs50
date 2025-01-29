#include <stdio.h>
// for BYTE / unint8_t
#include <stdint.h>

void use_fread_fwrite(FILE *src, FILE *dst);
void use_fget_fput(FILE *src, FILE *dst);

// user to input 2 file names - 1 dst 1 src
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./cp src dst\n");
        return 1;
    }

    // we open src file in read - r / rb mode
    FILE *src = fopen(argv[1], "rb");

    // we open dest file in write - w mode
    FILE *dst = fopen(argv[2], "w");

    use_fread_fwrite(src, dst);

    // use_fget_fput(src, dst);

    // we close the files
    fclose(src);
    fclose(dst);
}

void use_fread_fwrite(FILE *src, FILE *dst)
{
    // we use this instead of BYTE as we got error
    // typedef uint8_t BYTE; -> this can be used too
    // we can use char c also here
    uint16_t buffer;

    // we read the file contents 1 byte at a time and write it to the new file
    // we need to use &buffer, as buffer is char i.e. a scalar value and since fread and fwrite expect the address of the variable, we need to use &buffer
    while (fread(&buffer, 1, 1, src) != 0)
    {
        fwrite(&buffer, 1, 1, dst);

        // prints the number of bytes successfully written
        // printf("%i\n", fwrite(&buffer, 1, 1, dst));
    }
}

void use_fget_fput(FILE *src, FILE *dst)
{
    // we use this char to store the data read from fgetc
    char c;

    // we read one char at a time till we reach EOF
    while ((c = fgetc(src)) != EOF)
    {
        fputc(c, dst);

        // prints the char written
        printf("%c", fputc(c, dst));
    }
}