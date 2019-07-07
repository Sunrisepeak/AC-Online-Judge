#include<stdio.h>
int main()
{
	int n, i;
	scanf("%d", &n);
	int sum = 1;
	for(i = 1; sum < n; i = i + 1)
		sum += i;
	if(i % 2 != 0)
		printf("%d/%d\n", i - sum + n, sum - n + 1);
	else
		printf("%d/%d\n", sum - n ,i - sum + n);
	return 0;
}