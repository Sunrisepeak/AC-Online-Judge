#include<stdio.h>
char a[401][26];
int main()
{
	int x, b[26] = {0};
	char s[4][101];

	for(int i = 0; i < 4; i++)
	{
		fgets(s[i],101,stdin);
		for(int j = 0; s[i][j] != '\0'; j++)
		{
			
			x = s[i][j] - 65;
			if(0 <= x && x < 26)
				a[b[x]++][x] = '*';			
		}
	}
	int max = 0;
	for(int i = 0; i < 26; i++)
		if(max <  b[i])
			max = b[i];
	for(int i = max-1; i >= 0; i--)
	{	
		int flag = 0;
		for(int j = 0; j < 26; j++)
			if(a[i][j] == '*')
				flag++;
		for(int j = 0; j < 26; j++)
		{
			if(flag == 1 && a[i][j] == '*')
			{
				printf("* \n");
				break;
			}
			if(a[i][j] == '*')
			{
				printf("* ");
				flag--;
			}
		    else
				printf("  ");
		}
		
	}
		printf("A B C D E F J H I J K L M N O P Q R S T U V W S Y Z ");
		return 0;
}