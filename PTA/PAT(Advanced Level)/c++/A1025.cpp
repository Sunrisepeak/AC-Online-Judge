#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef struct{
	string r_n;
	int l_n, l_r, score;
}User;
bool cmp(User a, User b){
	if(a.score != b.score) 
		return a.score > b.score;
	else //if(a.l_n != b.l_n)	ISSUE: 2h  accuse of segmentation fault, 
		return a.r_n < b.r_n;	//a.l_n == b.l_n not return 
}
int main(){
	vector<User> user;
	int N, K, count = 0;
	cin >> N;
	for(int j = 1; j <= N; j++){
		cin >> K;
		User u;
		for(int i = 1; i <= K; i++){
			cin >> u.r_n >> u.score;
			u.l_n = j;
			user.push_back(u);
		}
		sort(user.begin() + count, user.end(), cmp);
		user[count].l_r = 1;
		for(int i = count + 1; i < user.size(); i++){
			if(user[i].score == user[i - 1].score){
				user[i].l_r = user[i - 1].l_r;
			}else{
				user[i].l_r = i + 1 - count;
			}
		}
		count += K;
	}
	cout << count << endl;
	sort(user.begin(), user.end(), cmp);
	int fr = 1;
	cout << user[0].r_n << " " << fr <<
		 " " << user[0].l_n << " " << user[0].l_r << endl;
	for(int i = 1; i < user.size(); i++){
		if(user[i].score != user[i - 1].score){
			fr = i + 1;
		}
		cout << user[i].r_n << " " << fr <<
		 " " << user[i].l_n << " " << user[i].l_r << endl;
	}
	return 0;
}	
		
/*
 *while(1); //test segmentation fault
 *
 */
