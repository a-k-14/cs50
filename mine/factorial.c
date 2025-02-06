#include <stdio.h>

// goal - to calculate the factorial of a number using recursion technique

long getFactrial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * getFactrial(n - 1);
    }
}

int main(void)
{
    int factorialOf = 5;
    long result = getFactrial(factorialOf);
    printf("%i factorial: %ld", factorialOf, result);
}