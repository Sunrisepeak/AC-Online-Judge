#define LOCAL
#include<stdio.h>
#include<string.h>
int stack[101], top = -1;
int memory[1005] = {0};
int main()
{
	#ifdef LOCAL
		freopen("cin.in","r", stdin);
		freopen("out.out", "w", stdout);
	#endif
	int m, n, x, flag = 0;
	for(int i = 0; i < 101; i++)
		stack[i] = 1002;
//	memset(stack, -1, sizeof(stack));
	scanf("%d%d",&m, &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&x);
		if(!memory[x])
		{
			
			flag++;
			top = (++top)%m;
			memory[stack[top]] = 0;
			stack[top] = x;
			memory[x] = 1;
		}
	}
	printf("%d\n", flag);
	return 0;
}