#include "main.h"

int do_multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3,Dlist **tail3, Dlist **head4, Dlist **tail4, Dlist **headR, Dlist **tailR)
{
        int num1, num2, mul, carry = 0, pos = 0;
        Dlist *t1 = *tail1;
        Dlist *t2 = *tail2;
        insert_at_last(head4 , tail4, 0);
        while(t2 != NULL)// Loop through all the digits of the second number
        {
                num2 = t2->data;// to get the current digit of the second number
                while(t1 != NULL)// Get the current digit of the first number
                {
                        num1 = t1->data;// Get the current digit of the first number
                        mul = num1 * num2 + carry;//multiply the two numbers and add the carry from the previous step
                        carry = 0;//reset the carry
                        if(mul > 9)//if the result is greater then 10 or equal to 9
                        {
                                int digit = mul % 10;// Get the current digit
                                insert_at_first(head3, tail3, digit);
                                carry = mul / 10;// Set the carry
                        }
                        else
                        {
                                insert_at_first(head3, tail3, mul);
                        }
                        t1 = t1->prev;//move to the next digit of the 1st list
                }
                if(carry > 0)// If there's a carry left after multiplying all digits of the first number
                {
                        insert_at_first(head3, tail3, carry);
                }
                carry = 0;//reset carry
                do_addition(head3, tail3, head4, tail4, headR, tailR);// Add the current result to the main result
                t2 = t2->prev;//move to the next digit in 2nd number
                pos++;//increment
                t1 = *tail1;// Reset the pointer for the first list to the last digit

		
		// Update head and tail of the result list
                *head4 = *headR;
                *tail4 = *tailR;
		
		// Clear the result list (headR and tailR) for the next iteration
                *headR = NULL;
                *tailR = NULL;

		// Delete the current result list (head3, tail3)
                delete_list(head3, tail3);
                *head3 = NULL;
                *tail3 = NULL;


                if(pos != 0)// Only add zeros if it's not the first multiplication step
                {
                        for(int i = 0; i < pos; i++)// Add 'pos' number of zeros
                        {
                                insert_at_first(head3, tail3, 0);
                        }
                }
        }
        return SUCCESS;//return success
}  

