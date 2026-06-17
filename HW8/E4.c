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

int Input(int *arr, int n)
{
	int i;
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	return i;
}
void SwapArr(int *arr,int i, int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void BubbleSort (int *arr, int len)
{
int noSwap;
	for (int i=0;i<len;i++)
	{
		noSwap=1;
		for(int j=len-1;j>i;j--)
		{
			if(arr[j-1]>arr[j])
			{
				SwapArr(arr,j-1,j);
				noSwap=0;
			}			
		}
		if(noSwap)
			break;
	}

}	
int main(void)
{
	int arr[SIZE];
	Input (arr,SIZE);	
	BubbleSort(arr,SIZE);
	printf ("%d",arr[SIZE-1]+arr[SIZE-2]);
	return 0;
}


