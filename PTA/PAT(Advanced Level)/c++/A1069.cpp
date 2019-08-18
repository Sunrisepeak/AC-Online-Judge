#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using LL = long long;
bool cmp(char a, char b){
	return a >= b;
}
int main(){
	string num;
	LL n1, n2, ans;
	cin >> num;
    num.insert(0, 4 - num.length(), '0');
	do{
		sort(num.begin(),num.end(), cmp);
		n1 = stoi(num);
		sort(num.begin(), num.end());
		n2 = stoi(num);
		ans = n1 - n2;
		num = to_string(ans);
		num.insert(0, 4 - num.length(), '0');
		printf("%04d - %04d = %04d\n",n1, n2, ans);
	}while(ans != 0 && ans != 6174);
	return 0;
} 
