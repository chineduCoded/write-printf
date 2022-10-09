#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * Myprintf - prints a simple character, a string, handles int and hex
 * format: a pointer
 * Return: nothing.
 */

void Myprintf(char* format,...)
{
	char *traverse;
	unsigned int i;
	char *s;

	/* Module 1: Initializing Myprintf arguments */
	va_list arg;
	va_start(arg, format);

	for (traverse = format; *traverse != '\0'; traverse++)
	{
		while (*traverse != '%')
		{
			putchar(*traverse);
			traverse++;
		}

		traverse++;

		/* Module 2: Fetching and executing arguments */
		switch(*traverse)
		{
			case 'c': i = va_arg(arg, int);
				  putchar(i);
				  break;

			case 'd': i = va_arg(arg, int);
				  if (i < 0)
				  {
					  i = -i;
					  putchar('-');
				  }
				  puts(convert(i, 10));
				  break;

			case 'o': i = va_arg(arg, unsigned int);
				  puts(convert(i, 8));
				  break;

			case 's': s = va_arg(arg, char *);
				  puts(s);
				  break;

			case 'x': i = va_arg(arg, unsigned int);
				  puts(convert(i, 16));
				  break;
		}
	}

	/* Module 3: closing argument list to necessary clean up */
	va_end(arg);
}
