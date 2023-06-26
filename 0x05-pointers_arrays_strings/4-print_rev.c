#include "main.h"

/**
 * print_rev - prints a string in reverse
 * @s: string to be printed
 */

void print_rev(char *s)
{
	int i, len = _strlen(s);

	for (i = len - 1; i >= 0; i--)
		_putchar(*(s + i));

	_putchar(10);
}

/**
 * _strlen - returns the length of a string
 * @s: string to be checked
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	unsigned int len = 0;
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
		len += sizeof(char);

	return (len);
}
