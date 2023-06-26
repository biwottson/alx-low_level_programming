#include "main.h"
#include "2-strlen.c"

/**
 * puts_half - prints the second half of a string
 * @str: string to be printed
 */

void puts_half(char *str)
{
	int i = 0, j = 0, n = _strlen(str);

	if (n % 2 != 0)
		j += 1;

	for (i = (n + j) / 2; i < n; i++)
		_putchar(*(str + i));


	_putchar('\n');

}
