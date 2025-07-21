#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool get_isalpha(string s);
bool get_isrepeated(string s);

int main(int argc, string argv[])
{
    // we check if key exists and if key length = 26
    if (argc != 2)
    {
        printf("Please pass a key to execute the program.\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must be 26 charactersonly.\n");
        return 1;
    }

    if (!get_isalpha(argv[1]))
    {
        printf("Key must be alphabets only (upper/lower).\n");
        return 1;
    }

    if (get_isrepeated(argv[1]))
    {
        printf("Key must be unique. No repition of alphabets.\n");
        return 1;
    }

    string key = argv[1];
    string input = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        char c = input[i];

        if (isalpha(c))
        {
            // we convert the char to lower, subsctract 'a' to get normal alphabetical position from ascii
            // Then we get the cipher char from key. This cipher char can be lower or upper case
            char d = key[tolower(c) - 'a'];

            if (islower(c))
            {
                printf("%c", tolower(d));
            }
            else
            {
                printf("%c", toupper(d));
            }
        }
        else
        {
            printf("%c", c); // This is non-alpha character
        }
    }

    printf("\n");
}

// we check if the key consists only alphabets upper/lower
bool get_isalpha(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // printf("%c", s[i]);

        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
        {
            return false;
        }
    }

    return true;
}

// we check if the alphabets are repeating in the key
bool get_isrepeated(string s)
{
    int freq[26] = {0}; // we have to initialize the array. Else we get unexpected behaviour

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char c = s[i];

        // we convert to lower and then check
        if (freq[tolower(c) - 'a'] > 0)
        {
            return true; // repeating character found
        }
        else
        {
            freq[tolower(c) - 'a']++;
        }
    }

    return false; // no repeating characters found
}
