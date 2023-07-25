#include "main.h"

/**
* print_address - prints string
* @arg: args from _printf
* @flag: pointer to flag
* Return: int
*/
int print_address(va_list arg, flags_t __attribute__((__unused__)) *flag)
{
	char *str;
	unsigned long int p = va_arg(arg, unsigned long int);

	int count = 0;


	if (!p)
		return (_puts("(nil)"));
	str = convert(p, 16, 0);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
* print_percent - prints string
* @arg: args from _printf
* @flag: pointer to flag
* Return: int
*/
int print_percent(va_list arg, flags_t __attribute__((__unused__)) *flag)
{
	(void)arg;
	return (_putchar('%'));
}

/**
* print_rot13 - prints string
* @arg: args from _printf
* @flag: pointer to flag
* Return: int
*/
int print_rot13(va_list arg, flags_t __attribute__((__unused__)) *flag)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(arg, char *);

	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}
