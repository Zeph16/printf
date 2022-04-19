#include "main.h"

/**
 * handler - detects format specifiers and prints the given string
 * Central processing unit for the _printf function
 * @givenstr: original string supplied to _printf
 * @args: list of arguments passed to _printf
 * @forms: Spec structure array
 *
 * Return: number of total bytes written
 */

int handler(const char *givenstr, va_list args, Spec forms[])
{
	int i, j, len = 0;

	for (i = 0; givenstr[i] != '\0'; i++)
	{
		if (givenstr[i] == '%')
		{
			if (givenstr[i + 1] == '\0')
				return (-1);
			if (givenstr[i + 1] == ' ')
				while (givenstr[i + 1] == ' ')
					i++;
			if (givenstr[i + 1] == '%')
			{
				len += _putchar('%');
				i++;
				continue;
			}
			for (j = 0; j < 4; j++)
			{
				if (givenstr[i + 1] == forms[j].form)
				{
					len += forms[j].fun(args);
					i++;
					break;
				}
			}
			if (j == 4)
				len += _putchar('%');
			continue;
		}
		len += _putchar(givenstr[i]);
	}
	return (len);
}
/**
 * _printf - the spotlight function which operates like the actual printf
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len;
	Spec specs_arr[] = {
		{'c', char_form},
		{'s', string_form},
		{'i', int_form},
		{'d', int_form}
	};

	if (format == NULL)
		return (-1);
	va_start(args, format);
	len = handler(format, args, specs_arr);
	va_end(args);
	return (len);
}
