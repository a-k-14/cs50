#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
void print_row(int pyramid_height, int i);

int main(void)
{
    // to get the height of pyramid from the user
    int pyramid_height = get_positive_int();

    for (int i = 0; i < pyramid_height; i++)
    {
        print_row(pyramid_height, i);
        printf("\n");
    }
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("What's the pyramid height? ");
    } while (n < 1);

    return n;
}

void print_row(int pyramid_height, int i)
{
    // we add 1 to i as i starts at 0
    int spaces = pyramid_height - (i + 1);
    int bricks = i + 1;

    for (int j = spaces; j > 0; j--)
    {
        printf(" ");
    }

    for (int k = bricks; k > 0; k--)
    {
        printf("#");
    }
}
