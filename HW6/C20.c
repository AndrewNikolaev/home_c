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

int digit_to_num (char c)
{
	if (c=='(')
		return 1;
	else if	(c==')')
		return -1;
	else
		return 0;
}
	
int main(void)
{
	char c;
	int sum = 0;
	while ((c=getchar())!='.'&& (sum>=0))
	{		
		sum+=digit_to_num(c);
	}
	if (sum==0) 
		printf("YES");
	else
		printf("NO");
	return 0;
}




