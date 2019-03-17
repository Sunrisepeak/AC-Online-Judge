#include<stdio.h>
int main()
{
	for(;;)
	{
		int n;
		scanf("%d",&n);
		if(n%4 == 0)
			int flag = n/4;
		else
		    flag =  n/4 + 1;
		int blank = n%4;
		printf("Printing order for %d pages:\n",n);
		for(int i = 0; i < flag; i++)
		{
			for(int j = 1; j <= 2; j++)
			{
				if(j == 1)
				{
					if(blank)
						printf("Sheet %d, front: Blank, %d\n",i+1,i*2+j);
					else
						printf("Sheet %d, front: %d, %d\n",i+1,4*flag-2*i,i*2+j);
				}
				else
				{
					if(blank)
						printf("Sheet %d, front: %d, %d\n",i+1,4*flag-2*i-1,i*2+j);
					else
						printf("Sheet %d, front: Blank, %d\n",i+1,i*2+j);
				}
			}
		}
		return 0;
	}
}