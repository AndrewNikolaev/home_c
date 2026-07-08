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

int main(void){
	
FILE *f_in, *f_out;
char name_in[]="input.txt";
char name_out[]="output.txt";
	f_in=fopen(name_in,"r");
	f_out=fopen(name_out,"w");
char str[1002];

int is_word = 0;
int count = 0;
int count_max = 0;
int start = 0;
int start_max = 0;

	fgets( str,sizeof(str),f_in);
    fclose (f_in);
    for(int i=0; i<strlen(str);i++)
    {
		 if (str[i]!=' ')		 
		{
			if (is_word==0)
			{
				start=i;
			}
			count++;
			is_word=1;			
		}
		else 
		{
			if (count_max<count)
			{
				start_max = start;
				count_max = count;
			}
			is_word=0;
			count = 0;			
		}		
	}
	if (is_word && count > count_max) {
    count_max = count;
    start_max = start;
}
	for (int j = start_max; j < start_max+count_max; j++)
	{
		fprintf(f_out,"%c",str[j]);
	}
	
    fclose (f_out);
    return 0;
}


