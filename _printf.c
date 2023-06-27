#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 *  @format: format string
 *
 *  Return: the no of charachters printed
 */

int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int char_count = 0;

	va_start(args, format);
	output = init_buffer();
	if (output == NULL)
		return (-1);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int)
					_memcpy(output->start + char_count, &c, 1);
				char_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int str_len = strlen(str);

				_memcpy(output->start + char_count, str, str_len);
				char_count += str_len;
			}
			else if (*format == '%')
			{
				_memcpy(output->start + char_count, "%", 1);
				char_count++;
			}
			else
			{
				_memcpy(output->start + char_count, "%", 1);
				_memcpy(output->start + char_count + 1, format, 1);
				char_count += 2;
			}
		}
		else
		{
			_memcpy(output->start + char_count, format, 1);
			char_count++;
		}
	}
	cleanup(args, output);
	return (char_count);
}
