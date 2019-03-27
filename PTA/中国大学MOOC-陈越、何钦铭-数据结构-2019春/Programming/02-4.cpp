#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> v(n+1);
	for(int i = 0; i < k; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> v[j];
		}
		int flag = 1, t, r;
		stack<int> s;
		for(r = 1; r <= n; r++)
		{
			s.push(r);
//			cout << "this is debug " << s.size() << endl;
			if(s.size() > m)
				break;
			while(!s.empty() && v[flag] == s.top())
			{
				 s.pop();
				 flag++;
			}
		}
		if(r != flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}