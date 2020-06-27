/*
 * @Author: SPeak Shen 
 * @Date: 2020-06-27 13:58:05 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2020-06-27 19:13:32
 */

// score: 26, case 4 : wrong answer

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define INF (1u << 30)

using namespace std;

int G[1100][1100] { { 0 } };
int dis[11][1100] { { 0 } };
bool visit[1100] { false };
int N, M, K, D;

struct OptSolu {
    int id { INF }, disGH { 0 };
    double aveDisHou { INF };

    void computeOptG(int g) {
        double sum { 0 };
        int minDis { INF };
        for (int i = 1; i <= N; i++) {
            sum += dis[g][i];
            if (minDis > dis[g][i]) {
                minDis = dis[g][i];
            }
            //cout << "[dis]: " << dis[g][i] << " " << g << "-" << i << endl;
        }
        aveDisHou = sum / N;
        this->disGH = minDis;
        id = g;
    }

    bool operator<(const OptSolu s) {
        if (disGH > s.disGH) return true;
        else if (disGH == s.disGH) {
            if (aveDisHou == s.aveDisHou) {
                return id < s.id;
            }
            return aveDisHou < s.aveDisHou;
        }
        return false;       // spend 30min (forget deal with disGH > s.disGH)
    }

    OptSolu & operator=(const OptSolu &s) {
        id = s.id;
        aveDisHou = s.aveDisHou;
        disGH = s.disGH;
        return *this;
    }

    friend ostream & operator<<(ostream &os, const OptSolu &s) {
        os << "<" << s.id << ", " << s.disGH << ", " << s.aveDisHou << ">";
        return os;
    }
};

void visitInit() {
    for (int i = 1; i <= N + M; i++) {
        visit[i] = false;
    }
}

bool Dijkstra(int g, int s) {
    fill(dis[g], dis[g] + 1100, INF);
    dis[g][s] = 0;
    // only compute house and station(a GS)
    for (int i = 1; i <= N + M; i++) {
        int min = INF, u = -1;
        for (int j = 1; j <= N + M; j++) {
            if (visit[j] == false && dis[g][j] < min) {
                u = j;
                min = dis[g][j];
            }
        }
        if (u == -1) return true;
        visit[u] = true;
        //cout << "[minDis]: " << u << "-->" << dis[g][u] << endl;
        //if (dis[g][u] > D)            // spend 30min
        if (dis[g][u] > D && u <= N) {
            return false;
        }
        for (int j = 1; j <= N + M; j++) {
            if (visit[j] == false && G[u][j] != 0) {
                if (dis[g][u] + G[u][j] < dis[g][j]) {
                    dis[g][j] = dis[g][u] + G[u][j];
                }
            }
        }
    }
}

int main() {
    cin >> N >> M >> K >> D;
    for (int i = 0; i < K; i++) {
        string p1, p2, temp;
        int pp1, pp2, d;
        cin >> p1 >> p2 >> d;
        if (!isdigit(p1[0])) {
            //pp1 = p1[1] - '0' + N;                // spend 1h
            pp1 = stoi(p1.substr(1, p1.length() - 1)) + N;
        } else pp1 = p1[0] - '0';
        if (p2[0] == 'G') {
            //pp2 = p2[1] - '0' + N;
            pp2 = stoi(p2.substr(1, p2.length() - 1)) + N;
        } else pp2 = p2[0] - '0';
        //cout << "\n[debug]: " << pp1 << " - " << pp2 << " - " << d << endl;
        G[pp1][pp2] = G[pp2][pp1] = d;
    }
    OptSolu os;
    for (int i = 1; i <= M; i++) {
        if (Dijkstra(i ,N + i)) {
            OptSolu tempOs;
            tempOs.computeOptG(i);
            //cout << "<----------------->" << endl;
            // << "[compara]: " << tempOs << " ? " << os <<endl;
            if (tempOs < os) {
                os = tempOs;
            }
            //cout << "[result]: " << os.id << endl;
        } /* else {
            dis[i][0] = -1;
            //cout << "[false]: " << i << endl;
        } */
        visitInit();                // spend 20min
    }
    if (os.id == INF) {               // spend 10min
        cout << "No Solution";
        return 0;
    }
    /* double averageS { 0.0 };                       // spend 1h
    int solutionNum { 0 };
    for (int i = 1; i <= M; i++) {
        //if (dis[i][0] != -1 && i != os.id)          
        if (i != os.id ) {
            solutionNum++;
            averageS += dis[os.id][i + N];
            //cout << "-->" << dis[os.id][i + N];     // spend 20min [i] forget add N
        }
    }
    averageS /= solutionNum; */
    printf("G%d\n%.1f %.1f\n", os.id, os.disGH * 1.0, os.aveDisHou);
    return 0;
}

/*

test data:
    4 3 11 5
    1 2 2
    1 4 2
    1 G1 4
    1 G2 3
    2 3 2
    2 G2 1
    3 4 2
    3 G3 2
    4 G1 3
    G2 G1 4         // modify
    G3 G2 2

*/