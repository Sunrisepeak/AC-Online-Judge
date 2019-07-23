#define Test

#include <iostream>

int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);
		freopen("../Tdata/name.ans.out", "w", stdout);
	#endif
	
	
	return 0;
}