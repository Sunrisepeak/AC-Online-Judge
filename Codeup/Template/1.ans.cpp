#define Test

#include <iostream>

int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);		//name: problem id 
		freopen("../Tdata/name.ans.out", "w", stdout);
	#endif
	
	
	return 0;
}
