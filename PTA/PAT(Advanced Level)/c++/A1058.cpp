//#define Test

#include <iostream>
const int Sickle = 17;
const int Knut = 29; 
int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);    //name: problem id
		freopen("../Tdata/name.out", "w", stdout);
	#endif
	
	long long a[3], b[3];
	/*
	 * carry[] = { 0, 17, 29};	//carry table
	 * int c = 0;
	 * ans[i] = (a[i] + b[i] + c) % carry[i]
	 * c = (a[i] + b[i] + c) / carry[i]
	 */
	long long A = a[0]*Sickle*Knut + a[1] * Knut + a[2];
	long long B = b[0]*Sickle*Knut + b[1] * Knut + b[2];
	long long sum = A + B;
	printf("%lld.%lld.%lld", sum / (Sickle * Knut), sum / Sickle % 17, sum % Knut);

	return 0;
}


