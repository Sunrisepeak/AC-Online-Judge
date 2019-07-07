#include<stdio.h>
#include<math.h>
int a[8];
//1、大表法。2、数学->偶位回文数肯定不是质数
//判断回文的方法，数组，最快的是 i = a + b*10 + a(aba)   求余数
int prime(int number)
{
	for(int i = 2; i <= sqrt(number); i++)
	{
		if(number%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int n,b;
	scanf("%d%d",&n,&b);
	if(n%2 == 0)
		n++;
	for(int i = n; i <= b; i += 2)
	{
		int palindrome = 0;	
			if(i < 10)
				palindrome = 1;
			else 
				if(i < 100)
				{
					if(i == (i%10)*10 + i%10)
						palindrome = 1;
				}
				else 
					if(i < 1000)
					{				
						if(i == (i%10)*100 + (i/10)%10*10 + i%10)
							palindrome = 1;
					}
					else 
						if(i < 10000)
						{
					//		if(i == (i%10)*1000 + (i/10)%10*100 + ((i/10)%10)*10 + i%10)
							palindrome = 0;
						}
						else 
							if(i < 100000)
							{
								if(i == (i%10)*10000 + (i/10)%10*1000 + ((i/100)%10)*100 + ((i/10)%10)*10+ i%10)
								palindrome = 1;
							}
							else
								if(i < 1000000)
								{
							//		if(i == (i%10)*100000 + (i/10)%10*10000 + ((i/100)%10)*1000 + ((i/100)%10)*100 + (i/10)%10*10 + i%10)
									palindrome = 0;
								}
								else
									if(i < 10000000)
									{
										if(i == (i%10)*1000000 + (i/10)%10*100000 + ((i/100)%10)*10000 + ((i/1000)%10)*1000 + ((i/100)%10)*100 + ((i/10)%10)*10 + i%10)
										palindrome = 1;
									}
									else 
									//	if(i < 100000000 && i == (i%10)*10000000 + (i/10)%10*1000000 + ((i/100)%10)*100000 + ((i/1000)%10)*10000 + ((i/1000)%10)*1000 + ((i/100)%10)*100 + ((i/10)%10)*10 + i%10)
											palindrome = 0;
		
		if(palindrome && prime(i))
			printf("%d\n",i);
	}
	return 0;
}