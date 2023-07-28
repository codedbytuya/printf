#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int print_integer(int num); 

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
    int num;

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
                case 'd':
                case 'i':
                    num = va_arg(args, int);
                    
                    count += print_integer(num);
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


int print_integer(int num)
{
    int count = 0;
    char buffer[20];

    
    if (num < 0)
    {
        write(1, "-", 1);
        count++;
        num = -num;
    }

    int i = 0;
    do
    {
        buffer[i++] = '0' + (num % 10);
        num /= 10;
    } while (num != 0);

    
    int j;
    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
        count++;
    }

    return count;
}
