#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;

int main(){
	const string map[]{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string N;
	cin >> N;
	int sum = 0;
	for(auto c : N){
		sum += c - '0';
	}
	string num_str = to_string(sum);
//	cout << num_str << endl;		//ISSUE: 5m  debug haven't delete
	cout << map[num_str[0] - '0'];
	for(int i = 1; i < num_str.length(); i++){
		cout << " " << map[num_str[i] - '0'];
	}
	return 0;
}
