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
		if (format[i] == '%')
			n++;
	return (n);
}
/**
 * getDigits - a function to count the digits of input numbers
 * @n: the passed number
 * Return: the count
 */
int getDigits(int n)
{
        int dup = n;
        int digits = 0;
        while (dup != 0)
        {
                dup /= 10;
                digits++;
        }
        return digits;
}
/**
 * toString - a function that turns numerics to string
 * @n: the passed number
 * Return: the string
 */
char *toString(int n)
{
        int i, neg = 0, index = 0;
        int digits = getDigits(n);
        char s[1000];
	char *sptr;

	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}

        for (i = 0; i < digits; i++)
        {
                s[digits - (i + 1)] = 48 + (n % 10);
                n /= 10;
        }
        s[digits] = '\0';
	if (neg)
	{
		digits++;
		index = 1;
	}
        sptr = malloc(sizeof(char) * digits);
	sptr[0] = neg ? '-' : s[0];
        for (i = 0; i < digits; i++)
	{
		sptr[index] = s[i];
		index++;
	}
        return sptr;
}
/**
 * _printf - the function which operates like the actual printf
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, n, temp, len = 0;
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
					len++;
					break;
				case 's':
					cptr = va_arg(args, char *);
					write(1, cptr, _strlen(cptr));
					len += _strlen(cptr);
					break;
				case 'i':
                                case 'd':
                                        temp = va_arg(args, int);
                                        cptr = toString(temp);
                                        write(1, cptr, _strlen(cptr));
                                        break;
				case '%':
					c = '%';
					cptr = &c;
					write(1, cptr, 1);
					len++;
					break;
				default:
					write(1, (char *)(format + i), 1);
					len++;
					i--;
					break;
			}
			i++;
			continue;
		}
		write(1, (char *)(format + i), 1);
		len++;
	}
	va_end(args);
	return (len);
}
