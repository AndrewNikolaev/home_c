/*
 * report.c
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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "temp_function.h"

#define NUMBER_MEASUREMENTS 200

int main(int argc, char **argv)
{
	printf("Program started\n");
	struct sensor data[NUMBER_MEASUREMENTS]; // массив из 200 структур
	int number = AddInfo(data);
	int rez = 0;
	// qsort(data, number, sizeof(struct sensor), CompareByTemp);
	// SortByT(data,number);
	// qsort(data, number, sizeof(struct sensor), CompareByDate);
	// print_temp(data, number);

	if (argc == 1)
		printf("-h help\n");
	while ((rez = getopt(argc, argv, "hf:m:y")) != -1)
	{
		switch (rez)
		{
		case 'h':
			printf("Usage: report.exe [options]\n");
			printf("Options:\n");
			printf("  -h           Show this help message\n");
			printf("  -f <file>    Input CSV file (not implemented yet)\n");
			printf("  -m <month>   Show statistics for the specified month (1-12)\n");
			printf("  -y           Show yearly statistics\n");
			break;
		case 'f':
			printf("found argument \"f = %s\".\n", optarg);

			break;
		case 'm':
		{
			int month = atoi(optarg);
			if (month >= 1 && month <= 12)
			{
				print_stat_month(data, number, month);
			}
			else
			{
				printf("Invalid month: %s\n", optarg);
			}
			break;
		}
		case 'y':
			print_stat_year(data, number);
			break;
		case '?':
			printf("Error found !\n");
			break;
		default:
			break;
		}
	}

	// print_stat_year(data,number);
	// print_stat_month(data,number,MONTH);
	// print_temp(data, number);
	return 0;
}
