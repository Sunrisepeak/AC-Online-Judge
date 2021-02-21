#include <iostream>
#include <vector>
#include <iomanip>  // setprecision

using namespace std;
const double MAX_PRICE = 1 << 30u;
vector<double> gStaPrice(30001, MAX_PRICE);

int getLowPriceSta(int begin, int end, double currPri) {
    int lpp = begin;
    double lowPrice = gStaPrice[lpp];
    for (int i = lpp + 1; i < end; i++) {
	if (gStaPrice[i] <= currPri) {
	    lpp = i;
	    break;
	}
	if (gStaPrice[i] < lowPrice) {
	    lowPrice = gStaPrice[i];
	    lpp = i;
    	}
    }
    return lpp;
}

int main() {
    int C, D, Davg, N;
    cin >> C >> D >> Davg >> N;
    auto runMaxD = C * Davg;
    for (int i = 0; i < N; i++) {
	double p, d;
	cin >> p >> d;
	gStaPrice[d] = p;   // Or use p / Davg
    }
    cout << fixed; cout.precision(2);	// set print format
    double currentSta { 0 }, cheapestPrice { 0.0 }, currC { 0.0 };
    while (true) {
	double lPriSta;
	if (currentSta + runMaxD >= D) {    // exit1
	    lPriSta = getLowPriceSta(currentSta + 1, D, gStaPrice[currentSta]);
	    cheapestPrice += (lPriSta - currentSta) / Davg * gStaPrice[currentSta] + (D - lPriSta) / Davg * gStaPrice[lPriSta];
	    break;
	} else {
	    lPriSta = getLowPriceSta(currentSta + 1, currentSta + runMaxD + 1, gStaPrice[currentSta]);
	    if (gStaPrice[lPriSta] == MAX_PRICE) {  // exit2
		cout << "The maximum travel distance = " << currentSta + runMaxD << endl;
		return 0;
	    } else {
		if (gStaPrice[lPriSta] > gStaPrice[currentSta]) {
		    
		} else {
		    // Note: distance / Davg = used capcity
		    cheapestPrice += (lPriSta - currentSta) / Davg * gStaPrice[currentSta];
		}
		currentSta = lPriSta;
		cout << cheapestPrice << "-" << currentSta << endl;
	    }
	}
    }
    cout << cheapestPrice << endl;
    return 0;
}

/**
 *  Best Practice:
 *	Price / Davg -> "newPrice_Standard"
 *  Note: ***
 *	not only find station of lower price but also first choice station of less than current price
 * */
