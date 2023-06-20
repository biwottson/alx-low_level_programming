#include <stdio.h>
/**
* main - causes an infinite loop
* Return: 0
*/
int main(void)
{
int i;
printf("Infinite loop incoming :(\n");
i = 0;
/*while (i < 10)*/
/*{*/
/*putchar(i);*/
/*}*/
printf("Infinite loop avoided! \\o/\n");
return (0);
}



2-largest_number.c

#include "main.h"
/**
* largest_number - returns the largest of 3 numbers
* @a: first integer
* @b: second integer
* @c: third integer
* Return: largest number
*/
int largest_number(int a, int b, int c)
{
int largest;
if (a > b && a > c)
{
largest = a;
}
else if (a > b && c > a)
{
largest = c;
}
else if (b > c)
{
largest = b;
}
else
{
largest = c;
}
return (largest);
}

