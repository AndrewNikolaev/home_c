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

int is_palindrom(char s[])
{
	int arr[26]={0};
	int count = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i]>='a' && s[i]<='z')
		{
			arr[s[i]-'a']++;			
		} 
	}
	for (int k=0; k<26; k++)
	{
		if (arr[k]%2!=0)
		{
			count++;
		}
	}
return count<2 ? 1:0;	
}

int main(void){

FILE *f_in;
char name_in[]="input.txt";
	f_in=fopen(name_in,"r");
		
char str[1002];
int res = 0;
	fgets( str,sizeof(str),f_in);
	str[strcspn(str, "\n")] = '\0';
    fclose (f_in);
    res = is_palindrom(str);
    res==1? printf("YES"):printf("NO");
    return 0;
}


