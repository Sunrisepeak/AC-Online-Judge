#include <iostream>
#include <algorithm>

using namespace std;

struct Yb{
	double price;
	double weight;
	double all_price;
};
bool cmp(Yb a, Yb b){
	return a.price >= b.price;
}
int main(){
	Yb yb[1001];
	int N, D;
	cin >> N >> D;
	for(int i = 0; i < N; i++){
		cin >> yb[i].weight;
	}
	for(int i = 0; i < N; i++){
		cin >> yb[i].all_price;
	//	yb[i].price = yb[i].price / yb[i].weight; //ISSUE: 10m
		yb[i].price = yb[i].all_price / yb[i].weight;
	}
	sort(yb, yb + N, cmp);
	double ans = 0;
	for(int i = 0; i < N; i++){
		if(yb[i].weight < D){
			D -= yb[i].weight;
			ans += yb[i].all_price;
		}else{
		//	ans += (yb[i].weight - D) * yb[i].price; //ISSUE: 10m
			ans += D * yb[i].price;
			break;
		}
	}
	printf("%.2lf", ans);
	return 0;
}
