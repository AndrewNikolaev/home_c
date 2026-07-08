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
#include <string.h>

int is_palindrom(char str[])
{
	int len=strlen(str);
	for (int i=0; i<len/2;i++)
	{
		if(str[i]!=str[len-1-i])
			return 0;			
	}
return 1;
}

int main(void){

FILE *f_in, *f_out;
char name_in[]="input.txt";
char name_out[]="output.txt";
	f_in=fopen(name_in,"r");
	f_out=fopen(name_out,"w");
char str[1000];
	fscanf( f_in,"%s",str);
    fclose (f_in);
	is_palindrom(str)==1 ? fprintf(f_out,"YES"):fprintf(f_out,"NO");
    fclose (f_out);
    return 0;
}


