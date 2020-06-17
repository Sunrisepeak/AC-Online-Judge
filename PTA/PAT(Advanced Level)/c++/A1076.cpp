#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool G[1010][1010] = { false };
vector<int> level(1010, 0);		// save levels
bool visit[1010] = { false };

int N, L;

void initGVisit() {
	for (int i = 1; i <= N; i++) {
		visit[i] = false;
	}
}

int BFS(int no) {
	int ans { 0 };
	level[no] = 0;
	queue<int> gQ;
	gQ.push(no);
	visit[no] = true;
	while (!gQ.empty()) {
		int temp = gQ.front();
		gQ.pop();
		for (int i = 1; i <= N; i++) {
			if (G[temp][i] && visit[i] == false) {
				visit[i] = true;
				level[i] = level[temp] + 1;
				if (level[i] <= L) {
					gQ.push(i);
					ans++;
				}
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int temp;
			cin >> temp;
			G[temp][i] = true;		// set in-degree [temp -> i]
		}
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int no;
		cin >> no;
		cout << BFS(no) << endl;
		initGVisit();
	}
	return 0;
}
