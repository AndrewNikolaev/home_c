#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define SIZE 10001

int min(int a,int b)
{
    return a<b? a:b;
}

int main(void)
{
char str1[SIZE] = {0};
char str2[SIZE] = {0};
int exist = 0;
    scanf("%s",str1);
    scanf("%s",str2);
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    for (int len = min(len1, len2); len > 0; len--) {
		if (strncmp(str1, str2 + len2 - len, len) == 0) {
			printf("%d ",len);
			exist=1;        
			break;
		}
		else exist=0;    
	}
	if (exist==0) printf("0 ");
	exist=0;
	    for (int len = min(len1, len2); len > 0; len--) {
		if (strncmp(str2, str1 + len1 - len, len) == 0) {
			printf("%d",len);
			exist=1;        
			break;
		}
		else exist=0;    
	}
	if (exist==0) printf("0");
	
    return 0;
}
