#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	string num;
	cin >> num;
	int E{0};
	for(int i = 0; i < num.length(); i++){
		if(num[i] == 'E'){
			E = i;
			break;
		}
	}
	int exp = 0, power = 1, i;
	for(i = num.length() - 1; isdigit(num[i]); i--){
		exp += ((num[i] - '0') * power);
		power *= 10;
	}
	if(num[0] == '-') cout << "-";
	if(num[i] == '-'){
		if(exp == 0){
			cout << num.substr(1, E - 1);	
		}else{
			if(exp--){
				cout << "0.";
			}
			while(exp--){
				cout << "0";
			}
			cout << num[1] << num.substr(3, E - 3);
		} 
	}else{
		int pos = 3;
		cout << num[1];
		if(!exp) cout << "."; 
		while(exp--){
//			cout << num[pos] << "\n000000000\n";
			if(num[pos] != 'E'){
				cout << num[pos++];
			//	if(!exp && num[pos] != E) cout << ".";	//ISSUE : E to 'E'  30m
				if(!exp && num[pos] != 'E') cout << ".";
			}
			else
				cout << "0";
		}
		while(num[pos] != 'E'){
			cout << num[pos++];
		} 
	}
	return 0;
}
/*
+1.23400E-3

notes: 
	+1.23400E-00003
	+1.23400E-00
	
	//stoi() 

*/
