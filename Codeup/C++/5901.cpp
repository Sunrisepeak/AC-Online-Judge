//#define Test

#include <iostream>
#include <string> 
using namespace std;

int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);		//name: problem id 
		freopen("../Tdata/name.out", "w", stdout);
	#endif
	
	string s;
	cin >> s;
	int len = s.length();
	bool flag = true;
	for(int i = 0; i <= len - i - 1; i++){
		if(s[i] != s[len - i - 1])
			flag = false;
	}	
	if(flag){
		cout << "YES";
	}else
		cout << "NO";
	return 0;
}
