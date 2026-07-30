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
#include "temp_functions.h"

int main(int argc, char **argv)
{
	sensor *data = NULL; // заводим динамический массив
	int number = 0;
	int rez = 0;
	int month_requested = 0;
	int year_requested = 0;
	int sort_requested = 0;

	if (argc == 1)
		printf("enter -h for help\n\n");
	while ((rez = getopt(argc, argv, "hf:m:ys:")) != -1)
	{
		switch (rez)
		{
		case 'h':
			printf("Usage: report.exe [options]\n");
			printf("Options:\n");
			printf("  -h           Show this help message\n");
			printf("  -f <file>    Input CSV file \n");
			printf("  -m <month>   Show statistics for the specified month (1-12)\n");
			printf("  -y           Show yearly statistics\n");
			printf("  -s <type>    Sort data: 't' - by temperature, 'd' - by date (max 100 records)\n");
			break;
		case 'f':
		{
			FILE *fp;
			const char *name = optarg;
			fp = fopen(name, "r");
			if (fp == NULL)
			{
				printf("\n\033[31mFile\033[0m %s \033[31m not found\033[0m\n\n", name);
				return 1;
			}
			int Y, M, D, H, m, T;
			char line[256];
			uint32_t countLine = 0;
			uint32_t countWrongLine = 0;
			while (fgets(line, sizeof(line), fp))
			{
				if (strlen(line) > 1)
				{
					countLine++;
					if (sscanf(line, "%04d;%02d;%02d;%02d;%02d;%3d", &Y, &M, &D, &H, &m, &T) != 6)
					{
						printf("\033[31mWrong format in line %d: %s\033[0m", countLine, line);
						countWrongLine++;
					}
					else
					{
						data = realloc(data, (number + 1) * sizeof(sensor));
						if (data == NULL)
						{
							printf("\n\033[31mMemory allocation error!\033[0m\n");
							fclose(fp);
							return 1;
						}
						AddRecord(data, number, Y, M, D, H, m, T);
						number++;
					}
				}
			}

			if (number == 0)
			{
				printf("\n\033[31mThe file\033[0m %s \033[31mempty or invalid. Please, select a file containing valid data.\033[0m\n\n", name);
				break;
			}
			else if (countWrongLine == 0)
			{
				printf("\n\033[32mFile \033[0m%s \033[32mprocessed successfully.\033[0m\n\n", name);
			}
			else
			{
				printf("\n\033[31mFile\033[0m %s \033[31mcontains %d error%s\033[0m\n\n", name, countWrongLine, countWrongLine > 1 ? "s." : ".");
			}

			fclose(fp);
		}
		break;
		case 'm':
		{
			int month = atoi(optarg);
			if (number == 0)
			{
				printf("No data\n");
				month_requested = 1;
				break;
			}

			if (month >= 1 && month <= 12)
			{
				print_report_month(data, number, month);
			}
			else
			{
				printf("Invalid month: \033[31m%s\033[0m\n", optarg);
			}
			month_requested = 1;
			break;
		}
		case 'y':
			if (number == 0)
			{
				printf("No data\n");
				year_requested = 1;
				break;
			}
			print_report_year(data, number);
			year_requested = 1;
			break;
		case 's':
		{
			if (number > 100)
			{
				printf("\033[31mThe maximum number of measurements for sorting is 100.\033[0m\n\n");
				sort_requested = 1;
				break;
			}
			printf("============================================");
			if (strcmp(optarg, "t") == 0)
			{
				printf("\n=========  \033[33mSorting by temperature.\033[0m =========\n");
				qsort(data, number, sizeof(struct sensor), CompareByTemp);
				sort_requested = 1;
			}
			else if (strcmp(optarg, "d") == 0)
			{
				printf("\n============  \033[33mSorting by date.\033[0m  ============\n");
				qsort(data, number, sizeof(struct sensor), CompareByDate);
				sort_requested = 1;
			}
			else
				printf("Invalid sort option : \033[31m%s\033[0m\n\n", optarg);
			if (sort_requested == 1)
			{
				print_temp(data, number);
				printf("============================================\n\n");
			}
			break;
		}
		case '?':
			printf("Error found !\n");
			break;
		default:
			break;
		}
	}

	if (number > 0 && month_requested == 0 && year_requested == 0 && sort_requested == 0)
	{
		print_report(data, number);
	}
	free(data);
	return 0;
}
