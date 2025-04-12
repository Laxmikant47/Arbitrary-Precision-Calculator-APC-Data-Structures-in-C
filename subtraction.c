#include"main.h"

/* Function to subtract two numbers represented as linked lists */
int do_subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *t1 = *tail1;//temporary pointer to traverse the 1st list
    Dlist *t2 = *tail2;//temporary pointer to traverse the 2nd list

    int diff, borrow = 0;//diff to store the subtraction result and borrow if any digit was borrowed

    while (t1 != NULL || t2 != NULL)//loop until both list are traversed
    {
        if (t1 != NULL && t2 != NULL)// Both lists still have digits to subtract
        {
            int num1 = t1->data - borrow;// Take the current digit of the first list and subtract any borrow from the previous step
            int num2 = t2->data;// Take the current digit of the second list

            if (num1 < num2)//num1 < num2 need to borrow
            {
                borrow = 1;//reset borrow to 1 when borrowed
                num1 += 10;// Add 10 to num1 to make it large enough to subtract num2
            }
            else
            {
                borrow = 0;//if no borrow
            }

            diff = num1 - num2;
            insert_at_first(headR, tailR, diff);

            t1 = t1->prev;//to move to the next digit in 1st list
            t2 = t2->prev;//to move to the next digit in the 2nd list
        }
        else if (t1 != NULL && t2 == NULL)//if num1 has greater number of digits
        {
            int num1 = t1->data - borrow;// Take the current digit from the first list and subtract any borrow
            if (num1 < 0)
            {
                borrow = 1;
                num1 += 10;// Add 10 to num1 to make it non-negative
            }
            else
            {
                borrow = 0;
            }
            insert_at_first(headR, tailR, num1);
            t1 = t1->prev;//move to the next digit in 1st list
        }
    }

    // Remove leading zeros in the result
	while (*headR && (*headR)->data == 0 && (*headR)->next != NULL)
	{
    	Dlist *temp = *headR;
    	*headR = (*headR)->next;
    	(*headR)->prev = NULL;
    	free(temp);
	}
    return SUCCESS;//return success
}