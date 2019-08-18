#include <iostream>
using namespace std;
const int maxn = 1000001;
int prime[maxn] = {0}, pNum = 0;
int p[maxn] = {false};
void find_prime(int n){
	for(int i = 2; i < maxn; i++){
		if(p[i] == false){
			prime[pNum++] = i;
			if(pNum >= n) break;
			for(int j = i + i; j < maxn; j += i) p[j] = true;
		}
	}
} 
int main(){
	int M, N;
	cin >> M >> N;
	find_prime(N);
	int count = 0;
	for(int i = M; i <= N; i++){
		cout << prime[i - 1];
		count++;
		if(count % 10 != 0 && i < N) cout << " "; 
		else cout << endl;
	}
	return 0;
}
