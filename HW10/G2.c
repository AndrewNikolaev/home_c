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
		int digit=2, n;
		char let = 0;
		f = fopen("input.txt","r"); // открытие файла input.txt на чтение
		fscanf (f, "%d", &n);
        fclose (f);
		
		f = fopen("output.txt","w"); // открытие файла input.txt для записи
		for (int j=1; j<=n; j++)
		{
			if(j%2==1)				
				fprintf (f, "%c",(char)('A'+let++));
			else
			{
				if (digit<9)
				{
					fprintf (f,"%d",digit);
					digit+=2;	
				}
				else	
				{
					digit=2;	
					fprintf (f,"%d",digit);
					digit+=2;
				}
			}
		}
    fclose (f);
    return 0;
}


