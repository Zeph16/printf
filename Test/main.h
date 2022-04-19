#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct Specifier - The conversion Specifying char andits respective function
 * @form: format specifying character
 * @fun: respective function
 */
typedef struct Specifier
{
	char form;
	int (*fun)(va_list);
} Spec;

int _printf(const char *format, ...);
int handler(const char *, va_list, Spec[]);
int write(int fd, const char *buf, int bytes);
int _strlen(const char *s);
int counter(const char *format);
int _putchar(char c);
int string_form(va_list f);
int char_form(va_list f);

#endif
