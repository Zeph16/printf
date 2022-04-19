#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * _strlen - a function that counts and returns the length of a string
 * @s: the passed string
 * Return: the count
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
/**
 * counter - a function to count the number of %
 * @format: character string
 * Return: the count
 */
int counter(const char *format)
{
	int i, n = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
			n++;
	}
	return (n);
}
/**
 * _printf - the function which operates like the actual printf
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, n;
	char c, *cptr;

	if (format == NULL)
		return (0);
	n = counter(format);
	if (n == 0)
		write(1, format, _strlen(format));
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					c = va_arg(args, int);
					cptr = &c;
					write(1, cptr, 1);
					break;
				case 's':
					cptr = va_arg(args, char *);
					write(1, cptr, _strlen(cptr));
					break;
				default:
					write(1, (char *)(format + i), 1);
					i--;
					break;
			}
			i++;
			continue;
		}
		write(1, (char *)(format + i), 1);
	}
	va_end(args);
	return (n);
}
