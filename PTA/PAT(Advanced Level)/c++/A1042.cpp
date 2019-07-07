#include <iostream>
#include <string>
using namespace std;
string poker1[55];
string poker2[55];
int cmd[55]{ 0 };
int main()
{
	//general
	string tag[] = {"S", "H", "C", "D"};
	for(int i = 0; i < 4; i++)
		for(int j = 1; j < 14; j++)
			poker1[i * 13 + j] = tag[i] + to_string(j);
	poker1[53] = "J1";
	poker1[54] = "J2";
	int N;
	cin >> N;
	for(int i = 1; i < 55; i++)
		cin >> cmd[i];
	for(int i = 1; i <= N; i++)
	{
		if(i % 2 != 0)
		{
			for(int j = 1; j < 55; j++)
				poker2[cmd[j]] = poker1[j];
		}
		else
		{
			for(int j = 1; j < 55; j++)
				poker1[cmd[j]] = poker2[j];
		}
	}
	auto temp = poker1;
	if(N % 2 != 0)
		temp = poker2;
//	cout << "this is debug" << endl;
	for(int i = 1; i < 55; i++)
		cout << (i != 54 ? temp[i] + " " : temp[i]);
	return 0;
}
