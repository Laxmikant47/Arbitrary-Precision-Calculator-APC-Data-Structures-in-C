#include"main.h"  // Include the header file "main.h" for function prototypes and type definitions

/* Calculate the number of nodes in a doubly linked list */
int cal_nodes(Dlist **head)
{
    Dlist *t1 = *head;  // Temporary pointer to traverse the list
    int count = 0;  // Initialize the counter for the nodes
    while (t1 != NULL)  // Traverse the list until the end
    {
        count++;  // Increment the count for each node encountered
        t1 = t1->next;  // Move to the next node
    }
    return count;  // Return the total number of nodes
}

/* Compare two doubly linked lists element by element */
int compare(Dlist *rh1, Dlist *rh2)
{
    while (rh1 != NULL && rh2 != NULL)  // Traverse both lists until one reaches the end
    {
        if (rh1->data < rh2->data)  // If the current node in the first list is smaller
            return rh1->data - rh2->data;  // Return the difference (negative)
        else if (rh1->data == rh2->data)  // If both data values are equal
        {
            rh1 = rh1->next;  // Move to the next node in the first list
            rh2 = rh2->next;  // Move to the next node in the second list
        }
        else  // If the current node in the first list is greater
        {
            return rh1->data - rh2->data;  // Return the difference (positive)
        }
    }
    return 0;  // Return 0 if both lists have the same data up to their end
}

/* Remove leading zeros from a doubly linked list */
int remove_zeros(Dlist **rh, Dlist **rt)
{
    while ((*rh)->next != NULL && (*rh)->data == 0)  // While the first node is zero
    {
        delete_first(rh, rt);  // Remove the first node
    }
}

/* Check if all the data in the list is zero */
int check_data(Dlist **rh, Dlist **rt)
{
    Dlist *t = *rh;  // Temporary pointer to traverse the list
    while (t != NULL)  // Traverse the list until the end
    {
        if (t->data != 0)  // If any node has a non-zero value
            return 0;  // Return false
        t = t->next;  // Move to the next node
    }
    return 1;  // Return true if all nodes are zero
}

/* Perform division of two numbers represented by doubly linked lists */
int do_division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3, Dlist **head4, Dlist **tail4)
{
    int flag = 0;  // Flag for error or specific conditions (not used here)
    int c = 0;  // Count for number of iterations (not used here)
    int c1 = cal_nodes(head2);  // Get the number of nodes in the divisor list
    Dlist *temp = *head1;  // Temporary pointer to traverse the numerator list
    int c2 = 0;  // Counter for the number of nodes in the current part of the numerator

    while (c2 < c1)  // While the length of the current part of numerator is less than the divisor
    {
        insert_at_last(head3, tail3, temp->data);  // Insert the current data into the result list
        c2 = cal_nodes(head3);  // Update the count of nodes in the result list
        if (temp->next != NULL)  // If there are more nodes in the numerator
            temp = temp->next;  // Move to the next node
    }

    if (temp->prev != NULL)  // If the numerator list has a previous node
        temp = temp->prev;  // Move to the previous node
    int c3 = cal_nodes(head1);  // Get the number of nodes in the numerator
    if (c3 == c2 && temp->next != NULL)  // If the lengths are equal and there are more nodes in numerator
        temp = temp->next;  // Move to the next node

    Dlist *head6 = NULL;  // Temporary head for intermediate operations
    Dlist *tail6 = NULL;  // Temporary tail for intermediate operations
    int count = 0;  // Counter for storing results of division

    while (temp != NULL)  // While there are more nodes in the numerator
    {
        while (c2 > c1)  // If the numerator part has more nodes than the divisor
        {
            while (check_data(head3, tail3) == 1 && temp != NULL)  // If all data in the result list is zero
            {
                insert_at_last(head4, tail4, 0);  // Insert a zero in the result list
                temp = temp->next;  // Move to the next node in the numerator
                if (temp != NULL)
                    insert_at_last(head3, tail3, temp->data);  // Insert the next numerator value into the result list
            }
            do_subtraction(head3, tail3, head2, tail2, &head6, &tail6);  // Perform subtraction of divisor from result
            count++;  // Increment the division count
            remove_zeros(&head6, &tail6);  // Remove any leading zeros
            *head3 = head6;  // Update result list
            *tail3 = tail6;  // Update result list
            head6 = NULL;  // Reset intermediate lists
            tail6 = NULL;
            c2 = cal_nodes(head3);  // Update the count of nodes in the result list
        }

        if (c1 == c2 && compare(*head3, *head2) < 0 && temp != NULL)  // If the result is less than the divisor
        {
            if (temp != NULL)
            {
                temp = temp->next;  // Move to the next node in the numerator
                if (temp != NULL)
                    insert_at_last(head3, tail3, temp->data);  // Insert the new numerator value into the result list
            }
            c2 = cal_nodes(head3);  // Update the count of nodes in the result list
            while (check_data(head3, tail3) == 1 && temp != NULL)  // While the result list has all zeros
            {
                insert_at_last(head4, tail4, 0);  // Insert a zero in the result list
                temp = temp->next;  // Move to the next node in the numerator
                if (temp != NULL)
                    insert_at_last(head3, tail3, temp->data);  // Insert the next numerator value into the result list
            }
        }

        while (c1 == c2 && compare(*head3, *head2) >= 0 && temp != NULL)  // If the result is greater or equal to the divisor
        {
            do_subtraction(head3, tail3, head2, tail2, &head6, &tail6);  // Perform subtraction of divisor from result
            count++;  // Increment the division count
            remove_zeros(&head6, &tail6);  // Remove leading zeros
            *head3 = head6;  // Update result list
            *tail3 = tail6;  // Update result list
            head6 = NULL;  // Reset intermediate lists
            tail6 = NULL;
            c2 = cal_nodes(head3);  // Update the count of nodes in the result list
        }

        if (count != 0)  // If there was a successful division
        {
            insert_at_last(head4, tail4, count);  // Insert the count into the result list
            count = 0;  // Reset count after inserting
        }

        if (c2 < c1)  // If the result list has fewer nodes than the divisor
        {
            temp = temp->next;  // Move to the next node in the numerator
            if (temp != NULL)
            {
                if (temp->data == 0 && temp->next == NULL && compare(*head3, *head2) < 0)  // If there are no more valid nodes
                {
                    insert_at_last(head4, tail4, 0);  // Insert a zero in the result list
                    break;  // Exit the loop
                }
                insert_at_last(head3, tail3, temp->data);  // Insert the new numerator value into the result list
            }
            c2 = cal_nodes(head3);  // Update the count of nodes in the result list
            while (c2 <= c1 && temp != NULL && temp->next != NULL && compare(*head3, *head2) < 0)  // While the result is less than the divisor
            {
                insert_at_last(head4, tail4, 0);  // Insert a zero in the result list
                temp = temp->next;  // Move to the next node in the numerator
                if (temp != NULL)
                {
                    insert_at_last(head3, tail3, temp->data);  // Insert the next numerator value into the result list
                    remove_zeros(head3, tail3);  // Remove leading zeros
                }
                c2 = cal_nodes(head3);  // Update the count of nodes in the result list
            }
        }
    }

    return SUCCESS;  // Return success if the division operation was completed successfully
}

