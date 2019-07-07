#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	map<char, int> A{
		{'C', 0},
		{'B', 0},
		{'J', 0},
	},
	B{
		{'C', 0},
		{'B', 0},
		{'J', 0},
	};
	string s;
	int N;
	cin >> N;
	int equal = 0;
	int n = N;
	cin.get(); 
	while(n--)
	{
		getline(cin, s); 
		if(s[0] == s[2])
			equal++;
		else if(s == "C J" || s == "J B" || s == "B C") 
			A[s[0]]++;
		else 
			B[s[2]]++; 
	}
	int w1 = A['J'] + A['B'] + A['C'];
	int w2 = B['J'] + B['B'] + B['C'];
	char  c[]{'B', 'C', 'J'};
	/**
	*char  c[]{'C','B','J'};	// waste 1 hours, please note detail 
	*/
	char a_max{c[0]}, b_max = a_max; 
	printf("%d %d %d\n", w1, equal,N - w1 - equal);
	printf("%d %d %d\n", w2, equal,N - w2 - equal);
	for(int i = 0; i < 3; i++)
	{
		if(A[a_max] < A[c[i]])
			a_max = c[i];	
		if(B[b_max] < B[c[i]])
			b_max = c[i];
	}
	printf("%c %c", a_max, b_max);
	return 0;
}
