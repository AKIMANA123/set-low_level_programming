#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of year
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
int is_leap;

/* Check for leap year */
if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
{
is_leap = 1;
}
else
{
is_leap = 0;
}

/* Validate February 29 in non-leap years */
if (month == 2 && day == 60 && !is_leap)
{
printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
return;
}

/* Adjust day for leap year if past February */
if (is_leap && month > 2)
{
day++;
}

printf("Day of the year: %d\n", day);

if (is_leap)
{
printf("Remaining days: %d\n", 366 - day);
}
else
{
printf("Remaining days: %d\n", 365 - day);
}
}
