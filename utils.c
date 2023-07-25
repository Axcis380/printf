#include "main.h"

/**
 * get_handler - gets the correct func
 *
 * @c: char
 * Return: func
 *
 */

int (*get_handler(char c))(va_list, flags_t *)
{
	pHandler_t hndlr_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'b', print_binary},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex_upper},
		{'S', print_S},
		{'p', print_address},
		{'R', print_rot13},
		{'r', print_rev},
		{'%', print_percent},
		{0, NULL}
	};
	int i = 0;

	while (hndlr_arr[i].c)
	{
		if (hndlr_arr[i].c == c)
			return (hndlr_arr[i].func);
		i++;
	}
	return (NULL);
}

/**
 * get_flag - gets flag
 * @s: char
 * @flag: flag pointer
 *
 * Return: int
 */
int get_flag(const char *s, flags_t *flag)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			flag->plus = 1;
			i = 1;
			break;
		case ' ':
			flag->space = 1;
			i = 1;
			break;
		case '#':
			flag->hash = 1;
			i = 1;
			break;
		case 'l':
			flag->longer = 1;
			i = 1;
			break;
		case 'h':
			flag->shorter = 1;
			i = 1;
			break;
	}

	return (i);
}

/**
 * count_digit - returns the number of digits
 * @i: int
 * Return: number of digits
 */
int count_digit(long int i)
{
	unsigned long int d = 0, u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}


/**
 * convert - converts number to string
 * @num: int
 * @base: base
 * @upper: upper or not
 * Return: string
 */
char *convert(unsigned long int num, int base, int upper)
{
	static char *map;
	static char con_buff[50];
	char *ptr;

	map = (upper)
		? "0123456789ABCDEF"
		: "0123456789abcdef";
	ptr = &con_buff[49];
	*ptr = '\0';
	do {
		*--ptr = map[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
