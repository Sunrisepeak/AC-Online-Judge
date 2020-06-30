#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#define INF (1u << 30)

using namespace std;

struct Node {
    int v, side;
};

int N, M, C1, C2;
vector<Node> G[510];
int dis[510] { 0 }, w[510] { 0 }, num[510] { 0 }, weight[501];
set<int> pre[510];

void Bellman(int s) {
    fill(dis, dis + 510, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    dis[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < N - 1; i++) {       // vertex num
        for (int u = 0; u < N; u++) {       // side num
            for (int j = 0; j < G[u].size(); j++) {
                int v = G[u][j].v;
                if (dis[u] + G[u][j].side < dis[v]) {
                    dis[v] = dis[u] + G[u][j].side;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);   // set can avoid the same of u
                } else if (dis[u] + G[u][j].side == dis[v]) {
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                    pre[v].insert(u);
                    num[v] = 0;
                    for (auto it = pre[v].begin(); it != pre[v].end(); it++) {
                        num[v] += num[*it];
                    }
                }
            }
        }
        /*** Note: the opt could lead to reduce of shortestPathNum and weight(most)
            bool isOk = true;
            for (int u = 0; u < N; u++) {
                for (int j = 0; j < G[u].size(); j++) {
                    int v = G[u][j].v;
                    if (dis[u] + G[u][j].side < dis[v]) {
                        isOk = false;
                        break;
                    }
                }
                if (isOk == false) break;
            }
            if (isOk)
                return;
        */
    }
}

int main() {
    cin >> N >> M >> C1 >> C2;
    for (int i = 0; i < N; i++) {
        int team;
        cin >> team;
        weight[i] = team;
    }
    for (int i = 0; i < M; i++) {
        int c1;
        Node temp;
        cin >> c1 >> temp.v >> temp.side;
        G[c1].push_back(temp);
        swap(c1, temp.v);
        G[c1].push_back(temp);
    }
    Bellman(C1);
    cout << num[C2] << " " << w[C2];
    return 0;
}