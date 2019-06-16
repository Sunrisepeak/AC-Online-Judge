#include <iostream>
using namespace std;
int status[100001]{ 0 };
int main()
{
	int N{ 0 }, M{ 0 };
	int m, f;
	cin >> N; 
	while(N--)
	{
		cin >> m >> f;
		status[m] = f;
		status[f] = m;
	}
	cin >> M;
	int g;
	int single = M;
	int s[100001]{0};
//	cout << "this is debug" << endl;
	while(M--)
	{
		cin >> g;
		s[g] = 1;
		if(s[ status[g] ] == 1)
		{
			single -= 2;
			s[g] = s[ status[g] ] = 0;
		}
		else
			s[g] = 1;
	}
	cout << single << endl;
	int lock = 1;
	for(int i = 0; i < 100000; i++)
	{
		if(lock && s[i] == 1)
		{
			printf("%05d",i);
			lock = 0;
		}
		else if(s[i] == 1)
		{
			printf(" %05d",i);
		}
	}
	return 0;
}
