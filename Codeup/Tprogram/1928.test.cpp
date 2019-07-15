#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main(){
	freopen("../Tdata/1928.td.in", "w", stdout);
	default_random_engine g(time(0));
	uniform_int_distribution<int> r_year(1000, 3000);
	uniform_int_distribution<int> r_month(1, 12);
	uniform_int_distribution<int> r_day(1, 28);
	int N = 1000;
	while(N--){
		printf("%d%02d%02d\n", r_year(g), r_month(g), r_day(g));
	}
	
	return 0;
}
