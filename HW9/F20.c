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

int Input(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
		scanf("%d",&arr[i]);
	}
return i;
}

void Print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int count_even_odd(int arr[],int n)
{
    int i;    
    int count_even=0;
    int count_odd=0;
 	for(i=0;i<n;i++)
    {
		if(arr[i]%2==0)	
			count_even++;
		else
			count_odd++;
	}
	
return	count_even>count_odd? 1:0;
}

void change_number (int arr[],int n,int comand)
{
	for (int i = 0; i < n; i++)
{
    if (arr[i] % 2 == comand) 
    {
        int num = arr[i];
        int p = 1;
        int has_digit = 0;
        while (num > 0)
        {
            int digit = num % 10;
            if (digit % 2 == comand) 
            {
                p *= digit;
                has_digit = 1;
            }
            num /= 10;
        }
        arr[i] = has_digit ? p : 0;
    }
}
}

int main(void)
{
	int arr [SIZE]={0};
	int a;
	Input(arr,SIZE);
	a=count_even_odd(arr,SIZE);
	change_number(arr,SIZE,a);
	Print(arr,SIZE);
	//~ printf("%d",a);
	return 0;
}


