#include <iostream>
using namespace std;

const int power[]{7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char M[]{"10X98765432"};

bool method1(){
	char card[20];
	fgets(card, 19, stdin);
	getchar();
	int sum = 0;
	for(int i = 0; i < 17; i++){
		if((card[i] > '9' || card[i] < '0') && i != 17){
			puts(card);
			return false;	
		}
		sum += (card[i] - '0') * power[i];
	}
	if(card[17] != M[sum % 11]){
		puts(card);
		return false;
	}
	return true;
}

bool method2(){
	char card[20];
	int sum = 0;
	bool flag = true;
	for(int i = 0; i < 17; i++){
		card[i] = getchar();
		if(card[i] > '9' || card[i] < '0'){
			flag = false;
		}
		sum += (card[i] - '0') * power[i];
	}
	card[17] = getchar();
	getchar();	//delete '\n'
	card[18] = '\0';	//set end of string
	if(card[17] != M[sum % 11] || !flag){
		puts(card);
		return false;
	}
	return true;
}

bool method3(){
	//string
}
int main(){
	int N;
	scanf("%d", &N);
	getchar();
	bool allTrue = true;
	while(N--){
		if(!method1()){
			allTrue = false;
		}
	}
	if(allTrue){
		printf("All passed");
	}
	return 0;
}
