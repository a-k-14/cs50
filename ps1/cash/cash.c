#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
int number_of_coins(int n);

int main(void)
{
    int change = get_positive_int();
    int coins = number_of_coins(change);

    printf("%i\n", coins);
}

int get_positive_int(void)
{
    int n;

    do
    {
        n = get_int("Change owed: ");
    } while (n < 1);

    return n;
}

// here n is the change owed to the customer
int number_of_coins(int n)
{
    int coins = 0;

    while (n > 0)
    {
        // printf("%i", coins);
        if (n >= 25)
        {
            n -= 25;
            coins++;
        }
        else if (n >= 10)
        {
            n -= 10;
            coins++;
        }
        else if (n >= 5)
        {
            n -= 5;
            coins++;
        }
        else if (n >= 1)
        {
            n -= 1;
            coins++;
        }
    }

    return coins;
}
