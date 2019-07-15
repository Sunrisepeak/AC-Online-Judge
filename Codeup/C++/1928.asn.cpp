//#define Test

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
bool issun(int year) {
    if ((year % 100 != 0 &&year % 4 == 0)||year%400==0) {//判断 闰年 的方法！！
        return true;
    }
    else{
        return false;
    }
}

int main()
{
	#ifdef Test
		freopen("../Tdata/1928.td.in", "r", stdin);
		freopen("../Tdata/1928.ans.out", "w", stdout);
	#endif
    int a1, a2;
    int year1, year2, mon1, mon2, day1, day2;
    while(scanf("%d%d",&a1,&a2)!=EOF){
        //没有强调，需要保证前者早于后者。
        if (a1 > a2) {
            int tmp = a1;
            a1 = a2;
            a2 = tmp;
        }
        day1 = a1 % 100;
        a1 = a1 / 100;
        mon1 = a1 % 100;
        a1 = a1 / 100;
        year1 = a1 % 10000;
        day2 = a2 % 100;
        a2 = a2 / 100;
        mon2 = a2 % 100;
        a2 = a2 / 100;
        year2 = a2 % 10000;
        int days = 1;
        int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int mons[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
        while (!(year1 == year2&&mon1 == mon2&&day1 == day2)) {
            day1++;
            if (issun(year1)) {
                if (day1 == mons[mon1] + 1) {
                    day1 = 1;
                    mon1++;
                }
            }
            else {
                if (day1 == mon[mon1] + 1) {
                    day1 = 1;
                    mon1++;
                }
            }
            if (mon1 == 13) {
                mon1 = 1;
                year1++;
            }
            days++;
        }
        printf("%d\n", days);
    }
    return 0;
}
