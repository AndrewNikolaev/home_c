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

int is_two_same(int size, int a[])
{

	for (int i = 0;i<size; i++)
	{
		for (int j = i+1;j<size; j++)
		{
			if (a[i]==a[j])
			{
				return 1;
				break;
			}
		}
	} 
return 0;
}
 
int main(void)
{
    int arr[SIZE]={0};
    Input(arr,SIZE);
    is_two_same(SIZE,arr) == 1 ? printf("YES"):printf("NO");
	return 0;
}


