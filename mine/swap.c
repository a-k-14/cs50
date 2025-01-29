#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void swap_add(int **a, int **b);

int main(void)
{
    printf("\n");
    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));

    if (x == NULL || y == NULL)
    {
        return 1;
    }

    *x = 2;
    *y = 6;

    printf("x: %p %i y: %p %i \n", x, *x, y, *y);
    printf("Address of x: %p\n", &x);
    printf("Address of y: %p\n", &y);

    printf("\n----------\n\n");

    // swap(x, y);
    // int *temp = x;
    // x = y;
    // y = temp;

    swap_add(&x, &y);

    printf("x: %p %i y: %p %i \n", x, *x, y, *y);

    printf("Address of x: %p\n", &x);
    printf("Address of y: %p\n", &y);

    printf("\n");
}

// here we swap the values of x and y, by swapping the values at the addresses x and y point to
// i.e. x and y still point to the same addresses, but the value at those addresses is changed
// here address and value combo change
void swap(int *a, int *b)
{
    int temp = *a; // Store the value pointed to by 'a' in 'temp'
    *a = *b;       // Set the value at 'a' to be the value at 'b'
    *b = temp;     // Set the value at 'b' to be the original value of 'a'
}

// here we swap x and y by swapping the addresses of the x and y
// i.e. we assign the address x points to y, and assign the address y points to x
// here the address and value combo remains same
void swap_add(int **a, int **b)
{
    // temp is not holding a pointer to a pointer; rather, it is holding a pointer to an integer
    // so **temp does not work as we get int * with *a i.e. address of integer
    // where as ** expects address of pointer (x) to integer
    int *temp = *a;
    *a = *b;
    *b = temp;
}