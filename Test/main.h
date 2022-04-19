#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int write(int fd, const char *buf, int bytes);
int _strlen(const char *s);
int counter(const char *format);

#endif
