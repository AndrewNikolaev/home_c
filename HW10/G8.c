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

int is_num=0;
int k = 0;

FILE *f_in, *f_out;
char name_in[]="input.txt";
char name_out[]="output.txt";
	f_in=fopen(name_in,"r");
	f_out=fopen(name_out,"w");
char str[1002];
int number[400] = {0};
	fgets( str,sizeof(str),f_in);
    fclose (f_in);
    for(int i=0; i<strlen(str);i++)
    {
		if(str[i]>='0'&& str[i]<='9')
		{
			number[k] = number[k]*10+(str[i]-'0');
			is_num++;
		}
		else if (is_num>0)	
		{
			is_num=0;
			k++;
		}		
	}
	for (int j=0; j<k;j++)
	{
		for (int l=j+1; l<k; l++)
		{
			if(number[j]>number[l])
			{
				int temp = number[l];
				number[l]=number[j];
				number[j]=temp;				
			}
		}
		fprintf(f_out,"%d ",number[j]);
	}
    fclose (f_out);
    return 0;
}


