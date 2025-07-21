#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isnum(string s);

int main(int argc, string argv[])
{
    if (argc == 2 && isnum(argv[1]))
    {
        int k = atoi(argv[1]);
        string input = get_string("plaintext:  ");

        printf("ciphertext: ");

        int len = 0;
        for (int i = 0, n = strlen(input); i < n; i++)
        {
            char c = input[i];

            if (c >= 'A' && c <= 'Z')
            {
                printf("%c", ((c + k) - 65) % 26 + 65);
            }
            else if (c >= 'a' && c <= 'z')
            {
                printf("%c", ((c + k) - 97) % 26 + 97);
            }
            else
            {
                printf("%c", c);
            }
        }

        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool isnum(string s)
{
    // bool b = false;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            // b = true;
            return false;
        }
    }

    return true;
}
