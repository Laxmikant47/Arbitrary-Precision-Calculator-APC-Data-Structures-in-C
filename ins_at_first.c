#include "main.h"

/*Insert_at_first*/
int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist)); // Memory allocation for new node
    if (new == NULL)                    // Check if memory is allocated
    {
        return FAILURE; // If not allowed return failure
    }

    new->data = data;
    new->prev = NULL; // As this will be the first node, prev is NULL
    new->next = NULL; // Initially, next is null

    if (*head == NULL) // Check if the list is empty
    {
        *head = new; // Set head to the new node
        *tail = new; // Set tail to new
        return SUCCESS;
    }

    // If the list is not empty
    new->next = *head;   // Point the new node's next to the current head
    (*head)->prev = new; // Update the current head's prev pointer to the new node
    *head = new;         // Update head to the new node

    return SUCCESS; 
}