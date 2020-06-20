#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GT[10100], dRoot;
bool visit[10100] { false };
int deep { 0 }, deepest { 0 }, N;

void initVisit() {
	for (int i = 1; i <= N; i++) {	// spend 30m [i < N -> bug]
		visit[i] = false;
	}
}

void DFS(int node, int deepth) {
	//cout << "[DFS]: " << node << "-" << deepth << endl;
	if (deep < deepth) {
		deep = deepth;
	}
	visit[node] = true;
	for (int i = 0; i < GT[node].size(); i++) {
		if (visit[GT[node][i]] == false) {
			DFS(GT[node][i], deepth + 1);
		}
	}
}

int travelGT() {
	int cc { 0 };
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			deep = 0;
			DFS(i, 1);
			cc++;
		}
	}
	if (cc != 1) return cc;		// is not tree
	
	initVisit();
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			deep = 0;
			DFS(i, 1);
			if (deep > deepest) {
				deepest = deep;
				dRoot.clear();
				dRoot.push_back(i);
			} else if (deep == deepest) {
				dRoot.push_back(i);
			}
			initVisit();
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		GT[node1].push_back(node2);
		GT[node2].push_back(node1);
	}
	int k = travelGT();
	if (k != 1) {
		cout << "Error: " << k << " components";
	} else {
		sort(dRoot.begin(), dRoot.end());
		for (int i = 0; i < dRoot.size(); i++) {
			cout << dRoot[i] << endl;
		}
	}
	return 0;
} 
