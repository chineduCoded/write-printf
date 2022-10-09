#include "main.h"

/**
 * convert - convert an int number into octal, hex and etc.
 * num: first param
 * base: secod param. a base
 * Return: ptr.
 */

char *convert(unsigned int num, int base)
{
	static char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = Representation[num % base];
		num /= base;
	}while (num != 0);

	return (ptr);
}
