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

#define SIZE 12
#define SHIFT 4

int Input(int *arr, int n)
{
	int i;
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	return i;
}

void Print(int *arr, int len)
{
	for(int i=0; i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void SwapArr(int *arr,int i,int j)
{
	int temp = arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void Reverse (int *arr, int h, int len)
{
	int k=0;
	int i=0;
	for (i=h, k=len-1; i<k;i++,k--)
		SwapArr(arr,i,k);
}
void ShiftRight (int *arr, int h, int len)
{
	Reverse(arr,0,len);
	Reverse(arr,0,h);
	Reverse(arr,h,len);	
	
}
	
int main(void)
{
	int arr[SIZE];
	Input (arr,SIZE);	
	ShiftRight(arr,SHIFT,SIZE);
	Print(arr,SIZE);
	return 0;
}


