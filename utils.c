#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * get_length - get length of the formatted string
 * @format: the format string
 * @args: the va_list of arguments
 *
 * Return: The length of the formatted string
 */
int get_length(const char *format, va_list args)
{
    int char_count = 0;

    for (; *format != '\0'; format++)
    {
        if (*format == '%')
        {
            format++;

            if (*format == 'c')
            {
                va_arg(args, int);
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
            else
            {
                char_count += 2;
            }
        }
        else
        {
            char_count++;
        }
    }

    return char_count;
}

/**
 * _printf - Prints formatted output to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int char_count;

    va_start(args, format);
    char_count = get_length(format, args);
    va_end(args);

    char buffer[char_count + 1];
    buffer[char_count] = '\0';

    int ret_count = handle_print(format, 0, args, buffer, 0, 0, 0, 0);
    write(1, buffer, ret_count);

    return ret_count;
}

