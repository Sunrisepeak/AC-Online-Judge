#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

using namespace std;

map<set<int>, int> setToId;
map<int, set<int>> idToSet;

//setId from 0 to n - 1
int getID(set<int> s) {
    if (setToId.find(s) != setToId.end()) return setToId[s];
    int tempId = setToId[s] = idToSet.size();
    idToSet[tempId] = s;
    return tempId;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
	stack<int> cs;
	int n;
	cin >> n;
	for (int j = 0; j < n; j++) {
	    string op;
	    cin >> op;
	    if (op == "PUSH") cs.push(getID(set<int>()));
	    else if (op == "DUP") cs.push(cs.top());
	    else {
		auto set1 = idToSet[cs.top()]; cs.pop();
		auto set2 = idToSet[cs.top()]; cs.pop();
		set<int> set3;
		switch(op[0]) {	    // note: char -> int
		    case 'U': 
			set_union(ALL(set1), ALL(set2), INS(set3));
			break;
		    case 'I':
			set_intersection(ALL(set1), ALL(set2), INS(set3));
			break;
		    case 'A':
			set3 = set2; set3.insert(getID(set1));
			break;
		    default:
			;
		}
		cs.push(getID(set3));
	    }
	    cout << idToSet[cs.top()].size() << endl;
	}
	cout << "***" << endl;
    }
    return 0;
}
