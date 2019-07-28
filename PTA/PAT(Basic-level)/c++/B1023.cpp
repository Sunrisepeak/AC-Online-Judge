#include <iostream>
using namespace std;
int main(){
	int save[10] = {0};
	for(int i = 0; i < 10; i++){
		cin >> save[i];
	}
	for(int i = 1; i < 10; i++){ //first_min
		if(save[i] != 0){
			cout << i;
			save[i]--;
			break;
		}
	}
	for(int i = 0; i < 10; i++){
		while(save[i]--){
			cout << i;
		}
	}
	return 0;
}
