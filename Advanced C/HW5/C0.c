#include <stdio.h>

int cnk2(int n, int k) {
    double res = 1;
    for (int i=1; i<=k; ++i)
        res = res * (n-k+i) / i;
    return (int) (res + 0.01);
}

int main(void) 
{
    char c;
    char digit[1000];
    int a[1000];
    int count=0;
    int len=0;
    int num=0;
    int equal=0;
    while((c=getchar())!='\n')
        digit[len++]=c;
    digit[len]=0;
    for (int i=0; i<len; i++)
			for (int j=i+1; j<len; j++)
				for (int k=j+1; k<len; k++)
				{
					if (digit[i] != '0') 
						num=(digit[i]-'0')*100+(digit[j]-'0')*10+(digit[k]-'0');
					if(count!=0)
					{
						equal=0;
						for(int b=0; b<count && equal!=1 ;b++)
							{
								if(num==a[b])
									equal=1;										
							}
						if(equal==0 && num!=0)
						{
							a[count++]=num;
							//printf ("%d\n", num);
						}
					}
					else
					{
						a[count++]=num;												
						//printf ("%d\n", num);
					}
				}				

printf ("%d\n", count);
    return 0;
}
