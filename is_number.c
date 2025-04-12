// Function to check if a string is a valid number
int is_number(const char *str) 
{
    if (*str == '-' || *str == '+') str++;  // Allow signed numbers
    if (!*str) return 0;  // Empty string after sign
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}