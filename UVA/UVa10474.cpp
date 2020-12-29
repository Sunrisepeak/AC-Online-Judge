#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10000;

int main()
{
	int n, q, kase = 0, x;
	int a[maxn];
	while(scanf("%d%d", &n, &q) == 2 && n)
	{
		printf("CASE# %d:\n", ++kase);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		while(q--)
		{
			scanf("%d", &x);
			int p = lower_bound(a, a+n, x) - a;	//find x in a_array
			if(a[p] == x)
				printf("%d found at %d\n", x, p+1);
			else
				printf("%d not found\n", x);
		}
	}
	return 0;
}
