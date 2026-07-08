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
int count_stone (char s[])
{
	int count = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i]=='*')
		{
			count++;			
		} 
	}	
return count;	
}

int main(void){

FILE *f_in,*f_out;
char name_in[]="input.txt";
char name_out[]="output.txt";
	f_in=fopen(name_in,"r");
	f_out=fopen(name_out, "w");		
char str[1002];
int count=0;
int lev=0;
	while (fgets(str, sizeof(str), f_in) != NULL) 
	{
		count += count_stone(str);
	}
	str[strcspn(str, "\n")] = '\0';
    fclose (f_in);
    for(int k=1; k<100;k++)
    {
		if(k*(k+1)/2==count)
		{
			lev = k;
		}
	}
	if (lev==0) 
		fprintf(f_out,"NO");	
	else
	{
		for (int i = 0; i < lev; i++)
		{
			for (int j = 0; j < lev-i-1; j++)
			{
				fprintf(f_out," ");	
			}
			for (int l = 0; l < i+1; l++)
			{
				fprintf(f_out,"* ");	
			}
			fprintf(f_out,"\n");		
		}
	}
    fclose (f_out);
    return 0;
}


