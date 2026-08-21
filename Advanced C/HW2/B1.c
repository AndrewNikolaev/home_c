/*
 * A0.c
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
#include <stdlib.h>

//список о выделенной памяти
typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

list *memlist = NULL;



size_t totalMemoryUsage(list *head){
	    size_t totalMemory = 0;	     
	    if(head == NULL)//если списко пустой - выходим 
        return 0;
        while(head) {
        totalMemory+=head->size;
        head = head->next;
		}
return totalMemory;	
}

//добавление  информация в однонаправленный список о новом блоке выделенной памяти
void insert(list **head, uint64_t address, size_t size, char *comment) {
    list *tmp = malloc(sizeof(list));
    tmp->next = *head;
    tmp->address = address;
    tmp->size = size;
    sprintf(tmp->comment,"%s",comment);
    *head = tmp;
}

_Bool delete(list **head, uint64_t address) {
    if(*head == NULL)//если списко пустой - выходим 
        return 0;
    list *del = NULL;
    if( (*head)->address == address) {
        del = *head;
        *head = (*head)->next;
        free(del);
        return  1;
    }
    list *tmp = *head;
    while( tmp->next ) {
        if(tmp->next->address == address ) {
            del = tmp->next;
            tmp->next = del->next;
            free(del);
            return 1;
        }
        tmp=tmp->next;
    }
    return 0;
}

void printList(list *head) {
    if(head == NULL) {
        printf("No memory leak detect\n");
    }
    while(head) {
        printf("%s\n",head->comment);//выводим диагностику
        head = head->next;
    }
}

void* my_malloc(size_t size, const char *file, int line, const char *func)
{
    void *ptr = malloc(size);
    char coment[64] = {0};
    sprintf (coment,"Allocated = %s, %i, %s, %p[%lli]", file, line, func, ptr, size);    
    insert(&memlist,ptr,size,coment);   
    return ptr;
}

void my_free(void *ptr, const char *file, int line, const char *func)
{
    delete(&memlist, ptr);
    free(ptr);
}


//макрос, который заменяет стандартный вызов функции malloc() на вызов функции  my_malloc() и аналогичный макрос для вызова функции free()
#define malloc(X) my_malloc( (X), __FILE__, __LINE__, __FUNCTION__)
#define free(X) my_free( (X), __FILE__, __LINE__, __FUNCTION__)


int main(void) {
    int *p  = malloc( sizeof(int) );//my_malloc
    //~ int *p  = my_malloc( sizeof(int), __FILE__, __LINE__, __FUNCTION__ );//my_malloc
    int *ar = malloc(sizeof(int)*10);
    *p = 5;
    free(p);
    p = malloc(sizeof(int));

    free(p);
    printList(memlist);
    return 0;
}

