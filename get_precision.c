#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int get_precision(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int char_count = 0;
	int precision = -1;

	va_start(args, format);
	output = init_buffer();
	if (output == NULL)
	{
		return (-1);
	}
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				char_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int str_len = strlen(str);

				char_count += str_len;
			}
			else if (*format == '%')
			{
				char_count++;
			}
			else if (*format == '.')
			{
				format++;
				if (*format >= '0' && *format <= '9')
				{
					precision = precision * 10 + (*format - '0');
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			char_count++;
		}
	}
	cleanup(args, output);
	return (precision);
}
