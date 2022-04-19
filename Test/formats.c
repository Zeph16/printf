#include "main.h"


/**
 * string_form - handles the string format specifier
 * @f: list of arguments to _printf
 *
 * Return: number of bytes written
 */
int string_form(va_list f)
{
	char *cptr;
	int i, len = 0;

	cptr = va_arg(f, char *);
	if (cptr == NULL)
		cptr = "(null)";
	for (i = 0; cptr[i] != '\0'; i++)
		len += _putchar(cptr[i]);
	return (len);
}

/**
 * char_form - handles the character format specifier
 * @f: list of arguments to _printf
 *
 * Return: number of bytes written (1)
 */
int char_form(va_list f)
{
	return (_putchar(va_arg(f, int)));
}

int int_form(va_list f)
{
	int i, n, len = 0;
	char *cptr;

	n = va_arg(f, int);
	cptr = toString(n);
	for (i = 0; i < _strlen(cptr); i++)
		len += _putchar(cptr[i]);
	return (len);
}


