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
int count;
	
FILE *f_in, *f_out;
char name_in[]="input.txt";
char name_out[]="output.txt";
	f_in=fopen(name_in,"r");
	f_out=fopen(name_out,"w");
char word_one[100];
char word_two[100];
	fscanf (f_in, "%s %s", word_one,word_two);
    fclose (f_in);
    for (int i=0; i< strlen(word_one);i++)
    {
		count=0;
		for (int j=0; j<strlen(word_one);j++)
		{
			if(word_one[i]==word_one[j] && i!=j)
			{
				count++;
			}
		}
		if(count==0)
		{
			for (int k=0; k<strlen(word_two);k++)
			{
				if(word_one[i]==word_two[k])
				{
					count++;
				}
			}
			
				if(count==1)
					fprintf (f_out, "%c ",word_one[i]);							
		}
	}
    fclose (f_out);
    return 0;
}


