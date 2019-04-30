#include<stdio.h>
#include<string.h>
int a[10];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		memset(a, 0, sizeof(a));
		int x;
		scanf("%d", &x);
		for(int k = 1; k <= x; k++)
		{
			int flag = k;
			while(flag)
			{
				a[flag%10]++;
				flag /= 10;
			}
		}
		printf("%d",a[0]);
		for(int j = 1; j < 10; j++)
			printf(" %d",a[j]);
		putchar('\n');
	}
	return 0;
}