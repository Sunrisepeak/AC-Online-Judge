#include<iostream>
using namespace std;
int main()
{
  int a, b, c[10],top;
  while(cin >> a >> b)
  {
	top = -1;			//初始化top
	a = a + b;
	if(a < 0)			//取a+b和的绝对值
	{
		cout << "-";
		a = -a;
	}
	if(a == 0)			//和为0的情况
		cout << "0";
	while(a)			//对和进行求余逐个入栈
	{
		c[++top] = a % 10;
		a = a/10;
	}
	int length = top + 1;
	int k = length%3;	//用于记录第一逗号的标记（例如是五位数会在第二位输出，4位数是第一个输出）
	while(top >= 0)		//循环出栈
	{
		cout << c[top--];	
		if(length > 3 && top >= 2)		//判断和小于等于三位数不用输出逗号，和确保最后一个逗号输出是在倒数第三个数输出时输出
			if(length - top - 1== k || ((length - top - k - 1)%3 == 0))	//左边是判断第一个逗号输出，右边是判断剩余逗号输出(就是对3求余)
				cout << ",";
	}
	cout << "\n";
  }
  return 0;
}