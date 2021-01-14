#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct TeamQueue {
    queue<int, deque<int> > teamNoQ;
    vector<decltype(teamNoQ)> Q;

    TeamQueue() = default;

    TeamQueue(int qNumber) {
	Q.resize(qNumber);
    }

    void push(const int &tNo,const int &no) {
	if (Q[tNo].empty())
	    teamNoQ.push(tNo);
	Q[tNo].push(no);
    }

    int pop() {
	auto tNo = teamNoQ.front();
	auto temp = Q[tNo].front();
	Q[tNo].pop();
	if (Q[tNo].empty()) teamNoQ.pop();
	return temp;
    }
};

map<int, int> toTeamNo;	    // no --> team

int main() {
    std::ios::sync_with_stdio(false);
    int t, no, nums, cnt = 0;
    while (cin >> t && t != 0) {
	cout << "Scenario #" << ++cnt << endl;
	auto tq = TeamQueue(t);
	for (int i = 0; i < t; i++) {
	    cin >> nums;
	    for (int j = 0; j < nums; j++) {
		cin >> no;
		toTeamNo[no] = i;	
	    }
	}
	string cmd;
	while (cin >> cmd && cmd[0] != 'S') {
	    if (cmd[0] == 'E') {
		cin >> no;
		tq.push(toTeamNo[no], no);
	    } else {
		cout << tq.pop() << endl;
	    }
	}
	toTeamNo.clear();
	cout << endl;
    }
    return 0;
}
