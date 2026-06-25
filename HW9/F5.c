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
#define SIZE 5

int Input(int* arr, int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    return i;
}

int find_max_array(int size, int a[])
{

    int max=a[0];
	for (int i = 0;i<size; i++)
	{
		if (a[i]>max)
		{
			max=a[i];
		}
		
	} 
return max;
}
 
int main(void)
{
    int arr[SIZE]={0};
    Input(arr,SIZE);
	printf("%d",find_max_array(SIZE,arr));
	return 0;
}


