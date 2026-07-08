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

int main(void){
    FILE *f;
		 char word[100], n;
		 int i=0;
		f = fopen("input.txt","r"); // открытие файла input.txt на чтение
        while (fscanf (f, "%c", &n) == 1)
        {
			if(n!='\n')
			{
				word[i] = n;
				i++;
			}
		}
		word[i]='\0';
		fclose (f);
		
		f = fopen("output.txt","w"); // открытие файла input.txt для записи
		for (int j=0; j<3; j++)
		{
			if(j)
				fprintf (f, ", ");
			fprintf (f,"%s",word);			
		}
		fprintf (f," %d",i);
    fclose (f);
    return 0;
}


