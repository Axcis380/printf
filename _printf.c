#include "main.h"

/**
* _printf - prints formatted string
* @format: format string
* Return: length of string
*/
int _printf(const char *format, ...)
{
	int (*pHndlr)(va_list, flags_t *);
	const char *p;
	va_list args;
	flags_t flags = {0, 0, 0, 0, 0};

	register int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
		while (get_flag(p, &flags))
			p++;
		pHndlr = get_handler(*p);
		count += (pHndlr)
			? pHndlr(args, &flags)
			: _printf("%%%c", *p);
		}
	else
		count += _putchar(*p);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
