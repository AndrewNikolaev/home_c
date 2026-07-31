/*
 * A0.c
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
#include <stdint.h>
union floatbit{
	float value;
	struct {
		uint32_t mant : 23;
		uint32_t exp : 8;
		uint32_t sign : 1;
	}bit;
}f;

int extractExp(float f)
{
	union floatbit tmp;    
	tmp.value = f;    
	return tmp.bit.exp;
}
		

int main(int argc, char **argv)
{
	
	float f;
	
	scanf("%f",&f);
	printf("%d",extractExp(f));
	
	return 0;
}

