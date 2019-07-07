#include<stdio.h>
int arr[21][21][21] = {0};
int w(int a, int b, int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
			return 1;
	if(20 < a || 20 < b || 20 < c)
	{
		if(!arr[20][20][20])
			arr[20][20][20] = w(20, 20 ,20);
		return arr[20][20][20];
	}
	if( a < b && b < c)
	{
		if(!arr[a][b][c])
			arr[a][b][c] = w(a, b, c -1) + w(a, b - 1, c -1) - w(a, b - 1, c);
	//	printf("this is debug ---- arr[%d][%d][%d] = %d\n", a, b, c, arr[a][b][c]);
		return arr[a][b][c];
	}
	if(!arr[a][b][c])
	{
		arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a-1, b- 1, c-1);
	//	printf("this is debug ---- arr[%d][%d][%d] = %d\n", a, b, c, arr[a][b][c]);
	}
	return arr[a][b][c];
}
int main()
{
	int a, b, c;
	for( ; ; )
	{
		scanf("%d%d%d", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1)
			return 0;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));	
	}
	return 0;
}