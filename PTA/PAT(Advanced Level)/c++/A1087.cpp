/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-28 10:28:52 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-28 12:55:12
 */

#include <iostream>
#include <vector>
#include <map>
#define INF (1u << 30)

using namespace std;

map<string, map<string, int>> cityG;    // rejacent table
map<string, int> happiness, dis;
map<string, vector<string>> pre;
map<string, bool> visit;
int N, K;
string start;

void Dijkstra(string s) {
    dis[s] = 0;
    for (int i = 0; i < N; i++) {
        int min = INF;
        string u = "E";
        for (auto it = cityG.begin(); it != cityG.end(); it++) {
            if (visit[it->first] == false && dis[it->first] < min) {
                u = it->first;
                min = dis[it->first];
            }
        }
        if (u == "E") return;
        visit[u] = true;
        for (auto it = cityG[u].begin(); it != cityG[u].end(); it++) {
            if (visit[it->first] == false) {
                if (dis[u] + it->second < dis[it->first]) {
                    dis[it->first] = dis[u] + it->second;
                    pre[it->first].clear();         // is not u but it->first [spend 15min]
                    pre[it->first].push_back(u);
                } else if (dis[u] + it->second == dis[it->first]) {
                    pre[it->first].push_back(u);
                }
                //cout << "[u->v]: " << u << "->" << it->first << endl;
            }
        }
    }
}

vector<string> path, tempPath;
double maxHappiness { -1 }, aveHappiness { -1 }, pathNum { 0 };
void DFS(string s) {
    tempPath.push_back(s);
    if (s == start) {
        pathNum++;
        double aveHap { 0 }, maxHap { 0 };
        for (int i = 0; i < tempPath.size(); i++) {
            maxHap += happiness[tempPath[i]];
        }
        aveHap = maxHap / (tempPath.size() - 1);     // get average Hap
        //cout << "[" << maxHap << ", " << aveHap << "]" << " ? "
        //     << "[" << maxHappiness << ", " << aveHappiness << "]" << endl;

        if (maxHap > maxHappiness) {
            path = tempPath;
            maxHappiness = maxHap;
            aveHappiness = aveHap;
        } else if (maxHap == maxHappiness && aveHap > aveHappiness) {
            path = tempPath;
            maxHappiness = maxHap;
            aveHappiness = aveHap;
        }
    } else {
        for (int i = 0; i < pre[s].size(); i++) {
            DFS(pre[s][i]);
        }
    }
    tempPath.pop_back();
}


int main() {
    cin >> N >> K >> start;
    happiness[start] = 0;
    visit[start] = false;
    for (int i = 0; i < N - 1; i++) {
        string tName;
        int hap;
        cin >> tName >> hap;
        // init map<> info
        happiness[tName] = hap;
        visit[tName] = false;
        dis[tName] = INF;
    }
    for (int i = 0; i < K; i++) {
        string n1, n2;
        int cost;
        cin >> n1 >> n2 >> cost;
        //cityG[n1][n2] = cityG[n1][n2] = cost;     // spend 30min
        cityG[n2][n1] = cityG[n1][n2] = cost;
    }
    Dijkstra(start);
    DFS("ROM");
    cout << pathNum << " " << dis["ROM"] <<
            " " << maxHappiness << " " << (int)aveHappiness << endl;
    if (path.size() != 0)
    cout << path[path.size() - 1];
    for (int i = path.size() - 2; i >= 0; i--) {
        cout << "->" << path[i];
    }
    return 0;
}


/**
 * map:
 *      create obj when use it.
 * 
 * key-value thinking:
 *      string a[10]   (map<int, string>) key:int, value:string
 *      map<string, map<string, int>>   a[string][string] = int;
 * 
 * keyword:
 *      dijkstra + dfs
 *          shortest path
 *          path number
 *          point power
 *          path print
 * 
*/