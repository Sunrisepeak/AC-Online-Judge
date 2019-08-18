#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Person{
	string name;
	int age, worth;
}per[100010],valid[100010];
int Age[210] = {0};

bool cmp(Person A, Person B){
	if(A.worth != B.worth) 
		return A.worth > B.worth;
	else if(A.age != B.worth) 
	//	return A.age < B.worth; //ISSUE: 2h
		return A.age < B.age;
	return A.name < B.name;
}

int main(){
	int N, K;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> per[i].name >> per[i].age >> per[i].worth;
	}
	sort(per, per + N, cmp);
	int validNum = 0;
	for(int i = 0; i < N; i++){
		if(Age[per[i].age] < 100){
			Age[per[i].age]++;
			valid[validNum++] = per[i];
		}
	}
/*	for(int i = 0; i < validNum; i++){
		cout << valid[i].age << endl;
	}*/ 
	int M, min, max;
	for(int i = 1; i <= K; i++){
		cin >> M >> min >> max;
		printf("Case #%d:\n", i);
		int printNum = 0;
		for(int j = 0; j < validNum && printNum < M; j++){
			if(valid[j].age >= min && valid[j].age <= max){
				printf("%s %d %d\n", per[j].name.c_str(), per[j].age, per[j].worth);
				printNum++;
			}
		}
		if(!printNum){
			printf("None\n");
		}
	}
	return 0;
}
