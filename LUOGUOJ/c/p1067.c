#include<stdio.h>
int a[101];
void f(int n, int i)
{
	if(n != 1 || i == 0)
		printf("%d",n);
	if(i > 1)
		printf("x^%d",i);
	else
		if(i == 1)
			printf("x");
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = n; i >= 0; i--)
		scanf("%d", &a[i]);
	int flag = 0;
	for(int i = n; i >= 0; i--)
	{
		if(a[i] > 0)
		{
			if(flag)
				printf("+");
			flag = 1;
			f(a[i], i);
		}
		else if(a[i] != 0)
		{
			printf("-");
			flag = 1;
			f(-1*a[i], i);
		}
	}
	return 0;
}
