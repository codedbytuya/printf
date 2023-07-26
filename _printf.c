#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf
 * @format: The format string
 *
 * Return: The number of characters printed
 */

i#include <stdio.h>
#include <stdlib.h>

int _printf(const char *format, ...) {
  int count = 0;
  va_list args;

  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      format++;
      switch (*format) {
        case 'c': {
          char c = va_arg(args, int);
          count += write(1, &c, 1);
          break;
        }
        case 's': {
          char *str = va_arg(args, char *);
          count += write(1, str, strlen(str));
          break;
        }
        case '%': {
          count += write(1, "%", 1);
          break;
        }
        default: {
          break;
        }
      }
    } else {
      count += write(1, format, 1);
    }
    format++;
  }

  va_end(args);
  return count;
}
