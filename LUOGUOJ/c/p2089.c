#include<stdio.h>
int a[10], x, flag = 0;
int b[60001][10];
void dfs(int k)
{
	if(k == 10)
	{
		int sum = 0;
		for(int i = 0; i < 10; i++){
			sum += a[i];
		}
		if(sum == x)
		{
			for(int i = 0; i < 10; i++)
				b[flag][i] = a[i];
			flag++;
		}
	}
	else
		for(int i = 1; i <= 3; i++)
		{
			a[k] = i;
			dfs(k + 1);
		}
}
int main()
{
	scanf("%d", &x);
	if(x <= 30)
		dfs(0);
	printf("%d\n",flag);
	for(int i = 0; i < flag; i++)
	{
		printf("%d %d %d %d %d %d %d %d %d %d\n",b[i][0],b[i][1],b[i][2],b[i][3],b[i][4],b[i][5],b[i][6],b[i][7],b[i][8],b[i][9]);
	}
	return 0;
}