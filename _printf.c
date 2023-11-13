#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Outputs a formatted string
 * @format: Character string to print
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        count += putchar(*str);
                        str++;
                    }
                    break;
                }
                case '%':
                    count += putchar('%');
                    break;
                default:
                    break;
            }
        } else {
            count += putchar(*format);
        }

        format++;
    }

    va_end(args);
    return count;
}
