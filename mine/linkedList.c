#include <stdio.h>
#include <stdlib.h>

// here we create a list that has reference to its next node and previous node
/*
the list we create with stackList is like a stack, because it is LIFO
wherein the latest element is added at the top
i.e. when we start going through the list using the list variable, we first get the latest added element
so LIFO
*/
void doublyLinkedList(void)
{
    // we define the struct named node which is the item in the linked list
    typedef struct node
    {
        int number;
        // char *text;
        // address of the next node
        struct node *next;
        // address of previous node
        struct node *previous;
    } node;

    // we create a variable to hold the list
    node *list = NULL;
    node *head = NULL;

    // Loop to create the linked list
    for (int i = 0; i < 5; i++)
    {
        // we create a temporary node
        node *n = malloc(sizeof(node));

        //  we check if the mem allocation was successfull, else exit
        if (n == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        // we assign the value of number to the node
        (*n).number = i;
        // n->text = "aaa";

        // if the list is NULL, this is first node, so we point list towards 1st node
        if (list == NULL)
        {
            // n holds the address to 1st node
            // with this line, list also holds the address to the first node
            list = n;
            head = n;

            // we point the next of current 1st node to NULL and previous node to NULL
            // *if we don't do this, the 2nd for loop that prints the values, runs 4 times
            (*n).next = NULL;
            (*n).previous = NULL;
        }
        else
        {
            // if this is not 1st node, we point the new node to whatever list is pointing at
            (*n).previous = list;
            // since there is no next node for new node we are creating now, we assign it to null
            // we will update the next value of this new node in next run
            (*n).next = NULL;

            // we update the next value lastly created node to point to newly created node
            (*list).next = n;

            list = n;
        }
    }
    // printf("%i\n", list->previous->previous->previous->previous->number);

    // we print the numbers that the linked list 'list' stores
    // we can also use while loop with != NULL

    // for (node *ptr = head; ptr != NULL; ptr = (*ptr).next)
    for (node *ptr = list; ptr != NULL; ptr = (*ptr).previous)
    {
        // value of next node for latest/last entry in linked list will be NULL
        // value of previous node for first entry in the linked list will be NULL
        printf("%p\n", ptr);
        printf("%i\n", (*ptr).number);
        // printf("%s\n", ptr->text);
        printf("(next node: %p)\n", (*ptr).next);
        printf("(prev node: %p)\n", (*ptr).previous);
        printf("------------------\n");
    }

    // freeing the memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *temp = ptr;
        free(temp);
        ptr = ptr->previous;
    }
}

// this is the linked list made as is from the class
int defaultList(void)
{
    // we define the structure of the list
    typedef struct node
    {
        int number;
        struct node *next;
    } node;

    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            // we should free the successful nodes before exiting
            return 1;
        }

        n->number = i;
        // for the 1st node n->next will be NULL as the value of list will be NULL
        n->next = list;
        list = n;
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}

// appended linked list is where we append the new node instead of adding it at the head like in stacked list
// list -> 123 instead of list -> 321
int appendedList(void)
{
    typedef struct node
    {
        int number;
        struct node *next;
    } node;

    node *list = NULL;

    for (size_t i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));

        n->number = i;
        // we assign next to NULL, because this new node will always be the end of the list and will the last node
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }
        else
        {
            // list is not empty and we need to find the last node to append the new node
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;

                    //? if we do not break, the for loop will keep running as the new node keeps getting appended again and again
                    break;
                }
            }
        }
    }

    // printing the number values inside the list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}

// sorted linked list
void sortedList(void)
{

    typedef struct node
    {
        int number;
        struct node *next;
    } node;

    node *list = NULL;

    for (int i = 0; i < 6; i++)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            printf("Memory allocation failed!");
            return;
        }

        n->number = i;

        /*

        // if it is the 1st node
        if (list == NULL)
        {
            list = n;
            n->next = NULL;
        }
        // if it is the 2nd node
        else if (list->next == NULL)
        {
            if (n->number < list->number)
            {
                // insert n before list
                n->next = list;
                // list -> new -> old
                list = n;
            }
            // insert new node at the end
            // list -> old -> new
            list->next = n;
            n->next = NULL;
        }
        // if there are more than 2 nodes in the list
        // we check if the new number is lesser than the starting number i.e. start of the list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        // else we have to insert the new node in between the nodes or at the end
        else
        {
            node *left = list;
            node *right = list->next;

            while (right != NULL)
            {
                if (left->number <= n->number && n->number <= right->number)
                {
                    left->next = n;
                    n->next = right;
                }
                else if (right->next == NULL)
                {
                    right->next = n;
                    n->next = NULL;
                    break;
                }

                left = right;
                right = right->next;
            }
        }
        */

        /*
         if it is the 1st node
         we check if the new number is lesser than the starting number i.e. start of the list
         here either if LHS is true, RHS is not evaluated as c use short circuit evaluation and prevents segmentation default
         seg default occues for RHS if this is 1st node
         */
        if (list == NULL || n->number < list->number)
        {
            // i.e. n->next = NULL for 1st run
            n->next = list;
            list = n;
        }
        else
        {
            /*
            if the list is not NULL or the new node is not < first node in list, we have to insert new node in between or at the end of the list
            we start at the start of the list and traverse through the list to find the position of insertion
            */
            node *current = list;

            /*
            If current == NULL means we have reached the end of the list and we add the new node at the end
            checking current != NULL helps prevent seg default error for RHS like if we are at the end of the list RHS will be error
            c short-circuits && checks like in ||
            we do not compare current->number as current starts with list and we have checked if new node number < list.number above in if
            and if the new node number > list.number, that case is captured by current->next->number as the c->n->number will be greater than list->number
            */
            while (current->next != NULL && n->number > current->next->number)
            {
                current = current->next;
            }

            // once we get the position via current, we do this
            n->next = current->next;
            current->next = n;
        }
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        printf("%p\n", ptr->next);
        printf("---------\n");
        ptr = ptr->next;
    }

    // to free list
    node *ptr1 = list;
    while (ptr1 != NULL)
    {
        // we get hold of next node as we will free the current node using ptr1
        node *temp = ptr1->next;
        // we free the current node
        free(ptr1);
        // we assign the next node to ptr1
        ptr1 = temp;
    }

    list = NULL;

    // printf("%p\n", list->next);

    /*
    here after freeing the memory also we can print the values because the data is not erased and list still points to the old data
    free() marks the memory as available to OS but does not erase
    *we should not be accessing memory after free()
    *we should do list = NULL after free()
    */
    /*
     node *ptr2 = list;
     while (ptr2 != NULL)
     {
         printf("%i\n", ptr2->number);
         printf("%p\n", ptr2->next);
         printf("---------\n");
         ptr2 = ptr2->next;
     }
    */

    printf("\nRun successful\n\n");
}

int main(void)
{
    // doublyLinkedList();
    // defaultList();
    // appendedList();
    sortedList();
}