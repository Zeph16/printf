#include "main.h"

/**
 * _putchar - prints a single character
 * @c: the character to be printed
 *
 * Return: number of bytes written (1)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


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
	return (digits);
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
	else if (n == 0)
	{
		sptr = malloc(sizeof(char) * 2);
		sptr[0] = '0';
		sptr[1] = '\0';
		return (sptr);
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
	return (sptr);
}
