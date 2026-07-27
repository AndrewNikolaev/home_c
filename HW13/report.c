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

int main(int argc, char **argv)
{
	printf("\n\tProgram started\n");
	sensor *data = NULL; // заводим динамический массив
	int number = 0;
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
			// printf("found argument \"f = %s\".\n", optarg);
			{
				FILE *open;
				const char *name = optarg;
				open = fopen(name, "r");
				if (open == NULL)
					return 1;
				int Y, M, D, H, m, T, n_scan;
				char line[256];
				uint32_t countLine = 0;
				uint32_t countWrongLine = 0;
				while (fgets(line, sizeof(line), open))
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
							AddRecord(data, number, Y, M, D, H, m, T);
							number++;
						}
					}
				}

				if (number == 0)
				{
					printf("\n\033[31mThe file\033[0m %s \033[31mempty or invalid. Please, select a file containing valid data.\033[0m\n\n", name);
				}
				else if (countWrongLine == 0)
				{
					printf("\n\033[32mFile \033[0m%s \033[32mprocessed successfully.\033[0m\n\n", name);
					print_report(data, number);
				}
				else
				{
					printf("\n\033[31mFile\033[0m %s \033[31mcontains %d error%s\033[0m\n\n", name, countWrongLine, countWrongLine > 1 ? "s." : ".");
					print_report(data, number);
				}

				fclose(open);
			}
			break;
		case 'm':
		{
			int month = atoi(optarg);
			if (month >= 1 && month <= 12)
			{
				print_report_month(data, number, month);
			}
			else
			{
				printf("Invalid month: %s\n", optarg);
			}
			if (number == 0)
				printf("No data");
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
	free(data);
	return 0;
}
