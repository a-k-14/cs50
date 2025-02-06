#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_w(string s);
int get_s(string s);
int get_l(string s);

int main(void)
{
    string text = get_string("Text: ");

    // words
    int s = get_s(text);
    // printf("Sentences: %i\n", s);

    // sentences
    int w = get_w(text);
    // printf("Words: %i\n", w);

    // letters
    int l = get_l(text);
    // printf("Letters: %i\n", l);

    // float index = 0.0588 * l - 0.296 * s - 15.8;
    int index = round((0.0588 * ((float)l / w * 100)) - (0.296 * ((float)s / w * 100)) - 15.8);
    // printf("Index: %i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}

int get_w(string s)
{
    int i = 0;
    int n = 0;

    while (s[n] != '\0')
    {

        if (s[n] == ' ')
        {
            i++;
        }
        n++;
    }

    return i + 1;
}

int get_s(string s)
{
    int i = 0;
    int n = 0;

    while (s[n] != '\0')
    {
        if (s[n] == '.' || s[n] == '!' || s[n] == '?')
        {
            i++;
        }
        n++;
    }

    return i;
}

int get_l(string s)
{
    // nof letters
    int l = 0;

    // char position
    int n = 0;

    while (s[n] != '\0')
    {
        if ((s[n] >= 'A' && s[n] <= 'Z') || (s[n] >= 'a' && s[n] <= 'z'))
        {
            l++;
            // printf("l: %i\n", l);
        }

        n++;
    }

    return l;
}
