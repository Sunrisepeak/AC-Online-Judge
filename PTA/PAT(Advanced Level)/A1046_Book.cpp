#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//const int MAXN = 100005;

int main()
{
	vector<int > dis;
	int N, M;
	int sum_path = 0;
	int x;
	dis.push_back(0);
	cin >> N;
	while(N--)
	{
		cin >> x;
		sum_path += x;
		dis.push_back(sum_path);
	}
	cin >> M;
	int left, right;
	while(M--)
	{
		cin >> left >> right;
		if(left > right)
			swap(left, right);	//	func: swap() include file of algorithm 
		int dis_temp = dis[right -1] - dis[left -1];
	//	printf(M ? "%d\n" : "%d",(sum_path - dis_temp > dis_temp) ? dis_temp : sum_path - dis_temp);
		cout << min(sum_path - dis_temp, dis_temp); //func: min()   ---algorithm
		printf(M ? "\n" : "");
	}
	return 0;
	
	/*
		Notes:
			1.algorithm
				1) swap(x, y)
				2) min(x, y)
			2.O A B --->  AB = OA - OB; reduce calculator time
	*/
	
}
