#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
<<<<<<< HEAD
 * main - Entry point
=======
 * main - assigns a random number to n and prints if it is positive, negative or zero
>>>>>>> Add program to print if random number is positive, negative, or zero
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
<<<<<<< HEAD
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;

    if (n > 0)
    {
        printf("%d is positive\n", n);
    }
    else if (n == 0)
    {
        printf("%d is zero\n", n);
    }
    else
    {
        printf("%d is negative\n", n);
    }

    return (0);
=======
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n > 0)
		printf("%d is positive\n", n);
	else if (n == 0)
		printf("%d is zero\n", n);
	else
		printf("%d is negative\n", n);

	return (0);
>>>>>>> Add program to print if random number is positive, negative, or zero
}
