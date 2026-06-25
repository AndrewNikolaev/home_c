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

int Input(int* arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
	}
    return i;
}

void Print(int *arr,int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}


int sum_between_ab(int from, int to, int size, int a[])
{
	int sum=0;
	int left = (from < to) ? from : to;
	int right = (from > to) ? from : to;
	for (int i=0; i<size; i++)
	{
		if(a[i] >= left && a[i] <= right)
			{
				sum+=a[i];
			}
	}
return sum;
}
 
int main(void)
{
    int from, to;
	scanf("%d %d", &from, &to);
    int arr[SIZE]={0};
	Input(arr,SIZE);
    printf("%d",sum_between_ab(from,to,SIZE,arr));
	return 0;
}


