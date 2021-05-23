#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <set>

using namespace std;
using INTP = pair<int, int>;

map<string, int> strToInt;
int table[10001][11] { 0 };


int main() {
    int n, m, cnt { 0 };
    while (cin >> n >> m) {
	getchar();  // del '\n'
	strToInt.clear();
	for (int i = 0; i < n; i++) {
	    string s;
	    getline(cin, s);
	    stringstream row(s);
	    //cout << i << "-------" << s << endl;
	    int col = 0;
	    while (getline(row, s, ',')) {
		if (strToInt.find(s) == strToInt.end()) strToInt[s] = cnt++;
		table[i][col++] = strToInt[s];
	    }
	}
	
	bool isNO = false;
	for (int c1 = 0; c1 < m && !isNO; c1++) {
	    for (int c2 = c1 + 1; c2 < m && !isNO; c2++) {
		map<INTP, int> ipToR;
		for (int r = 0; r < n; r++) {
		    auto ip { INTP(table[r][c1], table[r][c2]) };
		    if (ipToR.find(ip) != ipToR.end()) {
			cout << "NO" << endl;
			cout << ipToR[ip] << " " << r + 1 << endl <<
				c1 + 1 << " " << c2 + 1 << endl;
			isNO = true;
			break;
		    }
		    ipToR[ip] = r + 1;
		}
	    }
	}
	if (!isNO) cout << "YES" << endl;
    }
    return 0;
}

/**
 *  data process:
 *	complex structure to simple structure
 *	str to int
 *
 * */
