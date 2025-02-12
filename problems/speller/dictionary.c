// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
// for strcasecmp
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next; // Pointer to next node (linked list for collisions)
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
// we initialize it to NULL to avoid garbage values i.e. addresses to random memory
node *table[N] = {NULL};

// this is to tarck the number of words loaded from dictionary to table array successfully
// we dclare it globally so that load() and size() can access it
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // get hash of the word
    int index = hash(word);

    // go to the index location of the 'table' array
    node *current = table[index];

    // we loop through the linked list at the index location of table array
    while(current != NULL)
    {
        if (strcasecmp(current->word, word) == 0)
        {
            return true;
        } else
        {
            current = current->next;
        }
    }

    // if no match found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        printf("Unable to open dictionary!\n");
        return false;
    }

    // to read the words from dictionary and store
    // no word is > 45
    char buffer[LENGTH + 1];

    // Read each word in the file and store in node
    // as we have specified %s here, which is a string that ends with \0, fscanf will read till each \0
    while (fscanf(dict, "%s", buffer) != EOF)
    {
        // Create space for a new node
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            printf("Error creating node!");
            return false;
        }

        // we copy the word from buffer to node
        strcpy(n->word, buffer);

        // we get the bucket this node goes in to using hash function
        int index = hash(buffer);

        // we insert the node into array 'table' at location 'index'
        n->next = table[index];
        table[index] = n;

        // after every successful read, we increment the word_count;
        word_count += 1;
    }

    // close the dictionary file
    fclose(dict);
    // load was successful
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // we traverse the table array length (0 to N-1)
    for (int i = 0; i < N; i++)
    {

            // we get the 1st item in the linked list at table[i]
            node *n = table[i];

            // we loop through the linked list and free each node
            while(n != NULL)
            {
                node *temp = n->next;
                free(n);
                n = temp;
            }

    }
    // when the unload is successful
    return true;
}
