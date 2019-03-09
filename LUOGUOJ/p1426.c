#include<stdio.h>
int main()
{
	double s, x, move = 0;
	scanf("%lf%lf", &s, &x);
	for(double i = 7; ; i *= 0.98)
	{
		if(move >= s - x )
		{
			if( move + i > s + x)
				printf("n\n");
			else
				printf("y\n");
			break;
		}
		move += i;
	}
	return 0;
}