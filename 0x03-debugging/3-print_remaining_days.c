#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int is_leap = 0;
int day_of_year = 0;
int i;

/* Check for leap year */
if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
{
is_leap = 1;
days_in_month[1] = 29; /* February has 29 days in leap year */
}

/* Validate February 29 in non-leap years */
if (month == 2 && day == 29 && !is_leap)
{
printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
return;
}

/* Calculate day of year */
for (i = 0; i < month - 1; i++)
{
day_of_year += days_in_month[i];
}
day_of_year += day;

printf("Day of the year: %d\n", day_of_year);

if (is_leap)
{
printf("Remaining days: %d\n", 366 - day_of_year);
}
else
{
printf("Remaining days: %d\n", 365 - day_of_year);
}
}
