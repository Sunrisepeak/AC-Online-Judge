#include <iostream>
//#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

struct InOutTime {
    string id;
    int time;
    InOutTime(string  _id, int _time) : id { _id }, time { _time } { }
};

// id : <in, out>
//unordered_map<string, pair<bool, bool>> personSatuts;
vector<InOutTime> ioTime;

int toSeconds(const string &s) {
    return stoi(s.substr(0, 2)) * 3600 +
	   stoi(s.substr(3, 2)) * 60 +
	   stoi(s.substr(6, 2)) * 60; 
}

int main() {
    int N;
    cin >> N;
    string id, t1, t2;
    for (int i = 0; i < N; i++) {
	cin >> id >> t1 >> t2;
	int inT = toSeconds(t1);
	int outT = toSeconds(t2);
	ioTime.push_back(InOutTime(id, inT));
	ioTime.push_back(InOutTime(id, outT));
	//personSatuts[id] = make_pair<bool, bool>(false, false);
    }
    sort(ioTime.begin(), ioTime.end(), 
	[](const InOutTime &A, const InOutTime &B) { return A.time < B.time; });
/*    
    for (int i = 0; i < ioTime.size(); i++) {
	if (i % 2 == 0) {
	    personSatuts[ioTime[i].id].first = true;
	    cout << ioTime[i].id << ": in" << endl;
	} else {
	    personSatuts[ioTime[i].id].second = true;
	    cout << ioTime[i].id << ": out" << endl;
	}

    }
    bool fPrint = true;
    for_each(personSatuts.cbegin(), personSatuts.cend(),
	    [ = ](const auto &KV) mutable { 
		if (KV.second.first == KV.second.second) {
		    if (!fPrint) {
			cout << " ";
			fPrint = false;
		    }
		    cout << KV.first;
		}
	    });
    cout << endl;
*/
    cout << ioTime[0].id << " " << ioTime.back().id << endl;
    return 0;
}

/**
 *  misunderstand for problem
 *
 * */
