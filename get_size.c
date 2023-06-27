#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * get_size - get the size from the format string
 * @format: the format string
 *
 * Return: size of an integer
 */

int get_size(const char *format)
{
	int size = 0;

	if (*format == 'h')
	{
		size = SIZE_SHORT;
		format++;
	}
	else if (*format == 'l')
	{
		size = SIZE_LONG;
		format++;
	}
	else if (*format == 'z')
	{
		size = SIZE_SIZET;
		format++;
	}
	return (size);
}
