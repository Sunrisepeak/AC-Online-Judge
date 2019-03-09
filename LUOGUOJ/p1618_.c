#include<stdio.h>
int flag[3];
int a[10] = {0};
int a1, b, c, f = 0;
int judge(int sum1)
{
	int sum = 0;
	for(int i = 1; i < 10; i++){
		if(a[i] == 1)
			sum += a[i];
	}
	if(sum == sum1)
		return 1;
	return 0;
}
int tle(int ln,int i)
{
	if(ln == 1 && flag[0]*1.0/a1 < i*1.0/b)
			 return 1;
	if(ln == 2 && flag[1]*1.0/b < i*1.0/c)
			 return 1;
	return 0;
}
void dfs(int n, int ln)
{
	for(int i = n+1; i <= 987; i++)
	{
		if(i%10 != i/10%10 && i%10 != i/100%10 && i/10%10 != i/100%10)
		{
			if(tle(ln, i))
				break;
			flag[ln] = i;
			a[i%10]++;
			a[i/10%10]++;
			a[i/100%10]++;
			if(ln == 2 && flag[0]*1.0/a1 == flag[1]*1./b && flag[2]*1./c == flag[1]*1./b && judge(9)){
					printf("%d %d %d\n",flag[0],flag[1],flag[2]);
					f = 1;
			}
			else
				if(judge((ln+1)*3))
					dsf(i+1,ln+1);
			a[i%10]--;
			a[i/10%10]--;
			a[i/100%10]--;
		}
	}
}
int main()
{
	scanf("%d%d%d",&a1, &b, &c);
	dfs(122,0);
	if(!f)
	 printf("No!!!\n");
	return 0;
	
}