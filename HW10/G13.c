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
int last_slash = 0;
int last_dot = -1;

	fgets( str,sizeof(str),f_in);
    fclose (f_in);
    for(int i=0; i<strlen(str);i++)
    {
		if(str[i]=='/')
		{
			last_slash=i;
		}
	}
	 for(int j=last_slash+1; j<strlen(str);j++)
    {
		if(str[j]=='.')
		{
			last_dot=j;
		}
	}
	if(last_dot!=-1)
	{
		for(int k=0; k<=last_dot;k++)
		{
			fprintf(f_out,"%c",str[k]);
		}
		fprintf(f_out,"html");			
	}
	else
	{
		for(int l=0; l<strlen(str)-1;l++)
		{
			fprintf(f_out,"%c",str[l]);
		}
		fprintf(f_out,".html");
		
	}

    fclose (f_out);
    return 0;
}


