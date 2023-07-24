# printf
This is a simplified implementation of the _printf function, inspired by the standard C library's printf function. The purpose of this function is to print formatted output to the standard output stream (stdout) based on a given format string and variable arguments. 

Function Prototype:
int _printf(const char *format, ...);

Supported Conversion Specifiers The _printf function supports the following conversion specifiers:  
%c: Prints a single character. 
%s: Prints a null-terminated string.
%%: Prints a single '%' character.
