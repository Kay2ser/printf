#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * get_size - get the size from the format string
 * @format: the format string
 *
 * Return: size of an integer
 */

int get_size(const char *format, int *i)
{
	int size = 0;

	if (format[*i] == 'h')
	{
		size = S_SHORT;
		(*i)++;
	}
	else if (format[*i] == 'l')
	{
		size = S_LONG;
		(*i)++;
	}
	else if (format[*i] == 'z')
	{
		size = S_SIZET;
		(*i)++;
	}
	return (size);
}
