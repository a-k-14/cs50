#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
void print_space(int height, int i);
void print_row(int i);

int main(void)
{
    int n = get_positive_int();
    for (int i = 0; i < n; i++)
    {
        print_space(n, i);

        print_row(i);

        printf("  ");

        print_row(i);

        printf("\n");
    }
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Height (between 1 and 8): ");
    } while (n < 1 || n > 8);

    return n;
}

void print_space(int height, int i)
{
    // number of spaces per line = height - bricks
    // bricks = i +1 as is starts at 0
    for (int j = height - (i + 1); j > 0; j--)
    {
        printf(" ");
    }
}

void print_row(int i)
{
    for (int k = i + 1; k > 0; k--)
    {
        printf("#");
    }
}
