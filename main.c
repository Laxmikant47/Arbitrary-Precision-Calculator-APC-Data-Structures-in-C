/*
//  Name: Laxmikant
//  Title: Arithmetic Precision Calculator (APC)
//  Date : 24/03/2025
//  Descrption :The Arithmetic Precision Calculator is designed to perform arithmetic operations (+, -, x, /)
//              on large integers with high precision. It ensures accurate computations by handling input validation,
//              error detection, and special cases such as division by zero and sign management.
*/
#include "main.h"

int main(int argc, char *argv[])
{
    char option;
    do
    {
        int error_flag = 0; 

        if (argc != 4) 
        {
            printf("Error: Incorrect number of arguments.\n");
            printf("Usage: %s <number> <operator> <number>\n", argv[0]);
            return 1;
        }

        if (!is_number(argv[1])) 
        {
            printf("Error: First argument '%s' is not a valid number.\n", argv[1]);
            error_flag = 1; 
        }
   
    if (!is_valid_operator(argv[2])) {
        printf("Error: Second argument '%s' is not a valid operator (Use +, - , x , /).\n", argv[2]);
        printf("Note: The '*' symbol is a special character in the shell. Use 'x' for multiplication.\n");
        error_flag = 1; 
    }

    if (!is_number(argv[3])) 
    {
        printf("Error: Third argument '%s' is not a valid number.\n", argv[3]);
        error_flag = 1; 
       
    }
    if(error_flag == 1)
    {
        error_flag = 0;
        return 1;
    }

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *head3 = NULL, *tail3 = NULL;
    Dlist *head4 = NULL, *tail4 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    int isNegative1 = 0;
    int isNegative2 = 0;
         
    int i = 0;
    if (argv[1][0] == '-')
    {
        isNegative1 = 1;
        printf("-"); // Print '-' sign
		
        i = 1; // Skip '-' sign
    }
    
    while (argv[1][i] != '\0')
    {
        int temp = argv[1][i] - 48;
        insert_at_last(&head1, &tail1, temp);
        i++;
    }

    print_list(head1);
    char operator= argv[2][0];
    printf(" %c ",operator);

    int j = 0;
    // Check if second number is negative
    if (argv[3][0] == '-')
    {
        isNegative2 = 1;
        printf("-"); // Print '-' sign
	
        j = 1; // Skip '-' sign
    }
    
    while (argv[3][j] != '\0')
    {
        int temp = argv[3][j] - 48;
        insert_at_last(&head2, &tail2, temp);
        j++;
    }
    print_list(head2);
    printf(" = ");

    //char operator= argv[2][0];
    switch (operator)
    {

     //Addition       
        case '+':
        {
            /* Determine lengths and indices for processing */
            int len1 = (argv[1][0] == '-') ? strlen(argv[1]) - 1 : strlen(argv[1]);
            int len2 = (argv[3][0] == '-') ? strlen(argv[3]) - 1 : strlen(argv[3]);
            int i = (argv[1][0] == '-') ? 1 : 0;
            int j = (argv[3][0] == '-') ? 1 : 0;

            if (isNegative1 ==  isNegative2)
            {
             do_addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
             if (isNegative1) 
             printf("-");
            }
            else  // One number is negative
            {
            if ((len1 < len2) || (len1 == len2) && (strcmp(argv[1]+i, argv[3]+j) < 0))
            {
                // Swap head1 and head2 if necessary to ensure correct subtraction order
                Dlist *temp = head1;
                head1 = head2;
                head2 = temp;
                temp = tail1;
                tail1 = tail2;
                tail2 = temp;

                // Print '-' if the result is negative
            if (isNegative2 == 1 && isNegative1 == 0)
                    printf("-");
            }
            else if (isNegative1) // If first number is negative
                printf("-");

                do_subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            }

             print_list(headR);
            break;
        }
     //Subtraction   
        case '-':
        {
				/*call the function to perform the subtraction operation*/
                int len1 = strlen(argv[1]) - 1;
                int len2 = strlen(argv[3]) -1;
                if(isNegative1 == 1 && isNegative2 == 1)
                {
                    if(len1 > len2)
                    printf("-");
                }
                if ((isNegative2 == 1 && isNegative1 == 0) || (isNegative2 == 0 && isNegative1 == 1))
                {
				    if ((isNegative2 == 0 && isNegative1 == 1) && (strlen(argv[1]) >= strlen(argv[3])) && (strcmp(argv[1], argv[3]) > 0 ))
				    {
					    printf("-");
				    }
                    else if ((isNegative2 == 1 && isNegative1 == 0) && (strlen(argv[1]) <= strlen(argv[3])) && (strcmp(argv[1], argv[3]) < 0 ))
				    {
					    printf("-");
				    }
                    else if((isNegative2 == 0 && isNegative1 == 1))
                    {
                        printf("-");
                    }
                
                    do_addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                }
			    else if(strlen(argv[1]) == strlen(argv[3]))
				{
					if(strcmp(argv[1], argv[3]) < 0) 
					{
						Dlist *temp1 = head1;
						Dlist *temp2 = tail1;
						head1 =  head2;
						tail1 = tail2;
						head2 = temp1;
						tail2 = temp2;
                        if(isNegative2 != 1)
                        printf("-");
						do_subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					} 
					else
					{
						do_subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					
					}
				}
				else if(strlen(argv[1]) > strlen(argv[3]))
				{
					do_subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				}
				else
				{
					Dlist *temp1 = head1;
					Dlist *temp2 = tail1;
					head1 = head2;
					tail1 = tail2;
					head2 = temp1;
					tail2 = temp2;
                if(isNegative2 == 0 && isNegative1 == 1) 
                        printf("-");
					do_subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				}
				print_list(headR);
				break;
        }
       //Multiplication 
        case 'x':
        {
            if((argv[1][0] == '-' && argv[3][0] != '-') || (argv[1][0] != '-' && argv[3][0] == '-'))
            {
                if(atoi(argv[3]) != 0 && atoi(argv[1]) != 0)
                {
                    printf("-");
                }
            }
               
            /*call the function to perfrom the multiplication operation*/
            do_multiplication(&head1, &tail1, &head2, &tail2, &head3, &tail3, &head4, &tail4, &headR, &tailR);
			print_list(head4);
            break;
        }
       //Division 
        case '/':
        {
            int len1, len2, i, j;

            /* Check for division by zero */
            if (argv[3][0] == '0' || (argv[3][0] == '-' && argv[3][1] == '0'))
            {
                printf("Can't divide by zero\n");
                return 1;
            }

            /* Determine lengths and indices for processing */
            len1 = (argv[1][0] == '-') ? strlen(argv[1]) - 1 : strlen(argv[1]);
            len2 = (argv[3][0] == '-') ? strlen(argv[3]) - 1 : strlen(argv[3]);
            i = (argv[1][0] == '-') ? 1 : 0;
            j = (argv[3][0] == '-') ? 1 : 0;

            /* Determine the sign of the result */
            int negative_result = ((argv[1][0] == '-') ^ (argv[3][0] == '-')) ? 1 : 0;

            /* Handle different cases */
            if (len1 < len2 || (len1 == len2 && strcmp(argv[1] + i, argv[3] + j) < 0))
            {
                printf("0\nNumerator is less than denominator\n");
            }
            else if (strcmp(argv[1] + i, argv[3] + j) == 0)
            {
                printf("%d\nThe numerator and denominator are equal\nThe result will always be ±1.\n", negative_result ? -1 : 1);
            }
            else
            {
                /* Ensure lists are initialized */
                if (head1 == NULL || head2 == NULL)
                {
                    printf("ERROR: List is empty\n");
                    return 1;
                }

                /* Perform division */
                do_division(&head1, &tail1, &head2, &tail2, &head3, &tail3, &head4, &tail4);

                /* Print the result */
                if (negative_result)
                {
                    printf("-");
                }
                print_list(head4);
            }   
        }
        break;  
        default:
        {
            printf("Invalid Input\n");
        }

    }
    } while (0);
    printf("\n");
    return 0;
}
