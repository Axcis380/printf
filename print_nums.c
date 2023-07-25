#include "main.h"

/**
* print_int - prints an integer
* @arg: va_list of args
* @flag: pointer to flag
* Return: int
*/
int print_int(va_list arg, flags_t *flag)
{
	long int num;
	int res;

	if (flag->shorter == 1 && flag->longer == 0)
	{
		num = (short int)va_arg(arg, int);
	}
	else if (flag->longer == 1)
	{
		num = (long int)va_arg(arg, long int);
	}
	else
	{
		num = va_arg(arg, int);
	}
	res = count_digit(num);
	if (flag->space == 1 && flag->plus == 0 && num >= 0)
		res += _putchar(' ');
	if (flag->plus == 1 && num >= 0)
		res += _putchar('+');
	if (num <= 0)
	res++;
	print_number(num);
	return (res);
}

/**
* print_unsigned - prints unsigned int
* @arg: va_list of args
* @flag: pointer flag
* Return: int
*/
int print_unsigned(va_list arg, flags_t *flag)
{
	unsigned long int num;
	char *str;

	if (flag->shorter == 1 && flag->longer == 0)
	{
		num = (unsigned short int)va_arg(arg, unsigned int);
	}
	else if (flag->longer == 1)
	{
		num = (unsigned long int)va_arg(arg, unsigned long int);
	}
	else
	{
		num = va_arg(arg, unsigned int);
	}
	str = convert(num, 10, 0);
	return (_puts(str));
}

/**
* print_number - prints num
* @n: integer to be printed
*/
void print_number(long int n)
{
	unsigned long int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}
