#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int u, v;   //vertex
    int side;
};

vector<Edge> E;
vector<int> UFS;
int N, M;

bool cmp(const Edge &A, const Edge &B) {
    return A.side < B.side;
}

int findRoot(int n) {
    if (UFS[n] == n) {
        return n;
    }
    return UFS[n] = findRoot(UFS[n]);   // path contract
}

int kruskal() {
    int ans { 0 }, edgeNum { 0 };
    for (int i = 0; i < UFS.size(); i++) {  // init UFS
        UFS[i] = i;
    }
    sort(E.begin(), E.end(), cmp);
    for (int i = 0; i < E.size(); i++) {
        int uFa = findRoot(E[i].u);
        int vFa = findRoot(E[i].v);
        //cout << "[uFa, vFa]: " << uFa << ", " << vFa << endl;
        if (vFa != uFa) {
            UFS[vFa] = uFa;     // union op
            edgeNum++;
            ans += E[i].side;
            if (edgeNum == N - 1) break;
        }
    }
    if (edgeNum < N - 1) return -1;
    return ans;
}

int main() {
    cin >> N >> M;
    UFS.resize(N + 1);
    for (int i = 0; i < M; i++) {
        Edge temp;
        cin >> temp.u >> temp.v >> temp.side;
        E.push_back(temp); 
    }
    int ans = kruskal();
    if (ans == -1) {
        cout << "orz";
    } else {
        cout << ans;
    }
    return 0;
}