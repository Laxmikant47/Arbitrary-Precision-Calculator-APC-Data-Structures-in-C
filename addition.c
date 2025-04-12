#include "main.h"

/*addition operator*/
int do_addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *t1 = *tail1; // t1 temporary pointer to traverse the 1st list from tail
	Dlist *t2 = *tail2; // t2 temporary pointer to traverse the 2nd list from tail

	int sum, carry = 0; // sum will store the addition result, carry stores the carry-over during addition

	while (t1 != NULL || t2 != NULL) // loop to run upto both lists are traversed completely
	{
		if (t1 != NULL && t2 != NULL) // if t1 and t2 != null
		{
			sum = t1->data + t2->data + carry; // Add corresponding digits from both lists along with carry
			carry = 0;						   // reset carry to check the new carry is generated or no
			if (sum > 9)					   // if sum of the is greater then 9 then carry is generated
			{
				int updated_data = sum % 10;				 // current digit of the sum is updated
				insert_at_first(headR, tailR, updated_data); // fun call
				sum = sum / 10;								 // the remaining sum is stired for next iteration
				carry = sum;								 // Carry will be the quotient
			}
			else // if no carry
			{
				insert_at_first(headR, tailR, sum); // function call
			}
			t1 = t1->prev; // move to the next node in 1st list
			t2 = t2->prev; // move to the next node in the 2nd list
		}
		else if (t1 != NULL && t2 == NULL) // when the first list as more digits
		{
			sum = t1->data + 0 + carry; // Add the current digit from the first list and the carry
			carry = 0;					// reset carry
			insert_at_first(headR, tailR, sum);
			t1 = t1->prev; // move to next node in 1st list
		}
		else if (t1 == NULL && t2 != NULL) // if second list as more digits
		{
			sum = t2->data + 0 + carry; // Add the current digit from the second list and the carry
			carry = 0;					// reset carry
			insert_at_first(headR, tailR, sum);
			t2 = t2->prev; // move to the next node 2nd list
		}
	}
	if (carry) // if carry is present after both list is processed
	{
		insert_at_first(headR, tailR, carry);
	}
	return SUCCESS; // to return success
}

