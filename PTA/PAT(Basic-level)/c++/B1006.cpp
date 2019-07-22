#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N / 100; i++){
		cout << "B";
	}
	for(int i = 0; i < N / 10 % 10; i++){
		cout << "S";
	}
	for(int i = 1; i <= N % 10; i++){
		cout << i;
	}
	return 0;
}
