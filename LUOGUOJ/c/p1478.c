#include<stdio.h>
int y[101]={0};
int main()
{
	int n, s, a, b;
	scanf("%d%d%d%d",&n,&s,&a,&b);
	int xi,yi;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d",&xi,&yi);
		if(xi <= a + b && yi <= s)
			y[yi]++;
	}
	int sum = 0, flag = 0;
	for(int i = 0; i < 101; i++)
			if(y[i] != 0 && sum + i <= s)
			{
		//		printf("%d-\n",i);
				sum += i*y[i];
				flag += y[i];
				if(sum > s)
				{
					if((sum - s)%i != 0)
					flag -=  (sum - s)/i + 1;
					else
						flag -=  (sum - s)/i;
				}

			}
	printf("%d\n",flag);
	return 0;
}