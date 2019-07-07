#include<iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int flag = 0, s = 0, x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		s = s + x;
		if(s > m)
		{
			flag++;
			s = x;
		}
	}
	cout << ++flag;
	return 0;
}