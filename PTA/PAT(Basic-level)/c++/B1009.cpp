//#define Test

#include <iostream>
#include <string> 
#include <vector>
using namespace std;

int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);		//name: problem id 
		freopen("../Tdata/name.out", "w", stdout);
	#endif
	
//	vector<string> words = nullptr; //ISSUE0: isnt obj. 15m
	vector<string> words;
	string word;
	while(cin >> word){
		words.push_back(word);
	}
	
	int index = words.size() - 1;
	while(index > 0){
		cout << words[index--] << " ";
	}
	cout << words[0];
	return 0;
}
