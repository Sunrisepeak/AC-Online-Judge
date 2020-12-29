#include<stdio.h>
double elementMass(char e)
{
	if(e == 'C')
		return 12.01;
	if(e == 'H')
		return 1.008;
	if(e == 'O')
		return 16.00;
	if(e == 'N')
		return 14.01;
	return 0;
}
int main()
{
	int n;
	double ans;
	scanf("%d", &n);
	while(n--)
	{
		char s[81];
		scanf("%s", s);
		int flag = 0;
		int sign = 0;
		ans = 0;
		if(s[1] != '\0')
		for(int i = 0; s[i] != '\0'; i++)
		{
			if('0' <= s[i] && s[i] <= '9')
			{
				sign++;
				if(sign && (s[i+1] == '\0' || s[i+1] >= 'C'))
				{
					for(int j = flag + 1; j <= flag + sign; j++)
					{
						int t = 1;
						int k = flag + sign - j;
						while(k--)
							t *= 10;
				//		printf("k:%d--------t:%d", k, t);
						ans += ((s[j] - '0') * t * elementMass(s[flag]));
					}
					sign = 0;
					flag = i + 1;
			//		printf("element:%c\n",s[flag]);
				}
			}
			else
			{
				if(s[i+1] == '\0' || s[i+1] >= 'C')
				{
					ans += elementMass(s[i]);
					flag = i + 1;
				}
			//	printf("elementMass:%f\n",elementMass(s[i]));
			}
		}
		else 
			ans += elementMass(s[flag]);
		printf("%.3f\n", ans);
	}
	return 0;
}