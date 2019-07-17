//#define Test

#include <iostream>
using namespace std;
int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);    //name: problem id
		freopen("../Tdata/name.out", "w", stdout);
	#endif
	int N{0}, B{0};
	int ans[100] = {0};
	while(cin >> N >> B){
		int index = 0;
		do{	//do..while for numeral system, avoid error of boundary to "N=0" type 
			ans[index++] = N % B;
			N /= B;
		}while(N);
		bool isP = true;
		for(int i = 0; i < index; i++){
			if(ans[i] != ans[index - i -1]){
				isP = false;
				break;
			}
		}
		if(isP){
			cout << "Yes" << endl;
		}else
			cout << "No" << endl;
		cout << ans[index - 1];
		for(int i = index - 2; i >= 0; i--){
			cout << " " << ans[i];
		}
	}
	return 0;
}


