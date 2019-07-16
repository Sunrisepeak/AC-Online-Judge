//#define Test

#include <iostream>
using namespace std;
int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);    //name: problem id
		freopen("../Tdata/name.out", "w", stdout);
	#endif
	double p[2002] = {0};
	double ans[2002] = {0};
	int K;
	int a;
	double b;
	cin >> K;
	while(K--){
		cin >> a >> b;
		p[a] = b;
	}
	cin >> K;
	while(K--){
		cin >> a >> b;
		for(int i = 0; i < 2002; i++){
			if(p[i] != 0){
				ans[i + a] += (b * p[i]);
			}
		}
	}
	int count = 0;
	for(int i = 0; i < 2001; i++){
		if(ans[i] != 0){
			count++;
		}
	}
	cout << count;
	for(int i = 2001; i >= 0; i--){
		if(ans[i] != 0){
		//	cout << " " << i << " " << ans[i];			
			printf(" %d %.1lf", i, ans[i]);
		}
	}
	return 0;
}
