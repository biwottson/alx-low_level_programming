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
	char password[15];
	int i, sum, n;

	sum = 0;
	srand(time(NULL));

	for (i = 0; i < 14; i++)
	{
		password[i] = 33 + rand() % 94;
		sum += password[i];
		putchar(password[i]);
	}

	password[14] = 2772 - sum;
	sum += password[14];
	putchar(password[14]);

	password[15] = '\0';

	if (strcmp(password, "Tada! Congrats") == 0)
		printf("\nPassword cracked successfully!\n");
	else
		printf("\nWrong password\n");

	return (0);
}

