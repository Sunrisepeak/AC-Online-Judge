#include <iostream>
#include <string>
#include <vector>
using namespace std;
string number[] = {"ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu",};
string power[] = {"", "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi",};	//ISSUE: 30m
vector<string> ans; //ISSUE: 20m
void chinese(string n){
	for(int i = 0; i < n.length(); i++){
		bool end = false;
		if(n[i] == '0'){
			int j;
			for(j = i ; j < n.length(); j++){
				if(n[j] != '0'){		//ISSUE0: 10m
					ans.push_back(number[0]);
					i = j -1;
					break;
				}
				if(n.length() - j == 5 || n.length() - j == 9){		//ISSUE1: 20m
					ans.push_back(power[n.length() - j]);
				}
			}
			if(j == n.length())
				end = true;
		}else{
			ans.push_back(number[n[i] - '0']);
			if(power[n.length() - i] != "")		//ISSUE: 20m
				ans.push_back(power[n.length() - i]);
		}
		if(end){
			break;
		}
	}
}
int main(){
	string num;
	cin >> num;
	if(num[0] == '-'){
		ans.push_back("Fu");
		num = num.substr(1);
	}
	if(num == "0"){		//ISSUE: 20m
		cout << "ling";
		return 0;
	}
	chinese(num);
	cout << ans[0];
	for(int i = 1; i < ans.size(); i++){
		cout << " " << ans[i];
		if(ans[i] == "Yi" && i + 1 < ans.size() && ans[i + 1] == "Wan")
			i++;
	}
	return 0;
} 
