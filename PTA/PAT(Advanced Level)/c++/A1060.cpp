#include <iostream>
#include <string>
using namespace std;

string format(string s, int n){
	int e = 0;
	if(s.find(".") != string::npos){
		int temp = s.find(".");
		e = temp - s.length() + 1;
		s.erase(s.begin() + temp);
		while(s.length() > 1 && s[0] == '0') s.erase(s.begin());
		if(s == "0") e = 0;
		else e += s.length();
	}else{
		while(s.length() > 1 && s[0] == '0') s.erase(s.begin());
		if(s == "0") e = 0;
		else e = s.length();
	}
	if(s.length() < n){
		s.append(n - s.length(), '0');
	}
	return "0." + s.substr(0, n) + "*10^" + to_string(e);
}
int main(){
	int N;
	string s1, s2;
	cin >> N >> s1 >> s2;
	s1 = format(s1, N);
	s2 = format(s2, N);
	if(s1 == s2){
		cout << "YES " << s1;
	}else{
		cout << "NO " << s1 << " " << s2;
	}
	return 0;
}
