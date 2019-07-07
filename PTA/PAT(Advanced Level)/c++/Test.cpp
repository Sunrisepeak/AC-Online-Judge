#include <iostream>
#include <string>
using namespace std;

string add(string a, string b)
{
	string temp;
	if(a.length() > b.length())
	{
		temp = a;
		a = b;
		b = temp;
	}
	int carry = 0;
	for(int i = 0; i < a.length(); i++)
	{
		int sum = carry + a[a.length() - 1 - i] + b[b.length() - 1 - i] - 2 * '0';
//		cout << sum << "this is sum1\n" << b[b.length() - 1 - i] << "\n";
		b[b.length() - 1 - i] = sum % 10 + '0';
		carry = sum / 10;
	}
	for(int i = a.length(); carry && i < b.length(); i++)
	{
		int sum = carry + b[b.length() - i - 1] - '0';
		b[b.length() - i - 1] = sum % 10 + '0';
		carry = sum / 10;
//		cout << sum << "this is sum\n";
	}
	if(carry)
		b = "1" + b;
	return b;
}

string sub(string a, string b)
{
	return NULL;
}
bool judge(string sum, string c)
{
	return 1;
}
int main()
{
	string a, b, c;
	int N;
	cout << add("99991", "9");
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		string sum = "";
		cin >> a >> b >> c;
		if(a[0] == '-' && b[0] == '-')
		{
			sum = "-" + add(a.substr(1, a.length() - 1), a.substr(1, b.length() - 1));

		}
		else if(a[0] == '-' || b[0] == '-')
		{
			sum = sub(b, a);
		}
		else
			sum = add(a, b);

		printf("Case #%d: ", i);
		cout << (judge(sum, c) ? "true" : "false");
		printf(i != N ? "\n":"");	
	}
	
	return 0;
}
