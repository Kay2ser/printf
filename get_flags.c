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
			flags |= F_MINUS;
		}
		else if (*format == '+')
		{
			flags |= F_PLUS;
		}
		else if (*format == '0')
                {
			flags |= F_ZERO;
		}
		else if (*format == ' ')
		{
			flags |= F_SPACE;
		}
		else if (*format == '#')
		{
			flags |= F_HASH;
		}
		format++;
	}
	return (flags);
}
