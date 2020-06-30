#include <iostream>
#define INF (1u << 30)

using namespace std;

int G[501][501] { { 0 } };
bool visit[501] { false };
int dis[501], spNum[501] { 0 }, res[501] { 0 }, teams[501] { 0 };
int  N, M, C1, C2;

void Dijkstra(int s, int end) {
	fill(dis, dis + 501, INF);
	dis[s] = 0, res[s] = teams[s], spNum[s] = 1;
	for (int i = 0; i < N; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; j++) {
			if (visit[j] == false && dis[j] < MIN) {
				u = j;
				MIN = dis[j];
			}
		}
		if (u == -1 || end  == u) return;
		visit[u] = true;							// add to set of accessed
		for (int j = 0; j < N; j++) {				// update shortest paths [s -> un-accessed]
			if (visit[j] == false && G[u][j] != 0)
				if (G[u][j] + dis[u] < dis[j]) {
					dis[j] = G[u][j] + dis[u];
					res[j] = res[u] + teams[j];
					spNum[j] = spNum[u];
				} /*else if (G[u][j] + dis[u] == dis[j] && res[j] < teams[j] + res[u]){		// spend 20min
					res[j] = teams[j] + res[u];		// update res[j] for maximum amount
					spNum[j] += spNum[u];			// add paths
				}*/
				  else if (G[u][j] + dis[u] == dis[j]) {
					if(res[j] < teams[j] + res[u])
						res[j] = teams[j] + res[u];		// update res[j] for maximum amount
					spNum[j] += spNum[u];				// add paths
				}
		}
	}
}

int main() {
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++) {
		cin >> teams[i];
	}
	for (int i = 0; i < M; i++) {
		int c1, c2, len;
		cin >> c1 >> c2 >> len;
		G[c2][c1] = G[c1][c2] = len;
	}
	Dijkstra(C1, C2);
	cout << spNum[C2] << " " << res[C2];
	return 0;
}
