#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

int get_precision(const char *format, int *i, va_list list)
{
	int char_count = 0;
	int precision = -1;

	for (; *format[*i] != '\0'; (*i)++)
	{
		if (*format[*i] == '%')
		{
			(*i)++;
			if (*format[*i] == 'c')
			{
				char_count++;
				int c = va_arg(list, int);
				UNUSED(c);
			}
			else if (*format[*i] == 's')
			{
				char *str = va_arg(list, char *);
				int str_len = strlen(str);

				char_count += str_len;
			}
			else if (*format[*i] == '%')
			{
				char_count++;
			}
			else if (*format[*i] == '.')
			{
				(*i)++;
				if (*format[*i] >= '0' && *format[*i] <= '9')
				{
					precision = format[*i] - '0';
					while (format[*i + 1] >= '0' && format[*i + 1] <= '9')
					{
					precision = precision * 10 + (*format - '0');
					(*i)++;
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
