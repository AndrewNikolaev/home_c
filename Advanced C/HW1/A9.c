/*
 * A0.c
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


struct pack_array {
uint32_t array; // поле для хранения упакованного массива из 0 и 1
uint32_t count0 : 8; // счетчик нулей в array
uint32_t count1 : 8; // счетчик единиц в array
}arr;

void array2struct(int a[], struct pack_array *arr)
{	
	int i = 0;
	arr->array=0;
	while (i<32)
	{
		arr->array=arr->array<<1|a[i];
		if(a[i]==1) arr->count1++;
		if(a[i]==0) arr->count0++;	
		i++;	
	}	
}

int main(int argc, char **argv)
{
	int a[32] = {0};
	int i = 0;
	while (i<32)
	{
		scanf("%d", &a[i]);
		i++;
	}
	array2struct(a, &arr);
	
	printf ("%u %d %d", arr.array, arr.count0, arr.count1);
	return 0;
}


