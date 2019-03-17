#include<stdio.h>
int main()
{
	long i,j,a[2],flag,max;
	while(scanf("%ld%ld",&a[0],&a[1])!=EOF)
	{
		max=0;
		for(i=(a[0]>a[1]?a[1]:a[0]);i<=(a[1]>a[0]?a[1]:a[0]);i++)
		{
			flag=0;
			j=i;
			while(j!=1)
			{	
				flag++;
				if(j%2==0)
					j=j/2;
				else
					j=j*3+1;
			}
			if(++flag>max)
				max=flag;
		}
		printf("%ld %ld %ld\n",a[0],a[1],max);
	}
	return 0;
 } 
  