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
#include <string.h>
#include "temp_function.h"

#define NUMBER_MEASUREMENTS 200

struct sensor
{
	uint8_t minutу;
	uint8_t hour;
	uint8_t day;
	uint8_t month;
	uint16_t year;
	int8_t t;
};

int main(int argc, char **argv)
{
	 struct sensor data[NUMBER_MEASUREMENTS]; // массив из 200 структур
	return 0;
}
