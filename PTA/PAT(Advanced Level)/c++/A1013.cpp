#include <iostream>
#include <vector>

using namespace std;

bool visit[1010] { false };
vector<int> cities[1010];	// graph of city [adjacent list]
int N, M, K;

void initVisit(int occupied) {
	for (int i = 1; i <= N; i++) {
		visit[i] = false;
	}
	visit[occupied] = true;
}

void DFS(int c) {
	visit[c] = true;
	for (int i = 0; i < cities[c].size(); i++) {
		if (visit[cities[c][i]] == false) {
			DFS(cities[c][i]);
		}
	}
}

int travelCities() {
	int cc { 0 };		// connected component
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			DFS(i);
			cc++;
		}
	}
	return cc - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		cities[c1].push_back(c2);
		cities[c2].push_back(c1);
	}
	for (int i = 0; i < K; i++) {
		int occ;
		cin >> occ;
		initVisit(occ);
		cout << travelCities() << endl;
	}
	return 0;
}
