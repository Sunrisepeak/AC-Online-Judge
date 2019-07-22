#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	vector<string> s;
	int N;
	cin >> N;
	string str;
	getline(cin, str);	//ISSUE: 20m cannot use getchar() to delete '\n'
	while(N--){
		getline(cin, str);
//		cout <<str << "   ----tis \n";
		s.push_back(str);
	}
	int count = 0;
	bool go_on = true;
	while(go_on && count < s[0].length()){
		char temp = s[0][s[0].length() - count - 1];
//		cout << temp <<"^^" <<s[0] << "^^" <<s[0].length() <<"---this is test\n";
		for(auto value : s){
			if(value[value.length() - count - 1] != temp){
				go_on = false;
				break;
			}
		}
		if(go_on)
			count++;
	}
	if(!count){
		cout << "nai";
	}else{
		cout << s[0].substr(s[0].length() - count);
	}
	return 0;
}
