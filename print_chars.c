#include "main.h"

/**
* print_string - prints string
* @arg: args from _printf
* @flag: pointer to flag
* Return: int
*/
int print_string(va_list arg, flags_t __attribute__((__unused__)) *flag)
{
	char *s = va_arg(arg, char *);

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
* print_char - prints char
* @arg: args from _printf
* @flag: pointer to flag
* Return: int
*/
int print_char(va_list arg, flags_t __attribute__((__unused__)) *flag)
{
	_putchar(va_arg(arg, int));
	return (1);
}

/**
 * print_S - handles non-printable chars
 * @arg: va_list args
 * @flag: pointer to flag
 * Return: number of chars printed
 */
int print_S(va_list arg, flags_t __attribute__((__unused__)) *flag)
{
	int i, count = 0;
	char *replc;
	char *s = va_arg(arg, char *);

	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			replc = convert(s[i], 16, 1);
			if (!replc[1])
				count += _putchar('0');
			count += _puts(replc);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}

/**
 * print_rev - handles non-printable chars
 * @arg: va_list args
 * @flag: pointer to flag
 * Return: number of chars printed
 */
int print_rev(va_list arg, flags_t __attribute__((__unused__)) *flag)
{
	int i = 0, j;
	char *s = va_arg(arg, char *);

	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}
