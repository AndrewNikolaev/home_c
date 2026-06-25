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

#define SIZE 10

void Input(int arr[][SIZE])
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
		for(j=0;j<SIZE;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}

int Count(int arr[][SIZE])
{
    int i,j;
    int sum = 0;    
 	for(i=0;i<SIZE;i++)
    {
		int max = arr[i][0];
		for(j=0;j<SIZE;j++)
		{
			if (arr[i][j]>max)
				max=arr[i][j];
		}
		sum+=max;	
		max = 0;	
	}
return	sum;
}

int main(void)
{
	int arr [SIZE][SIZE]={0};
	Input(arr);
	printf ("%d\n",Count(arr));
	return 0;
}


