#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
struct Records {
    string id;
    int _time;
    string status;
    bool valid;
}rec[10010];

int timeToS(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

bool cmp(Records A, Records B) {
    if(A.id != B.id) 
        return A.id < B.id;
    else 
        return A._time < B._time;
}

bool cmp2(Records A, Records B){
    return A._time < B._time;
}

int main() {
    int N, K;
    cin >> N >> K;
    int hh, mm, ss;
    for(int i = 0; i < N; i++) {
        cin >> rec[i].id;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        rec[i]._time = timeToS(hh, mm, ss);
        cin >> rec[i].status;
    }
    sort(rec, rec + N, cmp);
    map<string, int> mp;    //in time
    int max_time = -1;
    for(int i = 0; i < N;) {
        if(rec[i].id == rec[i + 1].id && rec[i].status + rec[i + 1].status == "inout") {
            rec[i].valid = rec[i + 1].valid = true;
            if(mp.find(rec[i].id) == mp.end())
                mp[rec[i].id] = 0;
            mp[rec[i].id] += rec[i + 1]._time - rec[i]._time;
            max_time = max(max_time, mp[rec[i].id]); //update max_time
            i += 2;
        } else {
            rec[i++].valid = false;
        }
    }
    sort(rec, rec + N, cmp2);
    int now = 0, numCar = 0;
    for(int i = 0; i < K; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int temp_time = timeToS(hh, mm, ss);
        while(now < N && rec[now]._time <= temp_time) {
            if(rec[now].valid) {
                if(rec[now].status == "in")
                    numCar++;
                else
                    numCar--;
            }
            now++;
            //cout << "now = " << now << "numCar = " << numCar << endl;
        }
        cout << numCar << endl;
    }
    map<string, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); ++it) {
        if(it->second == max_time)
            cout << it->first << " ";
    }
    printf("%02d:%02d:%02d\n", max_time / 3600, max_time % 3600 / 60, max_time % 60);
    return 0;
}
