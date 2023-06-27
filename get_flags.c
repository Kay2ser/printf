#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * get_flags - Get the flags from the format string
 * @format: The format string
 *
 * Return: flags as an integer
 */

int get_flags(const char *format)
{
	int flags = 0;

	while (*format != '\0' && *format != '%')
	{
		if (*format == '-')
		{
			flags |= FLAG_LEFT_JUSTIFY;
		}
		else if (*format == '+')
		{
			flags |= FLAG_SIGN;
		}
		else if (*format == ' ')
		{
			flags |= FLAG_SPACE;
		}
		else if (*format == '#')
		{
			flags |= FLAG_ALTERNATE;
		}
		format++;
	}
	return (flags);
}
