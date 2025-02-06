#include <stdio.h>

// ?Goal is to see how structs are passed by: value or ref
// they are passed by value unlike arrays, which are passed by ref

// we define Person struct
typedef struct
{
    char name[64];
    int age;
} Person;

// we use a prototype to modify the struct
void updateStruct(Person *person, int age)
{
    // modifies the original struct as struct is passed by ref
    // i.e. we are pssing the refrence to the original struct and not the struct copy which would be the case if we were passing by value which is the dfault behavior
    (*person).age = age;
}

int main(void)
{
    // we crate a struct p
    Person p;
    // update the value of age
    p.age = 40;

    // update the value of age with a function
    // since we have to update the value, we have to pass the reference to the original struct p with &
    updateStruct(&p, 33);

    printf("%i\n", p.age);
}
