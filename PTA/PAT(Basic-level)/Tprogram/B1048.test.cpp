#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main(){
	freopen("../Tdata/B1048.td.in", "w", stdout);    //name : problem name
	default_random_engine g(time(0));
	uniform_int_distribution<int> range(0, 100000000);
	
	int N{ 1000 };
	while(N--){
		cout << range(g) << " " << range(g) << endl;
	}
	
	return 0;
}
