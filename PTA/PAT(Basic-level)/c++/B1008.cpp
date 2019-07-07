#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int > v;
	int N, M, x;
	cin >> N >> M;
	while(N--)
	{
		cin >> x;
		v.push_back(x);
	}
	M = M % v.size();
	cout << v[(v.size() - M) % (v.size())];
	for(decltype(v.size()) i = 1; i < v.size(); i++)
	{
		cout << " " << v[(v.size() - M + i) % (v.size())];
	}
	return 0;
}
