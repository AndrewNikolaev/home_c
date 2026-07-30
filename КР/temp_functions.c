/*
 * temp_functions.c
 *
 * Copyright 2026 a.nikolaev <a.nikolaev@TAG-5736>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "temp_functions.h"

const char *month_name[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"};

int min_temp_month(sensor *info, int number, uint8_t month)
{
    int min = 0;
    int found = 0;
    for (int i = 0; i < number; i++)
    {
        if (info[i].month == month)
        {
            min = info[i].t;
            found = 1;
            break;
        }
    }
    if (!found)
        return 100;

    for (int i = 0; i < number; i++)
    {
        if (info[i].t < min && info[i].month == month)
            min = info[i].t;
    }

    return min;
}

int max_temp_month(sensor *info, int number, uint8_t month)
{
    int max = 0;
    int found = 0;
    for (int i = 0; i < number; i++)
    {
        if (info[i].month == month)
        {
            max = info[i].t;
            found = 1;
            break;
        }
    }
    if (!found)
        return 100;

    for (int i = 0; i < number; i++)
    {
        if (info[i].t > max && info[i].month == month)
            max = info[i].t;
    }

    return max;
}

int average_temp_month(sensor *info, int number, uint8_t month)
{
    int avr = 0;
    int sum = 0;
    int found = 0;
    for (int i = 0; i < number; i++)
    {
        if (info[i].month == month)
        {
            sum += info[i].t;
            found++;
        }
    }
    if (!found)
        return 100;
    return avr = sum / found;
}

int min_temp_year(sensor *info, int number)
{
    int min = info[0].t;
    for (int i = 1; i < number; i++)
    {
        if (info[i].t < min)
            min = info[i].t;
    }

    return min;
}

int max_temp_year(sensor *info, int number)
{
    int max = info[0].t;
    for (int i = 1; i < number; i++)
    {
        if (info[i].t > max)
            max = info[i].t;
    }

    return max;
}

int average_temp_year(sensor *info, int number)
{
    int avr = 0;
    int sum = 0;
    for (int i = 0; i < number; i++)
    {
        sum += info[i].t;
    }

    return avr = sum / number;
}

void print_line(void)
{
    printf("===================================\n");
}

void print_start_table(int show_month)
{
    print_line();
    if (show_month != 0)
        printf("%-10s %6s %6s %6s\n", "|Month|", "|Average|", "|Min|", "|Max|");
    else
        printf("%-10s %6s %6s %6s\n", "", "|Average|", "|Min|", "|Max|");
    printf("%-10s %6s %8s %6s\n",
           "",
           "t*C",
           "t*C",
           "t*C");
    print_line();
}

void print_report_month(sensor *info, int number, uint8_t month)
{
    print_start_table(1);
    print_stat_month(info, number, month);
    print_line();
    printf("\n");
}

void print_report_year(sensor *info, int number)
{
    print_start_table(0);
    print_stat_year(info, number);
    print_line();
    printf("\n");
}

void print_report(sensor *info, int number)
{
    print_start_table(1);
    for (int i = 1; i < 13; i++)
    {
        print_stat_month(info, number, i);
    }
    print_line();
    print_stat_year(info, number);
}

void print_temp(sensor *info, int number)
{
    printf("============================================\n");
    for (int i = 0; i < number; i++)
        printf("\033[33mData:\033[0m %04d-%02d-%02d \033[33mTime:\033[0m %02d:%02d \033[33mTemperature=\033[0m%3d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].minute,
               info[i].t);
}
void print_stat_year(sensor *info, int number)
{
    printf("%-10s %5d %8d %6d\n",
           "Year",
           average_temp_year(info, number),
           min_temp_year(info, number),
           max_temp_year(info, number));
}

void print_stat_month(sensor *info, int number, uint8_t month)
{
    int max = max_temp_month(info, number, month);
    int min = min_temp_month(info, number, month);
    int avr = average_temp_month(info, number, month);

    if (min == 100 && max == 100 && avr == 100)
    {
        printf("%-10s %5s %8s %6s\n",
               month_name[month - 1],
               "-",
               "-",
               "-");
    }
    else
    {
        printf("%-10s %5d %8d %6d\n",
               month_name[month - 1],
               avr,
               min,
               max);
    }
}

void AddRecord(sensor *info, int number,
               uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].t = t;
}

int CompareByDate(const void *a, const void *b)
{
    sensor *sa = (sensor *)a;
    sensor *sb = (sensor *)b;

    if (sa->year != sb->year)
        return sa->year - sb->year;
    else if (sa->month != sb->month)
        return sa->month - sb->month;
    else
        return sa->day - sb->day;
}

int CompareByTemp(const void *a, const void *b)
{
    return ((sensor *)a)->t - ((sensor *)b)->t;
}