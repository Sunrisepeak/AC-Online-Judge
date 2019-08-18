#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Student{
	int id;
	string name;
	int score;
}stu[100002];

int C = 0;
bool cmp(Student a, Student b){
	switch(C){
		case 1: return a.id < b.id;
		case 2: 
			if(a.name != b.name)
				return a.name <= b.name;
			else
				return a.id < b.id;
		case 3:
			if(a.score != b.score)
				return a.score <= b.score;
			else
				return a.id < b.id;	
	}
}
int main(){
	int N;
	cin >> N >> C;
	for(int i = 0; i < N; i++){
		cin >> stu[i].id >> stu[i].name >> stu[i].score;
	/*	not good
		stu[i].name.resize(50);
		scanf("%d %s %d", &stu[i].id, &stu[i].name[0], &stu[i].score);
	*/
	}
	sort(stu, stu + N, cmp);
	for(int i = 0; i < N; i++){
		printf("%06d %s %d\n", stu[i].id, stu[i].name.c_str(), stu[i].score);	//string.c_str()	170ms
	/*	printf("%06d", stu[i].id);		//300ms
		cout << " " << stu[i].name << " " << stu[i].score << endl;
	*/
	}
	return 0;
}
