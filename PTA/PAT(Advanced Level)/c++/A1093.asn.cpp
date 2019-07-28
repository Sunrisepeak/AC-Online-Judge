#include <iostream>
#include <string>
using LL = long long;
using namespace std;
/*
	ans_address:
		https://github.com/liuchuo/PAT/blob/master/AdvancedLevel_C%2B%2B/1093.%20Count%20PAT's%20(25).cpp
		
	"PPPATTAT"
		A(4)_count = P_count(3) * T_count(3) = 9
		A(7)_count = P_count(3) * T_count(1) = 3
		PAT_count = A(4)_count + A(7)_count = 12;
*/
int main(){
	string str;
	cin >> str;
	LL P_count, T_count;
	P_count = T_count = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 'T'){
			T_count++;
		}
	}
	LL ans = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 'P'){
			P_count++;
		}else if(str[i] == 'T'){
			T_count--;
		}else{
			ans = (ans + P_count * T_count) % 1000000007;
		}
	}
	cout << ans;
	return 0;
}
