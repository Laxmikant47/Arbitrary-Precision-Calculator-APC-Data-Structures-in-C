#include "main.h"

/*delete_first*/
int delete_first(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head; // Store the current head node in a temporary pointer

    // Check if the list is empty
    if (*head == NULL)
    {
        return FAILURE; // Return FAILURE if the list is empty
    }

    // Check if the list has only one node
    if (*head == *tail)
    {
        free(*head);          // Free the only node in the list
        *head = *tail = NULL; // Set both head and tail to NULL as the list is now empty
        return SUCCESS;       // Return SUCCESS after deletion
    }
    else
    {
        // If the list has more than one node
        *head = (*head)->next; // Update head to the next node in the list
        free(temp);            // Free the memory of the old head
        (*head)->prev = NULL;  // Set the prev pointer of the new head to NULL
        return SUCCESS;        // Return SUCCESS after deleting the first node
    }
}
