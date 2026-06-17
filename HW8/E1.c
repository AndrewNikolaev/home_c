/*
 * A6.c
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

int Input(int *arr, int n)
{
	int i;
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	return i;
}
int Summ (int *arr, int len)
{
	int sum=0;
	for (int i=0;i<len;i++)
		sum+=arr[i];
	return sum;
}
	
int main(void)
{
	int arr[5];
	Input (arr,5);
	printf ("%.3f",((float)Summ(arr,5)/5));
	return 0;
}


