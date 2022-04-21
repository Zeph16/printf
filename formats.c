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


/**
 * int_form - handles the integer (%d || %i) format specifier
 * @f: list of arguments to _printf
 *
 * Return: number of bytes written
 */
int int_form(va_list f)
{
	int i, n, len = 0;
	char *cptr;

	n = va_arg(f, int);
	cptr = toString(n);
	for (i = 0; i < _strlen(cptr); i++)
		len += _putchar(cptr[i]);
	free(cptr);
	return (len);
}


/**
 * bin_form - handles the binary format specifier
 * @f: list of arguments to _printf
 *
 * Return: number of bytes written
 */
int bin_form(va_list f)
{
	int i, n, bin = 0, len = 0, k = 1;
	char *cptr;

	n = va_arg(f, int);
	while (n != 0)
	{
		bin += (n % 2) * k;
		k *= 10;
		n /= 2;
	}
	cptr = toString(bin);
	for (i = 0; i < _strlen(cptr); i++)
		len += _putchar(cptr[i]);
	free(cptr);
	return (len);
}
/**
 * rev_form - handles the reverse format specifier
 * @f: list of arguements to _printf
 *
 * Return: number of bytes written
 */
int rev_form(va_list f)
{
	int i, n, len = 0;
	char *cptr, *rev;

	cptr = va_arg(f, char *);
	if (cptr == NULL)
		cptr == "(null)";
	n = _strlen(cptr);
	for (i = 0; i < n; i++)
		rev[n - (i + 1)] = cptr[i];
	for (i = 0; cptr[i] != '\0'; i++)
		len += _putchar(rev[i]);
	free(rev);
	return (len);
}
