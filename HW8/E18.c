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

void PrintMultCount(int n)
{
    int count = 0; 
	for (int j=2; j < 10; j++) 
	{		
		count = 0; 
		for (int i = 2; i <= n; i++)
		{
			if (i%j==0)
			{
				count++;	
			}
		}
	printf("%d %d\n",j,count);			
	} 
return;
}
 
int main(void)
{
	int a;
	scanf("%d",&a);
	PrintMultCount(a);
	return 0;
}


