#include <iostream>
int data[100000]{0};
int main()
{
	int N, a, b;
	int max = 1;
	scanf("%d", &N);
	while(N--)
	{
		scanf(N ? "%d %d\n" : "%d %d", &a, &b);
//		getchar();
		data[a] += b;
		if(data[a] > data[max])
			max = a;
	}
	printf("%d %d", max, data[max]);
	return 0;
}
