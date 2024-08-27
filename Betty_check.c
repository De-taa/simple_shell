#include <stdio.h>

/**
 * main - Entry point of a simple code that passes Betty checks
 * The program displays the sum of integers
 * The program prints a simple arithmetic operation
 *
 * Return: Always 0
 */

int main(void)
{
	int x;
	int y;
	int sum;

	printf("Enter the value of x\n", x);
	scanf("%d", &x);
	printf("Enter the value of y\n", y);
	scanf("%d", &y);

	sum = x + y;
	printf("The sum of x and y is %d ", sum);

	return (0);
}
