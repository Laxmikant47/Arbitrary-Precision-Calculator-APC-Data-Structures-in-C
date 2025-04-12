#include "main.h"

/*delete_list*/

int delete_list(Dlist **head, Dlist **tail)
{
    // Check if the list is empty
    if (*head == NULL && *tail == NULL)
    {
        return FAILURE; // Return FAILURE if both head and tail are NULL (empty list)
    }

    Dlist *temp = *head; // Temporary pointer to traverse the list

    // Traverse the entire list and free each node
    while (temp != NULL)
    {
        Dlist *next = temp->next; // Store the next node
        free(temp);               // Free the current node
        temp = next;              // Move to the next node
    }

    *head = NULL; // Set head to NULL since the list is now empty
    *tail = NULL; // Set tail to NULL to mark the list as empty

    return SUCCESS; // Return SUCCESS after deleting all nodes
}