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

int main(int argc, char **argv)
{
	uint32_t n;
	const uint8_t k = 26;	
	char c;		
	scanf("%u",&n);
	while((c=getchar())!='.')
	{
		if(c==' ')
			printf(" ");
		else if (c>='a'&& c<='z') 
			printf("%c",(c-'a'+n)%k+'a');
		else if(c>='A'&& c<='Z') 
			printf("%c",(c-'A'+n)%k+'A');
	}	
	printf(".");
	
	return 0;
}

