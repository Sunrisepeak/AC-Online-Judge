#include <iostream>
#include <vector>
#include <map>
#define INF (1u << 30)

using namespace std;

struct Node {
    int v, side;
    int u;
};

struct Road {
    int c1, c2; // c1 <= c2
    Road(int a, int b) {
        if (b < a) {
            swap(b, a);
        }
        c1 = a;
        c2 = b;
    }

    Road & operator=(const Road &r) {
        c1 = r.c1;
        c2 = r.c2;
        return *this;
    }
};

struct Dis {
    int dis;
    Road r;
    Dis(int d, Road _r = Road(0, 0)) : dis{ d }, r{ _r } {}
};

map<Road, bool> hashRoad;
Dis dis[1001];
bool visit[1001] { false };
vector<Node> G[1001];
int N, M;

int prim() {
    Dis d(INF, Road(0, 0));
    fill(dis, dis + 1000, d);
    dis[0] = Dis(0);
    int ans { 0 };
    for (int i = 0; i < N; i++) {
        int min = INF, u = -1;
        for (int j = 0; j < N; j++) {
            if (visit[j] == false && dis[j].dis < min) {
                u = j;
                min = dis[u].dis;
            }
            if (u == -1) return -1;
            visit[u] = true;
            if (hashRoad.find(dis[u].r) == hashRoad.end()) {
                ans += dis[u].dis;
            }
            for (int j = 0; j < G[u].size(); j++) {
                if (visit[G[u][j].v] == false && G[u][j].side < dis[G[u][j].v].dis) {
                    dis[G[u][j].v] = G[u][j].side;
                    dis[G[u][j].v].r = Road(u, G[u][j].v);
                }
            }
        }
    }
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        
    }
    return 0;
}