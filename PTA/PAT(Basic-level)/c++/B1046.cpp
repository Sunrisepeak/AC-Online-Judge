#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int a1, a2, b1, b2;
	int a_ans{ 0 }, b_ans{ 0 };
	while(N--)
	{
		cin >> a1 >> a2 >> b1 >> b2;
		int sum = a1 + b1;
		if(a2 != sum && b2 == sum)
			a_ans++;
		if(a2 == sum && b2 != sum)
			b_ans++;
	}
	printf("%d %lld", a_ans, b_ans);
	return 0;
}
