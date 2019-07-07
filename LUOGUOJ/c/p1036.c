#include<stdio.h>
#include<math.h>
int  a[21],b[21];
int n, k, flag = 0;
void f(int k1, int i)
{
	if(k1 == 0)
	{
		int j, sum = 0;
		for(j = 0; j < k; j++){
			sum += b[j];
//			printf("forsum__this is debug->sum:%d b:%d\n",sum,b[j]);
		}
		for(j = 2; j < sqrt(sum); j++){
//			printf("for__this is debug->sum:%d j:%d\n",sum,j);
			if(sum % j == 0)
			{
//				printf("this is debug->sum:%d j:%d\n",sum,j);
				break;
			}
		}
//		printf("if(k1)__this is debug->sum:%d j:%d\n",sum,j);
		if(j >= sqrt(sum))
			flag++;
	}
	else
		for(; i < n; i++)
		{
			b[k-k1] = a[i];
			f(k1-1, i+1);
		}
}
int main()
{	
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	f(k,0);
	printf("%d\n",flag);
	return 0;
}