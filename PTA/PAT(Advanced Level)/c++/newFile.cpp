#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	map<int, vector<int>> test;
	test[1].clear();
	test[1].push_back(2);
	cout << test[1][0] << endl;
	return 0;
}
// array Tree
