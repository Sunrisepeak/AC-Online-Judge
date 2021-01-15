#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> coeff{2, 3, 5};
ll cntUn = 0, un;

int main() {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    set<ll> uNumbers;
    pq.push(1);
    uNumbers.insert(1);
    while (cntUn != 1500) {
	un = pq.top(); pq.pop();
	cntUn++;
	//cout << cntUn << " " << un << endl;
	for (auto v : coeff) {
	    ll temp = un * v;
	    if (!uNumbers.count(temp)) {
		uNumbers.insert(temp);	    // Note: uNumbers.size() >= cntUn
		pq.push(temp);
	    }
	}
    }
    cout << "The 1500'th ugly number is " << un << "." << endl;
    return 0;
}



/*
#include <iostream>

using namespace std;
using ll = long long;

bool isUglyNumbers(ll n) {
    for (ll i = 2; i <= 5; i++) {
	while (n != 0 && n % i == 0) n /= i;
	if (n == 1) break;
    }
    return n == 1;
}

int main() {
    ll num = 0, cnt = 0;
    while (cnt != 1500) {
	//cout << cnt << " " << num << endl;
	num++;
	if (isUglyNumbers(num)) cnt++;
    }
    cout << "The 1500'th ugly number is " << num << "." << endl;
    return 0;
}
*/
