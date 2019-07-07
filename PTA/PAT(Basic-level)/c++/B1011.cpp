#include <iostream>
using namespace std;
int main()
{
	long long a, b, c;
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> a >> b >> c;
		printf("Case #%d: ", i);
		if(a + b > c)
			cout << (i != N ? "true\n" : "true");
		else
			cout << (i != N ? "false\n" : "false");
	}
	return 0;
}
