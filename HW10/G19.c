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
#define SIZE 26
int main() 
{
FILE *f_in = fopen("input.txt", "r");
FILE *f_out = fopen("output.txt", "w");
 
char str[1002];
int odd;
int a[SIZE] = {0};
 
    fgets(str, sizeof(str), f_in);
 
    for(int i=0; str[i] != '\n' && str[i]; ++i)
        a[str[i] - 'a']++;
 
    for(int i = 0; i < SIZE; ++i)
        if (a[i] % 2 != 0)
        {
            odd = i;
            break;
        }
 
    for(int i = 0; i < SIZE; ++i)
        if (a[i] > 0)
            for (int j = 0; j < a[i]/2; ++j)
                fprintf(f_out, "%c", i + 'a');
 
    fprintf(f_out, "%c", odd + 'a');
 
    for(int i = SIZE-1; i >= 0; --i)
        if (a[i] > 0)
            for (int j = 0; j < a[i]/2; ++j)
                fprintf(f_out, "%c", i + 'a');
    fclose(f_in);
    fclose(f_out);
    return 0;
}

