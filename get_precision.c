#include "main.h"
#include <stdbool.h> 

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
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
    curr_i++;

    if (format[curr_i] == '*')
    {
        precision = va_arg(list, int);
        curr_i++;
    }
    else
    {
        while (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
            curr_i++;
        }
    }

    *i = curr_i - 1;

    return precision;
}
