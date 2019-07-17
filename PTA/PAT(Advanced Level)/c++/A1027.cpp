//#define Test

#include <iostream>
// another is mapping table 
char getValue(int v){
	if(v < 10)
		return '0' + v;
	else
		return 'A' + v - 10;
}

int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);    //name: problem id
		freopen("../Tdata/name.out", "w", stdout);
	#endif
	
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	printf("#%c%c%c%c%c%c", getValue(r/13), getValue(r%13), getValue(g/13), getValue(g%13), getValue(b/13), getValue(b%13));
	return 0;
}


