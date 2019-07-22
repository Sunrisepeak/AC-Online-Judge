#include <iostream>
using namespace std;

int main(){
	int a[10] = {0};
	char c;
	while((c = getchar()) != EOF){
		a[c - '0']++;
	}
	for(int i = 0; i < 10; i++){
		if(a[i] != 0){
			cout << i << ":" << a[i] << endl;
		}
	}
	return 0;
}
