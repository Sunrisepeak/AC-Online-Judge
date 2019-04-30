#include<stdio.h>
#define max 81
int main()
{
	char s[max];
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		int score = 0, flag = 0;
		for(int i = 0; s[i] != '\0'; i++)
		{
			if(s[i] == 'O')
				score += ++flag;
			else
				flag = 0;		
		}
		printf("%d\n", score);
	}
	return 0;
}