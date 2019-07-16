//#define Test

#include <iostream>
using namespace std;
int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);    //name: problem id
		freopen("../Tdata/name.out", "w", stdout);
	#endif
	int a, b;
	cin >> a >> b;
	if(b != 0){
		cout << a * b << " " << b - 1;
	}else
		cout << "0 0";		//ISSUE0: 5m, because of high to low about exp of poly
	while(cin >> a >> b){
		if(b != 0){
			cout << " " << a * b << " " << b - 1;
		}
	} 
	return 0;
}
