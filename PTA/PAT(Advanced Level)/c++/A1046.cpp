#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int N, M;
	int x, path_length = 0;
	cin >> N; 
	while(N--)
	{
//		cout << "this is debug\n" << endl;
		cin >> x;
		path_length += x;
		v.push_back(x);
	}
	
	cin >> M;
	int c1{0}, c2{0};
	while(M--)
	{
//		cout << "this is debug--M\n";
		cin >> c1 >> c2;
		int p_length = 0;
		if(c1 > c2)
		{
			c1 = c1 + c2;
			c2 = c1 - c2;
			c1 = c1 - c2;
		}
		//	Part of time limit exceded 
		for(decltype(v.size()) i = c1 - 1; i < c2 - 1; i++)
		{
			p_length += v[i];
		} 
			
		//comparator size about "p_length"(forward) and "path_p_length"(reverse)
		cout << (p_length * 2 > path_length ? path_length - p_length : p_length);
		printf(M != 0 ? "\n":"");			
	}
	return 0;
}
/*
Mainly reason
	1.to use 'for' calculator the shortest distance for every query
	
*/


