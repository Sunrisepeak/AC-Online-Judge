#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
using namespace std;

int main(){
	string week[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};	
	map<char, int> map{
		{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, 
		{'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, 
		{'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17},
		{'I', 18}, {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}
	};
	string s1, s2, s3, s4;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	getline(cin, s4);
	if(s1.length() > s2.length()){
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	vector<char> v;
	int i = 0;
	for(; i < s1.length(); i++){
		if('A' <= s1[i] && s1[i] <= 'G' && s1[i] == s2[i]){
			v.push_back(s1[i]);
            break;
		}
	}
	for(i++; i < s1.length(); i++){
		if((isdigit(s1[i]) || ('A' <= s1[i] && s1[i] <= 'N')) && s1[i] == s2[i]){
			v.push_back(s1[i]);
            break;
		}
	}
	cout << week[v[0] - 'A'];
    for(i = 0; i < s3.length(); i++){
		if(isalpha(s3[i] && s3[i] == s4[i])){	//ISSUE : think of 's' == s3[i], used to English
			printf(" %02d:%02d", map[v[1]], i);
			break;
		}
	}
	return 0;
}
