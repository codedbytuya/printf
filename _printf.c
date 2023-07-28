#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Prints output according to a format.
 * _strlen - returns the length of a string
 * @param format The format string.
 * @param ... The variable arguments.
 *
 * @return The number of characters printed.
 */

int _strlen(const char *str);

int _printf(const char *format, ...) {
  int len = 0;
  va_list args;

  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      format++;

      switch (*format) {
        case 'c': {
          char c = va_arg(args, int);
          len += write(1, &c, 1);
          break;
        }

        case 's': {
          char *s = va_arg(args, char *);
          len += write(1, s, _strlen(s));
          break;
        }

        case '%': {
          len += write(1, "%", 1);
          break;
        }

        default:
          break;
      }
    } else {
      len += write(1, format, 1);
    }
    format++;
  }

  va_end(args);

  return len;
}

int _strlen(const char *str);


int _strlen(const char *str) {
  int len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }
  return len;
}
