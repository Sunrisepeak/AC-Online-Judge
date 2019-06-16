#include <iostream>
using namespace std;
void print(int ans)
{
	printf(ans ? "%d " : "N ", ans);
}
int main()
{
	int A1{0}, A2{0}, A3{A1}, A4{0}, A5{0};
	int x, A4_count{ 0 };
	int single = -1;
	cin >> x;	//delete first number
	bool isExsit = false;
	while(cin >> x)
	{
//		cout << x << endl;
		switch(x % 5)
		{
			case 0 :
				if(x % 2 == 0) 
					A1 += x;
				 break;
			case 1 : single = -single; A2 += single * x; isExsit = true; break;
			case 2 : A3++; break;
			case 3 : A4_count++; A4 += x; break;
			case 4 : 
				if(x > A5)
					A5 = x;
		}
	}
	
	/* //error because of "N"
	cout << (A1 ? A1 : "N") << " ";
	cout << (A2 ? A2 : "N") << " ";
	cout << (A3 ? A3 : "N") << " ";
	cout << (A4_count ? static_cast<double>(A4)/ A4_count : "N") << " ";
	cout << (A5 ? A5 : "N");
	*/
	/*
	cout << (A1 ? A1 : 'N') << " ";
	cout << (A2 ? A2 : 'N') << " ";
	cout << (A3 ? A3 : 'N') << " ";
	cout << (A4_count ? static_cast<double>(A4)/ A4_count : 'N') << " ";
	cout << (A5 ? A5 : 'N');
	*/
	
	print(A1);
	printf(isExsit ? "%d " : "N ", A2);
	print(A3);
	printf(A4_count ? "%.1lf ": "N ", ((double)A4)/(A4_count * 1.0));
	printf(A5 ? "%d" : "N", A5);
	return 0;
}

/*
 *because of the programe,I would not to use "cout" in oj.
 *please look at problem to use your heart.
 *
 *Presentation Error is deal with space key problem in the end of line 
 */
