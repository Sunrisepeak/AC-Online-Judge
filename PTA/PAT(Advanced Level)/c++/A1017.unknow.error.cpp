#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Custmmers {
    int arriveTime { 0 };     // s
    int sTime { 0 };          

    void set(const string &ar, const int &st) {
        sTime = min(st, 60) * 60;
        arriveTime = stoi(ar.substr(0, 2)) * 3600 + 
                     stoi(ar.substr(3, 2)) * 60 + stoi(ar.substr(6));
    }
};

vector<Custmmers> cts;

bool cmp(const Custmmers &A, const Custmmers &B) {
    return A.arriveTime < B.arriveTime;
}

int main() {
    int N, K;
    cin >> N >> K;
    cts.resize(N);
    for (int i = 0; i < N; i++) {
        string t1;
        int t2;
        cin >> t1 >> t2;
        cts[i].set(t1, t2);
    }
    sort(cts.begin(), cts.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> curTime(K, 8 * 3600);
    int waitTime = 0, numServed;
    for (numServed = 0; numServed < N; numServed++) {
        if (cts[numServed].arriveTime > 17 * 3600) break;
        int ct = curTime.top();
        if (ct >= 17 * 3600) continue;         // stop server 

        curTime.pop();
        if (cts[numServed].arriveTime < ct) {
            waitTime += ct - cts[numServed].arriveTime;
            ct += cts[numServed].sTime;
        } else {
            ct = cts[numServed].arriveTime + cts[numServed].sTime;
        }
        curTime.push(ct);
    }
    if (numServed == 0) cout << "0.0";
    else printf("%.1lf", waitTime * 1.0 / (numServed * 60));
    return 0;
}

/**
 *  score: 23
 *  last case:  answer error
 * 
 *  please look A1017.cpp:
 *          A1017.cpp deal with '> 17H' before calaulate wait-time   -->   AC
 *          the version is after deal with it['> 17H'].              -->   partially correct
*/