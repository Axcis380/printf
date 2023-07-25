#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return precision;

    precision = 0;

    // Move to the character after '.'
    curr_i++;

    // Check if precision is specified using '*'
    if (format[curr_i] == '*')
    {
        curr_i++;
        precision = va_arg(list, int);
        if (precision < 0) // Handle negative values
            precision = -1;
    }
    else
    {
        // Calculate the precision value from the format string
        while (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
            curr_i++;
        }
    }

    // Check for non-custom conversion specifiers
    switch (format[curr_i])
    {
        case 'd':
        case 'i':
        case 'c':
            // For %d, %i, %c, apply precision to limit the number of characters to print
            break;
        default:
            // For other conversion specifiers, handle precision as needed
            break;
    }

    *i = curr_i - 1;

    return precision;
}

