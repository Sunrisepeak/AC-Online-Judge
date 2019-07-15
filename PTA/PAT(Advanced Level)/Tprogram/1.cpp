#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmpSize(string a, string b)
{
	if(a.length() > b.length())
		return true;
	else if(a.length() < b.length())
		return false;
	else
		for(int i = 0; i < a.length(); i++)
		{
			if(a[i] > b[i])
				return true;
			if(a[i] < b[i])
				return false;	
		}
	//a = b return false;
	return false;
}

string add(string a, string b)
{
	if(a.length() > b.length())
	{
		swap(a, b);
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
	string temp;
	string sign = "";
	if(cmpSize(a, b))
	{
		sign = "-";
		swap(a, b);
	}
//	cout << a <<"  " <<b << "\n";
	for(int i = 0; i < a.length(); i++)
	{
		if(a[a.length() - i - 1] > b[b.length() - i - 1])
		{
			int index = b.length() - i - 2;
			//subtract with borrow
			while(index >= 0 && b[index] == '0') index--;
			b[index++] -= 1;
			for(; index < b.length() - i - 1; index++)
			{
				b[index] += 9;
			}
			b[index] = 10 + b[index] - a[a.length() - i - 1] + '0';
		}
		else
		{
			b[b.length() - i - 1] = b[b.length() - i - 1] - a[a.length() - i - 1] + '0';
		}
	//	cout << b[b.length() - i - 1] << "this is \n";
	}
	int begin = 0;
	//delete 0 ,'000001' to '1' or "00000" to "0"
	while(begin < b.length() - 1 && b[begin] == '0') begin++;
	return sign + b.substr(begin, b.length() - begin);
}

int main()
{
	string a, b, c;
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		string sum = "";
		cin >> a >> b >> c;
		if(a[0] == '-' && b[0] == '-')
			sum = "-" + add(a.substr(1, a.length() - 1), a.substr(1, b.length() - 1));
		else if(a[0] == '-')
			sum = sub(a.substr(1, a.length() - 1), b);
		else if(b[0] == '-')
			sum = sub(b.substr(1, b.length() - 1), a);
		else
			sum = add(a, b);
			
		int flag = false;
		if(sum[0] == '-' && c[0] == '-')
			//sad, An hour was wasted becouse of under code
			flag = !cmpSize(sum.substr(1, sum.length() - 1), c.substr(1, c.length() - 1));
		else if(sum[0] == '-')
			flag = false;
		else if(c[0] == '-')
			flag = true;
		else
			flag = cmpSize(sum, c);
//		cout << sum << "--sum\n";
		printf("Case #%d: ", i);
		cout << (flag ? "true" : "false");
		printf(i != N ? "\n":"");	
	}
	return 0;
}
