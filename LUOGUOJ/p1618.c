#include<stdio.h>
int flag[3];
int d[10] = {0};
int a1, b, c;
int judge(int sum1, int a[])
{
	int sum = 0;
	for(int i = 1; i < 10; i++){
		if(a[i] == 1)
			sum += a[i];
	}
	if(sum == sum1 )
		return 1;
	return 0;
}
void dsf(int n,int a[], int ln)
{
	for(int i = n+1; i <= 987; i++)
	{
		if(i%10 != i/10%10 && i%10 != i/100%10 && i/10%10 != i/100%10)
		{
			
			flag[ln] = i;
			a[i%10]++;
			a[i/10%10]++;
			a[i/100%10]++;
			if(ln == 2){
				if(judge(9, a) && flag[0]/a1 == flag[1]/b && flag[2]/c == flag[1]/b)
				{
					printf("%d %d %d\n",flag[0],flag[1],flag[2]);
					a[i%10]--;
					a[i/10%10]--;
					a[i/100%10]--;
					return;
				}
			}
			if(judge((ln+1)*3,a))
				dsf(i+1,a,ln+1);
			a[i%10]--;
			a[i/10%10]--;
			a[i/100%10]--;
			
		}
	}
}
int main()
{
	scanf("%d%d%d",&a1, &b, &c);
	dsf(122,d,0);
	return 0;
	
}