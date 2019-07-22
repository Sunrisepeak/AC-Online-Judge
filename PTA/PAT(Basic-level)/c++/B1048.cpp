//#define Test

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	#ifdef Test
		freopen("../Tdata/B1048.td.in", "r", stdin);    //name: problem id
		freopen("../Tdata/B1048.out", "w", stdout);
	#endif
	string A, B;
	while(cin >> A >> B){
		stack<char> ans;
		int index = 1, t;
		char map[] = {'J', 'Q', 'K'};
		if(A.length() > B.length()){	//ISSUE: 2h
			B = ((string)"").append(A.length() - B.length(), '0') + B;
		}else{
			A = ((string)"").append(B.length() - A.length(), '0') + A;
		}
		while(index <= A.length() && index <= B.length()){
			if(index % 2 == 1){
				t = (stoi(A.substr(A.length() - index, 1)) + stoi(B.substr(B.length() - index, 1))) % 13;
				if(t < 10) 
					ans.push(t + '0');
				else
					ans.push(map[t - 10]);		//ISSUE: 10m, not succession 'J' 'Q' 'K'
			}else{
				t = (stoi(B.substr(B.length() - index, 1)) - stoi(A.substr(A.length() - index, 1)) + 10) % 10;
				ans.push(t + '0');
			}
			index++;
		}
		while(!ans.empty()){
			cout << ans.top();
			ans.pop();
		}
		putchar('\n');
	}
	return 0;
}
