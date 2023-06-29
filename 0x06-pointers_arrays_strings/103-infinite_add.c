#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: The first number
 * @n2: The second number
 * @r: The buffer to store the result
 * @size_r: The size of the buffer
 *
 * Return: Pointer to the result (r)
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, i, j, sum, carry = 0;

	while (n1[len1] != '\0')
		len1++;

	while (n2[len2] != '\0')
		len2++;

	if (size_r <= len1 || size_r <= len2)
		return (0);

	r[size_r - 1] = '\0';
	len1--;
	len2--;
	i = size_r - 2;

	while (len1 >= 0 || len2 >= 0)
	{
		sum = carry;

		if (len1 >= 0)
			sum += n1[len1--] - '0';

		if (len2 >= 0)
			sum += n2[len2--] - '0';

		carry = sum / 10;
		r[i--] = (sum % 10) + '0';
	}

	if (carry && i >= 0)
		r[i--] = carry + '0';

	if (carry && i < 0)
		return (0);

	return (r + i + 1);
}

