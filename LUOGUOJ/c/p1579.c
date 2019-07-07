#include<stdio.h>
#include<math.h>
int judge(int n)
{
	for(int i = 2; i <= sqrt(n); i++)
		if(n%i == 0)
			return 0;
	return 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n/3; i++)
	{
		if(judge(i))
		for(int j = i; j <= n/2; j++)
		{
			if(judge(j))
			for(int k = j; k < n; k++)			//第三个数可以免去循环（直接判断k = n - j - i 是否为质数）
			{
				if(j + k + i == n && judge(k))
				{
					printf("%d %d %d\n", i, j, k);
					return 0;
				}
			}
		}
	}
	return 0;
}