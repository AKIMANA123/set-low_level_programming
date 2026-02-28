#include "main.h"

/**
* convert_day - converts day of month to day of year, without accounting
* for leap year
* @month: month in number format
* @day: day of month
* Return: day of year
*/

int convert_day(int month, int day)
{
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day_of_year = 0;
int i;

/* Sum days in previous months */
for (i = 0; i < month - 1; i++)
{
day_of_year += days_in_month[i];
}

/* Add current day */
day_of_year += day;

return (day_of_year);
}
