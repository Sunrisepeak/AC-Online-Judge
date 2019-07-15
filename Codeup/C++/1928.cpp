//#define Test

#include <iostream>
using namespace std;
int month[2][13] = {//0 is not leapyear but 1.
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isLeap(int y){
//	if(y % 400 == 0 || (y % 4 == 0 && y % 4 == 0))	//ISSUE0: 2h
	if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		return 1;
	return 0;
}

int main(){
	#ifdef Test
		freopen("../Tdata/1928.td.in", "r", stdin);
		freopen("../Tdata/1928.out", "w", stdout);
	#endif
	long long date1, date2;
	while(scanf("%lld%lld", &date1, &date2) == 2){
		if(date1 > date2){	//ISSUE1: 20m 
			int temp = date1;
			date1 = date2;
			date2 = temp;
		}
		int y1, m1, d1, y2, m2, d2;
		y1 = date1 / 10000;		//ISSUE2: date1/1000 error 10m
		m1 = date1 / 100 % 100;
		d1 = date1 % 100;
		y2 = date2 / 10000;
		m2 = date2 / 100 % 100;
		d2 = date2 % 100;
	//	printf("%d %d %d %d %d %d",y1, m1, d1, y2, m2, d2);
		int ans = 0;
		if(y1 == y2 && m1 == m2)
			ans = d2 - d1;
		else{	//ISSUE2: haven't choice simple method 10m
			if(y1 == y2){
				for(int i = m1 + 1; i < m2; i++)
					ans += month[isLeap(y1)][i];
			}else{
				for(int i = m1 + 1; i <= 12; i++) 
					ans += month[isLeap(y1)][i];
				for(int i = 1; i < m2; i++) 
					ans += month[isLeap(y2)][i];
			}
			for(int i = y1 + 1; i < y2; i++)
				ans += (isLeap(i) ? 366 : 365);
			ans += (month[isLeap(y1)][m1] - d1 + d2);
		}
	//	cout << ans + 1 << endl;
		printf("%d\n", ans + 1);
	}
	return 0;
}
