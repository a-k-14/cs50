#include <stdio.h>

void get_int(void);
void get_string(void);

int main(void)
{
    // get_int();
    get_string();
}

void get_int(void)
{
    int n;

    printf("Enter n: ");

    scanf("%i", &n);

    printf("The number is %i\n", n);
}

void get_string(void)
{
    // char s[10] = {0};

    // printf("Enter s: ");

    // even if we enter more than 10 characters, c will read them and save in s which is danger as it may overwrite the memory after 10
    // so we limit input length to 9 leaving one char for \0 or nul terminator
    // scanf("%9s", s);

    // printf("Input s: %s\n", s);

    char t[10] = {0};

    printf("Enter t: ");

    fgets(t, sizeof(t), stdin);

    printf("Input t: %s\n", t);
}