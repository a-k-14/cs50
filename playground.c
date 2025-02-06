#include <stdio.h>
#include <stdlib.h>

void updateArr(int *arr)
{
    arr[0] = 120;
}

int main(void)
{
    // int list[3];
    int *list = malloc(3 * sizeof(int));

    list[0] = 2;
    list[1] = 5;
    list[2] = 9;

    // we update an element to check if arrays are passed by reference
    updateArr(list);

    // we increase the space by 2 int
    list = realloc(list, 5 * sizeof(int));

    list[3] = 54;
    list[4] = 16;

    // we loop through the list arr to print the elements
    for (int t = 0; t < 5; t++)
    {
        printf("%i\n", list[t]);
    }

    // we free the list array memory space
    free(list);
}