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
#define SIZE 1000

int Input(int* arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if (arr[i]==0) break;
	}
    return i;
}

int find_max (int a[])
{
	int max = 0;
	int i = 0;
	while (a[i]!=0)
	{
		if (a[i]>max)
		{
			max=a[i];
		}
	i++;
	}
return max;
}

int find_min (int a[])
{
	int min = a[0];
	int i = 0;
	while (a[i]!=0)
	{
		if (a[i]<min)
		{
			min=a[i];
		}
	i++;
	}
return min;
}

int find_sum (int m, int n)
{
	int sum=0;
	for (int i=m; i<=n; i++)
	{
		sum+=i;
	}
return sum;	
}

int find_missing(int a[],int N)
{
	int res=0;
	int sum=0;
	for (int i=0; i<N; i++)
	{
		sum+=a[i];		
	}	
	res = find_sum(find_min (a), find_max (a)) - sum;

return res;
}
 
int main(void)
{
    int arr[SIZE]={0};
    int len;
    len = Input(arr,SIZE);
    printf ("%d",find_missing(arr,len));
	return 0;
}


