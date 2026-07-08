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
 
#define SIZE 10001

void input(char *strIn)
{
FILE *in;
	
    in = fopen("input.txt", "r");
	
    while(fscanf(in, "%[^\n]", strIn) == 1);
	
    fclose(in);
}
 
void changeName(char *strExt, char *buffer)
{
int count = 0;
	
    for(int i =  0; i < strlen(strExt); i++)
    {  
        if(!memcmp(strExt+i,"Ling",4))
        {
            strcat(buffer, "Cao");
            count += 3;
            i += 4;
        }
        buffer[count++] = strExt[i];
    }
}
void output(char *strOut)
{  
FILE *out;
    out = fopen("output.txt", "w");
    fprintf(out, "%s", strOut);
    fclose(out);
}
 
int main(int argc, char **argv)
{
char str[SIZE]={0}, strFinal[SIZE]={0};
    input(str);
    changeName(str, strFinal);
    output(strFinal);
    return 0;
}



