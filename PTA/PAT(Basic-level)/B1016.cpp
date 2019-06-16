#include <iostream>
#include <string>
using namespace std;
int new_num(string n_str, char value)
{
	int ans{0}, flag = 1;
	for(auto v : n_str)
	{
		if(v == value)
		{
			ans += flag * (value - '0');
			flag *= 10;
		}	
	}
	return ans;
}
int main()
{
	string a, b;
	char num1, num2;
	cin >> a >> num1 >> b >> num2;
	int ans{0};
	ans = new_num(a, num1) + new_num(b, num2);
	cout << ans;
	return 0;
}
