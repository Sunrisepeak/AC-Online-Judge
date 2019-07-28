#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<int> p, a, t;
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 'P'){
			p.push_back(i);
		}else if(str[i] == 'A'){
			a.push_back(i);
		}else{
			t.push_back(i);
		}
	}
	int sum = 0;
	for(int i = 0; i < p.size(); i++){
		for(int j = 0; j < a.size(); j++){
			if(a[j] > p[i]){
				for(int k = 0;k < t.size(); k++){
					if(t[k] > a[j]){
						sum = (sum + t.size() - k) % 1000000007;
						break;
					}
				}
			}
		}
	}
	cout << sum;
	return 0;
}
