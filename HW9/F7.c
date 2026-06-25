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
#define SIZE 6

int Input(int* arr, int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    return i;
}

void Print(int *arr, int len)
{
	for(int i=0; i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int compression(int a[], int b[],int N)
{
	int count=1;
	int i=1;
	int j=0;
	if (a[0]==1) 
	{
		b[j]=0;
		j++;
	}
	while(i<N)
	{
		if(a[i]==a[i-1])
		{
			count++;
		}
		else
		{
			b[j]=count;
			j++;	
			count = 1;		
		}
		i++;		
	}
	b[j]=count;
	j++;
return j;
}
 
int main(void)
{
    int arr[SIZE]={0};
    int b[10]={0};
    int len=0;
    Input(arr,SIZE);
	len = compression(arr,b,SIZE);
	Print(b,len);
	return 0;
}


