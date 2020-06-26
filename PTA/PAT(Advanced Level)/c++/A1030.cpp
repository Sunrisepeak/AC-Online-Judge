/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-26 14:44:16 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-26 16:18:09
 */

#include <iostream>
#include <vector>
#define INF (1u << 30)

using namespace std;

struct Node {
    int id;
    int len, cost;  // S(firstNode) -> Node
};

vector<Node> G[501];
vector<int> pre[501], tempPath, path;
bool visit[501] { false };
int dis[501] { 0 }, N, M, S, D;

void Dijkstra(int s, int d) {
    fill(dis, dis + 501, INF);
    dis[s] = 0;
    for (int i = 0; i < N; i++) {
        int min = INF, u = -1;
        for (int j = 0; j < N; j++) {
            if (visit[j] == false && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) return;
        visit[u] = true;
        for (int j = 0; j < G[u].size(); j++) {
            int v = G[u][j].id;
            if (visit[v] == false) {
                if (dis[u] + G[u][j].len < dis[v]) {
                    dis[v] = dis[u] + G[u][j].len;      // update shortestPath
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + G[u][j].len == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int optValue { INF };
void DFS(int d) {
    tempPath.push_back(d);
    if (d == S) {   //  exit
        int value { 0 };
        for (int i = tempPath.size() - 1; i > 0; i--) {
            int c1 = tempPath[i];
            for (int j = 0; j < G[c1].size(); j++) {
                if (G[c1][j].id == tempPath[i - 1]) {   // c1 -> id
                    value += G[c1][j].cost;
                    break;
                }
            }
        }
        if (value < optValue) {
            path = tempPath;
            optValue = value;
        }
    } else {
        for (int i = 0; i < pre[d].size(); i++) {
            DFS(pre[d][i]);
        }
    }
    tempPath.pop_back();
}

int main() {
    cin >> N >> M >> S >> D;
    Node temp;
    for (int i = 0; i < M; i++) {
        int id;
        cin >> temp.id >> id >> temp.len >> temp.cost;
        G[id].push_back(temp);  // c1 -> c2
        swap(id, temp.id);
        G[id].push_back(temp);  // c2 -> c1
    }
    Dijkstra(S, D);
    DFS(D);
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << dis[D] << " " << optValue;
    return 0;
}

/**
 * only use Dijkstra [meanwhile deal with cost and path]
 * 
 * 
*/