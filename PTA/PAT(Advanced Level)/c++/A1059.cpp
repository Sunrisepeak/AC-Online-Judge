#include <iostream>
#include <cmath>
using namespace std;
using LL = long long;
struct Factor{
	int x;
	int cnt;
}fac[12];
/*
bool is_prime(LL n){
	if(n == 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
*/
const int maxn = 100001;
int prime[maxn], p_num = 0;
bool p[maxn] = {false};
void find_prime(){
	for(LL i = 2; i < maxn; i++){
		if(p[i] == false){
			prime[p_num++] = i;
			for(int j = i + i; j < maxn; j += i) prime[j] = true;
		}
	}
}
int main(){
	find_prime();
	LL n, num = 0;
	cin >> n;
	if(n == 1) cout << "1=1";
	else{
		cout << n << "=";
		int sq = (int)sqrt(1.0 * n);
		for(int i = 0; i < p_num && prime[i] <= sq; i++){
			if(n % prime[i] == 0){
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while(n % prime[i] == 0){
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			if(n == 1) break;
		}
		if(n != 1){
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		//
		for(int i = 0; i < num; i++){
			if(i > 0) cout << "*";
			if(fac[i].cnt > 1){
				printf("%d^%d", fac[i].x, fac[i].cnt);
			}else{
				printf("%d", fac[i].x);
			}
		}
	}
	
	return 0;
}
