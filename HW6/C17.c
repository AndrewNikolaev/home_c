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

int is_happy_number (int x)
{
	int sum=0;
	int prod=1;
	int res = 1;
	while(x>0)
	{
		sum=sum+x%10;
		prod=prod*(x%10);
		x=x/10;
	}
	if(sum != prod) res=0;

	return res;
}
	
int main(void)
{
	int a;
	scanf("%d",&a);
	is_happy_number(a) == 1 ? printf ("YES"):printf ("NO");
	return 0;
}




