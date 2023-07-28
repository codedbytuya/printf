#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * _printf - Prints formatted output to stdout.
 *
 * @param format: A format string.
 * @param ...: A variable number of arguments.
 *
 * @return The number of characters printed.
 */

int _printf(const char *format, ...) {
  /**
   * count: The number of characters printed.
   */
  int count = 0;

  /**
   * args: A variable argument list.
   */
  va_list args;

  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      format++;
      switch (*format) {
        case 'c': {
          /**
           * c: A character.
           */
          char c = va_arg(args, int);
          count += write(1, &c, 1);
          break;
        }
        case 's': {
          /**
           * str: A string.
           */
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
