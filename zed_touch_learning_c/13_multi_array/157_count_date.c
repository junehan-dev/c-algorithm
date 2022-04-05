static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) /* whole dayz in specific year. */
{
    int i, leap;

    leap = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)); /* leap year or not? */
    i = 1;
    while(i < month)
        day += daytab[leap][i++];
    return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday) /* dayz in specific year-month */
{
    int i, leap;

    leap = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    i = 1;
    while(yearday > daytab[leap][i])
        yearday -= daytab[leap][i++];
    *pmonth = i;
    *pday = yearday;
}

/*
 * char type data in multi array,
 * if data figured as charater, it will substitute as ascii. 
 * but char data can store about -256 ~ 255.
 * store as char, read as int.
 */
#include <stdio.h>

int main()
{    
    /*
    int yearday;
    yearday = day_of_year(2020, 12, 0); // month 0~12
    int *pday, *pmonth;
    month_day(2020, yearday, pmonth, pday);
    printf("pmonth: %d, pday: %d", *pday, *pmonth);
    */
    int *val;
    *val = 10;
    printf("%p", val);
}
