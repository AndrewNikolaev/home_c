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

void CountNumber(int n,int *digits)
{
		while(n>0)
		{
			digits[n % 10]++;
			n/=10;
		}
}
 
int main(void)
{
	int a;
	int digits[10]={0};
	scanf("%d",&a);
	CountNumber(a,digits);
	for (int i = 9; i >= 0; i--)
	{
		while(digits[i]!=0)
		{
			printf("%d",i);
			digits[i]--;
		}
	}
	return 0;
}


