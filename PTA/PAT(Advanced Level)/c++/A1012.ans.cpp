#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Student{
	int id;
	int grade[4]; // save score
	int rank[4]; // A > C > M > E
}stu[2010];

const char course[] = {'A', 'C', 'M', 'E'};
int now;	//use to ctl 'grade-rank' in cmp
int exist[10000000] = {0};	// can't put main()
bool cmp(Student A, Student B){
	return A.grade[now] > B.grade[now];
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> stu[i].id >> stu[i].grade[1] >>
			   stu[i].grade[2] >> stu[i].grade[3];
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0);
	}
	
	for(now = 0; now < 4; now++){
		sort(stu, stu + n, cmp);
		stu[0].rank[now] = 1;
		for(int i = 1; i < n; i++){
	//		if(stu[i].grade[now] == stu[i].grade[now - 1]){	//ISSUE: 40m i - 1 rather than now - 1
			if(stu[i].grade[now] == stu[i - 1].grade[now]){
				stu[i].rank[now] = stu[i - 1].rank[now];
			}else{
				stu[i].rank[now] = i + 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		exist[stu[i].id]= i + 1;	// can't is zero
	}
	
	int qurey = 0;
	for(int i = 0; i < m; i++){
		cin >> qurey;
		if(exist[qurey]){
			int temp_id = exist[qurey] - 1;
			int best = 0;
			for(int j = 0; j < 4; j++){
				if(stu[temp_id].rank[j] < stu[temp_id].rank[best]){
					best = j;
				}
			}
//			cout << stu[temp_id].grade[0] << " " <<stu[temp_id].grade[1]<<" " <<stu[temp_id].grade[2] << " " <<stu[temp_id].grade[3] << endl;
//			cout << stu[temp_id].rank[0] << " " <<stu[temp_id].rank[1]<<" " <<stu[temp_id].rank[2] << " " <<stu[temp_id].rank[3] << endl;
			cout << stu[temp_id].rank[best] << " " << course[best] << endl;
		}else{
			cout << "N/A" << endl;
		}
	}
	
	return 0;
}
