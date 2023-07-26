#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf
 * @format: The format string
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c;
    const char *str;

    va_start(args, format);

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
