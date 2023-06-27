#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
/**
 * struct buffer_s - Buffer struct
 * @start: Pointer to the start of the buffer
 * @len: Length of the buffer
 */
typedef struct buffer_s
{
	char *start;
	int len;
} buffer_t;

/*buffer functions */
buffer_t *init_buffer(void);
void _memcpy(char *dest, cont char *src, size_t n);
int _strlen(const char *str);
void cleanup(va_list args, buffer_t *output);

/* printf function */
int _printf(const char *format, ...);
int get_length(const char *format, ...);
int get_width(const char *format, ...);
int get_precision(const char *format, ...);

#endif
