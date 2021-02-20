#include <iostream>
#include <iomanip>  // setprecision
using namespace std;

const char intToChar[3] {'W', 'T', 'L'}; 
int ans[3] { 0 };
double maxProfit { 0.65 * 2 };

int main() {
    for (int i = 0; i < 3; i++) {
	double odds { 0 }, maxOdds { 0 };
	for (int j = 0; j < 3; j++) {
	    cin >> odds;
	    if (odds > maxOdds) {
		ans[i] = j;
		maxOdds = odds;
	    }
	}
	maxProfit *= maxOdds;
    }
    
    for (int i = 0; i < 3; i++) {
	cout << intToChar[ans[i]] << " "; 
    }
    // Fixed belong to iostream op_sign means fix_decimalism
    cout << setprecision(2) << fixed << maxProfit - 2 << endl;
    return 0;
}
