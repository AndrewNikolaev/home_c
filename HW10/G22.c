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
void soundex(char s[],char res[])
{
	int count = 0;
	for (int i = 0; i < strlen(s) && count<4; i++)
	{
		if (i==0)
		{
			res[0]=s[0];
			count++;			
		} 
		else if(s[i]=='b'||s[i]=='f'||s[i]=='p'||s[i]=='v')
		{
			if (res[count-1]!='1')
			{
				res[count]='1';
				count++;
			}			
		}
		else if(s[i]=='c'||s[i]=='g'||s[i]=='j'||s[i]=='k'||s[i]=='q'||s[i]=='s'||s[i]=='x'||s[i]=='z')
		{
			if (res[count-1]!='2')
			{
				res[count]='2';
				count++;
			}			
		}
		else if(s[i]=='d'||s[i]=='t')
		{
			if (res[count-1]!='3')
			{
				res[count]='3';
				count++;
			}			
		}
		else if(s[i]=='l')
		{
			if (res[count-1]!='4')
			{
				res[count]='4';
				count++;
			}			
		}
		else if(s[i]=='m'||s[i]=='n')
		{
			if (res[count-1]!='5')
			{
				res[count]='5';
				count++;
			}			
		}
		else if(s[i]=='r')
		{
			if (res[count-1]!='6')
			{
				res[count]='6';
				count++;
			}			
		}	
	}
	if(count<4)
		{
			while(count!=4)
			{
				res[count++]='0';
			}
		}
	res[count] = '\0';
	
return;	
}

int main(void){

FILE *f_in,*f_out;
char name_in[]="input.txt";
char name_out[]="output.txt";
	f_in=fopen(name_in,"r");
	f_out=fopen(name_out, "w");		
char str[1002];
char arr[100];
	fgets( str,sizeof(str),f_in);
	str[strcspn(str, "\n")] = '\0';
    fclose (f_in);
    soundex(str,arr);
    fprintf(f_out,"%s",arr);
    fclose (f_out);
    return 0;
}


