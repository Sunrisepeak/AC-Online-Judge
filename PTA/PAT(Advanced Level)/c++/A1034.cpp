#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Members {
	bool access { false };
	int weight { 0 };
	vector<string> adjacent;
};

struct GHead {
	string name { "--false" };
	int number { 0 }, totalW { 0 };
};

map<string, Members> Gangs;
vector<GHead> ans;
int N, K;

bool cmp(const GHead A, const GHead B) {
	return A.name < B.name;
}

void DFS(string name, GHead &gh) {
	//cout << "[DFS] " << name << endl;
	Gangs[name].access = true;
	gh.number++;
	gh.totalW += Gangs[name].weight;
	if (Gangs.find(gh.name) == Gangs.end() || Gangs[gh.name].weight < Gangs[name].weight) {
		gh.name = name;
	}
	for (int i = 0; i < Gangs[name].adjacent.size(); i++) {
		if (Gangs[Gangs[name].adjacent[i]].access == false) {
			DFS(Gangs[name].adjacent[i], gh);
		}
	}
}

void travelGangs() {
	for (auto it = Gangs.begin(); it != Gangs.end(); it++) {
		if (it->second.access == false) {
			GHead gh;
			DFS(it->first, gh);
			if (gh.totalW / 2 > K && gh.number > 2) {	//[totalW]:two times for a side, so '/2'
				ans.push_back(gh);
			}
			//cout << "[debug] " << it->first << endl;
			//cout << "[GHead] " << gh.name << " - " << gh.number <<
			//	    " - " << gh.totalW << endl;
		}
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string n1, n2;
		int w;
		cin >> n1 >> n2 >> w;
		
		if (Gangs.find(n1) != Gangs.end()) {
			Gangs[n1].weight += w;
		} else {
			Gangs[n1].weight = w;
		}
		Gangs[n1].adjacent.push_back(n2);
		
		if (Gangs.find(n2) != Gangs.end()) {
			Gangs[n2].weight += w;
		} else {
			Gangs[n2].weight = w;
		}
	}
	travelGangs();
	sort(ans.begin(), ans.end(), cmp);
	if (ans.size() == 0) {
		cout << "0";
	} else {
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].name << " " << ans[i].number << endl;
		}
	
	}
	return 0;
}
