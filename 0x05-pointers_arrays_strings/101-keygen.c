#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * main - program that generates random valid
 * passwords for the program 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int pass[15];
	int i, sum;

	sum = 0;

	srand(time(NULL));

	for (i = 0; i < 14; i++)
	{
		pass[i] = rand() % 78;
		sum += pass[i];
		putchar(pass[i] + 33);
	}

	pass[14] = 2772 - sum;
	sum += pass[14];
	putchar(pass[14] + 33);
	putchar('\n');

	if (sum == 2772)
		printf("Tada! Congrats\n");
	else
		printf("Wrong password\n");

	return (0);
}
