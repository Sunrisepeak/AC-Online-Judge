#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a[100];
int b[100001];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		cin >> a[i];
	}
	int d, q, flag = 0;
	for(int i = 0; i < m; i++)
	{
		cin >> d >> q;
		if(b[flag] == d)
			flag = (flag - q) % n;
		else
			flag = (flag + q) % n;
		if(flag < 0)
			flag += n;
	//	cout << a[flag] << endl;
	}
	cout << a[flag] << endl;
	return 0;
}