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

void print_num (int n)
{
	if(n==0)
	{
		return;
	}
	if(n>0)
	{
	print_num (n/2);
	printf("%d", n%2);	
	}
}
	
int main(void)
{
	int a;
	scanf("%d",&a);
	if(a==0)
		printf("0");
	else	
		print_num (a);
	return 0;
}




