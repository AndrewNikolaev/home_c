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


float abs(float d)
{
	return d<0 ? -d:d;
}

float cosinus (float x)
{
	
	float cos_x=0; 
	float rad = x*3.1415926535/180;
	float term=1;
	int n=0;
	int sigh = 1;
	while (abs(term)>0.0005f)
	{
		cos_x+=sigh*term;
		n+=2;
		term=term * rad * rad / ((n-1)*n);
		sigh *=(-1);		
	}

	return cos_x;
}
	
int main(void)
{
	float a;
	scanf("%f",&a);
	printf ("%.3f", cosinus(a));
	return 0;
}



