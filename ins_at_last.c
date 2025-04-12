#include "main.h"

/*Insert_at_last*/
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist)); // memory allocation for the new node
    if (new == NULL)                    // check if memory is allocated or not
    {
        return FAILURE; // return failure
    }

    new->data = data;
    new->prev = NULL; // As this will be the first node, prev is NULL
    new->next = NULL; // Initially, next is NULL

    if (*head == NULL) // Check if the list is empty
    {
        *head = new; // Set head to the new node
        *tail = new; // set tail to new
        return SUCCESS;
    }

    new->prev = *tail;   // point the new node previous to the tail
    (*tail)->next = new; // update the tail next to the new
    *tail = new;         // update tail to the new node
    return SUCCESS;
}
