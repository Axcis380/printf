#ifndef __MAIN_H__
#define __MAIN_H__
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct flags - flags
 * @space: flag ' '
 * @plus: flag '+'
 * @longer: flag 'h'
 * @shorter: flag 'h'
 * @hash: flag '#'
 */
typedef struct flags
{
	int space;
	int plus;
	int hash;
	int longer;
	int shorter;
} flags_t;

/**
 * struct pHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @func: pointer to the correct printing function
 */
typedef struct pHandler
{
	char c;
	int (*func)(va_list arg, flags_t *flag);
} pHandler_t;

int _putchar(char);
int _puts(char *);
int _printf(const char *, ...);
int count_digit(long int);
void print_number(long int);
int print_unsigned(va_list, flags_t *);
int print_int(va_list, flags_t *);
int print_char(va_list, flags_t *);
int print_string(va_list, flags_t *);
int (*get_handler(char))(va_list, flags_t *);
int get_flag(const char *, flags_t *);
char *convert(unsigned long int num, int base, int upper);
int print_binary(va_list, flags_t *);
int print_octal(va_list, flags_t *);
int print_hex_upper(va_list, flags_t *);
int print_hex(va_list, flags_t *);
int print_S(va_list, flags_t *);
int print_address(va_list, flags_t *);
int print_rev(va_list, flags_t *);
int print_rot13(va_list, flags_t *);
int print_percent(va_list, flags_t *);



#endif
