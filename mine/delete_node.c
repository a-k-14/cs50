// Goal is to implement a function to delete node in a linked list

#include <stdio.h>
#include <stdlib.h>

// node dfinition
typedef struct node
{
    int num;
    struct node *next;
} node;

// function to add a node to the list
void add_node(node **list, int num)
{
    // create a node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Unable to allocate memory!\n");
        return;
    }

    // update num of new node to num received from main
    n->num = num;
    // update new node to point to last node in the list
    n->next = *list;
    *list = n;
}

void print_node(node *list)
{
    printf("\n");
    while (list != NULL)
    {
        printf("%i\n", list->num);
        printf("curr: %p\n", &(*list));
        printf("next: %p\n", list->next);
        printf("------------\n");
        list = list->next;
    }
    printf("______________________\n");
}

// to delete a node that has the num passed from main
void delete_node(node **list, int num)
{
    // we have to delete a node from the list and then link the list
    // we keep tarck of left because, we have to link the left node to current->next
    node *left = *list;
    node *current = (*list)->next;

    // if the 1st node has the num we have to delete
    if ((*list)->num == num)
    {
        // to free the memory of the node
        node *temp = *list;
        // we just point the head(list) to next node in the list
        *list = (*list)->next;

        free(temp);
    }
    else
    {
        // we loop through the linked list
        while (current != NULL)
        {
            if (current->num == num)
            {
                left->next = current->next;
                free(current);
                return;
            }
            else
            {
                left = current;
                current = current->next;
            }
        }
    }
}

int main(void)
{
    // header of the list
    node *list = NULL;

    // create a linked list of 6 numbers (0 - 5)
    for (int i = 0; i <= 3; i++)
    {
        add_node(&list, i);
    }

    // print the nodes
    print_node(list);

    // delete the node that has num == 1
    delete_node(&list, 1);

    // print nodes
    print_node(list);
}