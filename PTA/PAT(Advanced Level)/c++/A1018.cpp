/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-26 18:14:46 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-26 20:33:48
 */

#include <iostream>
#include <vector>
#define INF (1u << 30)

using namespace std;

int G[501][501] { { 0 } };      // save path-len
int sCapacity[501], dis[501];
bool visit[501] { false };
vector<int>  pre[501];
int C, N, S, M;


void Dijkstra() {
    fill(dis, dis + 501, INF);
    dis[0] = 0;
    for (int i = 0; i <= N; i++) {
        int min = INF, u = -1;
        for (int j = 0; j <= N; j++) {
            if (visit[j] == false && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) return;
        visit[u] = true;
        for (int j = 0; j <= N; j++) {
            if (visit[j] == false && G[u][j] != 0) {
                if (dis[u] + G[u][j] < dis[j]) {
                    pre[j].clear();
                    pre[j].push_back(u);
                    dis[j] = dis[u] + G[u][j];
                } else if (dis[u] + G[u][j] == dis[j]) {
                    pre[j].push_back(u);
                }
            }
        }
    }
}

vector<int> tempPath, path;
int optNeed { INF }, optBack { INF };

void DFS(int s) {
    tempPath.push_back(s);
    if (s == 0) {   // spend 1h
        int need { 0 }, current { 0 };
        for (int i = tempPath.size() - 2; i >= 0 ; i--) {
            int sNeed =  C / 2 - sCapacity[tempPath[i]];
            if (sNeed < 0) {
                current += abs(sNeed);
            } else if (sNeed <= current) {
                 current -= sNeed;
            } else {
                need += sNeed - current;
                current = 0;
            }
            //cout << "[debug]: " << tempPath[i] << " -> "<< need << endl;
        }
        if (need < optNeed || (need == optNeed && current < optBack)) {
            path = tempPath;
            optNeed = need;
            optBack = current;
        }
    } else {
        for (int i = 0; i < pre[s].size(); i++) {
            DFS(pre[s][i]);
        }
    }
    tempPath.pop_back();
}

int main() {
    cin >> C >> N >> S >> M;
    for (int i = 1; i <= N; i++) {
        cin >> sCapacity[i];
    }
    for (int i = 0; i < M; i++) {
        int s1, s2, t;
        cin >> s1 >> s2 >> t;
        G[s1][s2] = G[s2][s1] = t;
    }
    
    Dijkstra();
    DFS(S);

    cout << optNeed << " " << path[path.size() - 1];
    for (int i = path.size() - 2; i >= 0; i--) {
        cout << "->" << path[i];
    }
    cout << " " << optBack;
    return 0;
}