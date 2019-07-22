#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	map<char, char> rep{
		{'1', '@'},
		{'0', '%'},
		{'l', 'L'},
		{'O', 'o'}
	};
	int N, modify_count = 0;
	string info[1001][3];
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> info[i][1] >> info[i][2];
		bool isM = false;
		for(auto& c : info[i][2]){
			switch(c){
				case 'O' :
				case '1' :
				case '0' :
				case 'l' : c = rep[c]; info[i][0] = "m"; isM = true; break;
			}
		}
		if(isM) 
			modify_count++;
	}
	if(modify_count == 0){
		if(N == 1)	//ISSUE: 1h, are and counts of Output Specification
			printf("There is %d account and no account is modified", N);
		else
			printf("There are %d accounts and no account is modified", N);
	}else{
		cout << modify_count << endl;
		for(int i = 0; i < N; i++){
			if(info[i][0] == "m"){
				cout << info[i][1] << " " << info[i][2] << endl;
			}
		}
	}
	return 0;
}
