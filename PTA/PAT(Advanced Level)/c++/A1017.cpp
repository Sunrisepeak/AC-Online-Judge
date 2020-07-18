#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



struct Custmmers {
    int arriveTime { 0 };     // s
    int sTime { 0 };          

    Custmmers(const int &ar, const int &st) : arriveTime{ ar }, sTime{ st } {}
};

vector<Custmmers> cts;

bool cmp(const Custmmers &A, const Custmmers &B) {
    return A.arriveTime < B.arriveTime;
}

int strToSec(const string &ar) {
    return stoi(ar.substr(0, 2)) * 3600 + 
           stoi(ar.substr(3, 2)) * 60 + stoi(ar.substr(6));
}

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string t1;
        int t2;
        cin >> t1 >> t2;
        int ar = strToSec(t1);
        if (ar > 17 * 3600) continue;
        cts.push_back(Custmmers(ar, min(t2, 60) * 60));
    }
    sort(cts.begin(), cts.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> curTime(K, 8 * 3600);
    int waitTime = 0;
    for (int i = 0; i < cts.size(); i++) {
        int ct = curTime.top();
        curTime.pop();
        if (cts[i].arriveTime < ct) {
            waitTime += ct - cts[i].arriveTime;
            ct += cts[i].sTime;
        } else {
            ct = cts[i].arriveTime + cts[i].sTime;
        }
        curTime.push(ct);
    }
    if (cts.size() == 0) cout << "0.0";
    else printf("%.1f", waitTime * 1.0 / (cts.size() * 60));
    return 0;
}
