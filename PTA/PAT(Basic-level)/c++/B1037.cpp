//#define Test

#include <iostream>
#include <cmath>
/* set base number
	const int Galleon = 17 * 29;
	const int Sickle = 29;
*/
long long getKnut(long long a[]){
	return (a[0] * 17 + a[1]) * 29 + a[2];
}
int main(){
	#ifdef Test
		freopen("../Tdata/name.td.in", "r", stdin);    //name: problem id
		freopen("../Tdata/name.out", "w", stdout);
	#endif
	long long p[3], a[3];
	
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &p[0], &p[1], &p[2], &a[0], &a[1], &a[2]);
	long long ans = getKnut(a) - getKnut(p);
	/*format abc;
	 *	a = abc / bc % base(a)
	 *  b = abc / c % base(b)
	 *  b = abc % base(c)
	 */
	long long g = abs(ans) / (17 * 29);
	long long s = abs(ans) / 29 % 17;
	long long k = abs(ans) % 29;
	if(ans < 0){
		printf("-");
	}
	printf("%ld.%ld.%ld", g, s, k); 
	return 0;
}
/*Float Point Exception
 *  /0
 *	%0
 *	data overflow	
 */

