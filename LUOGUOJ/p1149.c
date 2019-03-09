#include<stdio.h>
int a[] = {6,2,5,5,4,5,6,3,7,6};
int f(int number)
{
	int sum = 0;
	if(number == 0)
		return 6;
	while(number != 0)
	{
		sum += a[number%10];
		number = number/10;
	}
	return sum;
}
int main()
{
	int n, flag = 0;
	scanf("%d",&n);
//	for(int n = 0; n <= 24; n++){		//int flag = 0;
	for(int i = 0; i < 1111; i++)
		for(int j = i; j < 1111; j++)
			if(f(i) + f(j) + f(i+j) + 4 == n)
			{
			//	printf("%d+%d=%d\n",i,j,i+j);
				flag++;
				if(i != j)
					flag++;
			}
	printf("%d\n",flag);
//	}
	return 0;
}