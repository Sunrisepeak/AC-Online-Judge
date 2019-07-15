//#define Test

#include <iostream>

int main(){
	#ifdef Test
		freopen("../Tdata/B1022.td.in", "r", stdin);
		freopen("../Tdata/1022.out", "w", stdout);
	#endif
	
	int a, b, d;
	int ans[33] = {0};
	scanf("%d %d %d", &a, &b, &d);
	int sum = a + b;
	int index = 0;
/*
	//case: 0
	ans[index++] = sum % d;
	sum /= d;
	while(sum != 0){
		ans[index++] = sum % d;
		sum /= d;
	}
*/
	do{
		ans[index++] = sum % d;
		sum /= d;
	}while(sum != 0);
	
	while(index--){
		printf("%d", ans[index]);
	}
	return 0;
}
