#include<stdio.h>
#include<string.h>
//int map[1001][1001];
int row[1001] = {0}, line[1001] = {0};
void print(int a[])
{
	for(int i = 0; i < 1001; i++)
		if(a[i] == -1)
			printf("%d ",i);
	printf("\n");
}
int main()
{
	int m, n, k, l, d;
//	memset(map, 0, sizeof(map));
	scanf("%d%d%d%d%d",&m, &n, &k, &l, &d);
//	int cout = 1;
	int x1,x2,y1,y2;
	for(int i = 0; i < d; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 == x2 +1)
			row[x2]++;
		if(y1 == y2 +1)
			line[y2]++;
		if(x1 == x2 -1)
			row[x1]++;
		if(y1 == y2 -1)
			line[y1]++;	
	}		
	int max, flag;
	for(int i = 0; i < k; i++)
	{
		max = 0;
		for(int j = 0; j < 1001; j++)
			if(max < row[j])
			{
				max = row[j];
				flag = j;
			}
		row[flag] = -1;
	//		printf("this is debug-----row：%d\n", flag);
	}
	for(int i = 0; i < l; i++)
	{
		max = 0;
		for(int j = 0; j < 1001; j++)
			if(max < line[j])
			{
				max = line[j];
				flag = j;
			}
		line[flag] = -1;
	//			printf("this is debug-----line：%d\n", flag);
	}
	print(row);
	print(line);
	return 0;
}