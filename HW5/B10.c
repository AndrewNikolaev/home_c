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
#include <stdbool.h>

int main(int argc, char **argv)
{
	int a;
	bool riseNum = true; 
	scanf("%d",&a);
	while (a!=0) 
	{
	if ((a%10)<(a/10)%10 || (a%10)==(a/10)%10)
	{
		riseNum = false;
		break;
	}
	a=a/10;	
	}	
	riseNum==true ? printf("YES"):printf("NO");

	return 0;
}

