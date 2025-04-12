#include "main.h"

/*print_list*/
void print_list(Dlist *head)
{
    /* Cheking the list is empty or not */
    if (head == NULL)
    {
        printf("INFO : List is empty\n");
    }
    else
    {
       
        while (head)
        {
            /* Printing the list */
            printf("%d", head->data);

            /* Travering in forward direction */
            head = head->next;   
        }
        
    }
}