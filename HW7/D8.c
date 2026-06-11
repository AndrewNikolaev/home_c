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

void print_range (int a,int b)
{
	if (a<b) 
	{
		printf ("%d ",a);
		print_range (a+1,b);
	}
	if (a>b)
	{
		printf ("%d ",a);
		print_range (a-1,b);		
	}
	if (a==b) 
	{
		printf ("%d ",a);
		return;
	}
}
	
int main(void)
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	print_range(a,b);
	return 0;
}



