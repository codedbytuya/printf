#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints formatted output to the standard output stream (stdout).
 * @format: A character string containing format specifiers that control the output.
 *
 * Return: The total number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;
    const char *str;

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move past the '%' */

            switch (*format)
            {
                case 'c':
                    c = (char)va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, const char *);
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    /* If the format is invalid, just print the '%' and the next character */
                    write(1, "%", 1);
                    write(1, format, 1);
                    count += 2;
                    break;
            }
        }
        else
        {
            /* Regular character, just print it */
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
