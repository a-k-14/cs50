#include <stdio.h>

// recursively print the bricks like in mario
void print_bricks_loop(int n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

void print_bricks_recusrively(int n)
{
    if (n <= 0)
    {
        return;
    }

    print_bricks_recusrively(n - 1);

    for (size_t i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

int main(void)
{
    // print_bricks_loop(4);
    print_bricks_recusrively(4);
}