#include <stdio.h>
// for uint8_t
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // validating the user CLA
    // spec - prog name, input forensic image / memory card
    if (argc != 2)
    {
        printf("Usage ./recover <file name>\n");
        return 1;
    }

    // we open the forensic image input in "r" mode
    FILE *input = fopen(argv[1], "r");

    // we return if there is an error in opening the file
    if (input == NULL)
    {
        printf("Unable to open the input file.\n");
        return 1;
    }

    // buffer to store the data
    uint8_t buffer[512];

    // Filenames: ###.jpg, starting at 000. jpg
    // we crate a filename buffer
    // as file name is 7 chars + 1 char for \0, we need 8 char space or 8 bytes
    char filename[8];
    // = malloc(sizeof(char) * 8);

    // counter to track the file number
    int counter = 0;

    // counter to track the number of previous file
    // to close current file and open a new file
    // int pr_counter = 0;

    // variable to store the address of output file created inside the while loop
    FILE *output = NULL;

    // While there's still data left to read from the memory card
    // fread returns the number of blocks it has read of size 1 here
    while (fread(buffer, 1, 512, input) == 512)
    {

        // we check for the jpg signature and if it exists we create a new file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // we check if this is 1st jpg file, and if it is, we first create a new file without closing any previous file as there is no previous file
            if (counter == 0)
            {
                // we create the file name and store it in filename variable
                // Format - sprintf(filename, "%03i.jpg", 2)
                sprintf(filename, "%03i.jpg", counter);

                // we open a new file in w mode and store it in output
                output = fopen(filename, "w");

                // !we change the counter by 1 - this was causing errors
                // counter += 1;
            }
            else
            {
                // if the current file is not the first file, we first close the previous file and then continue creating new file

                // we close the file that is in open
                fclose(output);

                // !we change the counter by 1 if the counter is not 1
                // counter += 1;

                // we create the file name and store it in filename variable
                sprintf(filename, "%03i.jpg", counter);

                // we open a new file in w mode and store it in output
                output = fopen(filename, "w");
            }

            printf("%s\n", filename); // *to debug filename issue casued by updating counter above
            // we write the data to the newly opened file
            fwrite(buffer, 1, 512, output);
            counter += 1;
        }
        else
        {
            // if this is the first run, and if we do not find jpg singature, we have to exit the loop
            // we cannot check for counter != 0, as for the first file after we find the signature, the subsequent blocks will not get written
            // so we use output != NULL, as it will be NULL til 1st run
            // output is not NULL means already we found a jpg signature
            if (output != NULL)
            {
                // if the jpg signature does not exist at the start of the block for the subsequent runs after 1st run
                // we write the data to the currently opened jpg
                fwrite(buffer, 1, 512, output);
            }
        }
    }

    // we close the card image file and the last jpg generated
    fclose(input);
    fclose(output);

    // we free the malloc to filename
    // free(filename);
}
