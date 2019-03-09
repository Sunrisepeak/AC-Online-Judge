#include<stdio.h>
long number(long n)
{
	if(n==1)
		return 1;
	if(n%2==0)
		n=n/2;
	else
		n=3*n+1;
	return number(n)+1;
}
int main()
{
	long i,j,k,flag,max;
	while(scanf("%ld%ld",&i,&j)!=EOF)
	{
		max=0;
		for(k=(i>j?j:i);k<=(j>i?j:i);k++)
		{
			flag=number(k);
			if(max<flag)
				max=flag;
		}
		printf("%ld %ld %ld\n",i,j,max);
	}
	return 0;
}
  