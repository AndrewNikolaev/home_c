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
int PosMin (int *arr, int len)
{
int min=arr[0],pos=0;
	for (int i=0;i<len;i++)
		if (min>arr[i])
		{
			min=arr[i];
			pos=i;
		}
return pos;
}
int PosMax (int *arr, int len)
{
int max=arr[0],pos=0;
	for (int i=0;i<len;i++)
		if (max<arr[i])
		{
			max=arr[i];
			pos=i;
		}
return pos;
}	
int main(void)
{
	int arr[10];
	Input (arr,10);	
	printf ("%d %d %d %d",PosMax(arr,10)+1,arr[PosMax(arr,10)],PosMin(arr,10)+1,arr[PosMin(arr,10)]);
	return 0;
}


