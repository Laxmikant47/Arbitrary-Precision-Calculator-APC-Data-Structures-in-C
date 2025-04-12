#include "main.h"

// Function to check if the operator is valid
int is_valid_operator(const char *op) 
{   
    return (strlen(op) == 1 && (*op == '+' || *op == '-'  || *op == '/' || *op == 'x'));
}