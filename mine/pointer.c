#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void learn_pointer(void);

int main(void)
{

    printf("\n");

    int *x = malloc(sizeof(int));

    if (x == NULL)
    {
        return 1;
    }

    *x = 10;

    int y = 12;

    // output: value x holds i.e. address of 10
    printf("Value of x: %p\n", x);
    printf("Value of x: %p\n", *&x);
    // o: address of x in the memory
    printf("Address of x: %p\n", &x);
    // o: 10
    printf("Value at the address in x: %i\n", *x);

    printf("\n");

    // address of y and 12 will be same (actually no address for 12)
    // o: address of y in the memory (y and 12 will have same address)
    printf("Address of y: %p\n", &y);
    // o: address of y in the memory
    printf("Value in y: %i\n", y);

    printf("\n");

    learn_pointer();
}

void learn_pointer(void)
{
    int arr[5];
    arr[0] = 1;

    for (int i = 1; i < 5; i++)
    {
        arr[i] = arr[i - 1] * 2;

        // printf("%i\n", arr[i]);
    }

    int x = 10;
    int *p = &x;

    printf("x: %i\n", *&x);
    printf("p(x): %p\n", p);
    printf("p(p): %p\n", &p);
    // we are getting the address of p with &p
    // then we are getting the value at the address of p with *(&p)
    // which is nothing but the address of x (as p is a pointer variable that stores the address/pointer of x)
    printf("p(x): %p\n", *&p);
    // *p = 20;
    // printf("x(with p): %i\n", *p);
    // printf("p(x): %p\n", p);

    printf("---------\n");

    char *s = "Hi!";

    // gives the value inside s i.e. the address where "Hi!" is stored
    printf("value of s: %p\n", s);

    // gives the value "Hi!"
    // but, we should use *s instead of direct s?
    printf("value at the address inside s: %s\n", s);

    // gives the address of s
    printf("p(s): %p\n", &s);

    // gives the value that s is holding inside it
    printf("value of s with *: %p\n", *&s);

    // we print the address of each of the char in the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c: %p\n", s[i], &s[i]);
    }

    // to check the address of \0 at the end of the string
    // but we need not add the 1 at the end
    printf("\\0: %p\n", &s[strlen(s)]);

    // we are printing the character itself at s[strlen(s)], which is \0 or NUL
    char p1 = s[strlen(s)];
    printf("%c\n", p1);

    printf("%c\n", *(s + 1));
    printf("%s\n", s + 1); // starts from 2nd character
}