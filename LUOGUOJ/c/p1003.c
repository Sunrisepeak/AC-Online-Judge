#include<stdio.h>
int a[10001], b[10001], j[10001], k[10001];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d%d%d", &a[i], &b[i], &j[i], &k[i]);
	int r, l;
	scanf("%d%d", &r, &l);
	for(; n > 0; n--)
		if(a[n-1] <= r && r <= a[n-1] + j[n-1] && b[n-1] <= l && l <= b[n-1] + k[n-1])
			break;
	if(n == 0)
		printf("-1\n");
	else
		printf("%d\n", n);
	return 0;
}