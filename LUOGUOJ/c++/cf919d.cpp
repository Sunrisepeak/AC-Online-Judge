#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

vector<int> G[300001];
// <char, vertex>: length of path about 'a' from vertex
int dp[128][300001] { {0} }, N, M;
string str;
bool inDeNZero[300001] = { false }, acRecord[300001] = { false };

bool existRound = false;
int DP(char c, int v) {
    //cout << "[debug-AR]: " << c << "-" << v << endl;
    if (acRecord[v] == true) {
        existRound = true;
        return -1;
    } else if (dp[c][v] >= 0) {
        return dp[c][v];
    } else if (G[v].size() == 0) {
        dp[c][v] = (str[v - 1] == c);
    } else {
        acRecord[v] = true;
        for (int j = 0; j < G[v].size(); j++) {
            if (existRound == true) break;
            dp[c][v] = max(dp[c][v], DP(c, G[v][j]) + (str[v - 1] == c));
            /**
             * note:
             *      dp[c][v] = max{
             *          DP(c, G[v][j]) + (Is v map of char variable c?)[bool: 0 or 1]
             *          j = {adjecent vertex}
             *      }
             * 
            */
        }
        acRecord[v] = false;    // remove access record
    }
    return dp[c][v];
}

int main() {
    cin >> N >> M >> str;
    memset(dp, -1, sizeof(dp[0]) * 128);
    for (int i = 1; i <= M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        if (v1 == v2) {
            existRound = true;    
        }
        G[v1].push_back(v2);
        inDeNZero[v2] = true;
    }
    int ans = -1;
    for (int i = 1; i <= N; i++) {
        if (existRound == true) break;
        if (inDeNZero[i] == false) {
            for (int j = 'a'; j <= 'z'; j++) {  // note: str.length + hash [TLE]
                int value = DP(j, i);
                if (existRound == true) {
                    ans = -1;
                    break;
                } else if (value > ans) {
                    ans = value;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

/**
test data:
input:
    4 3
    qwer
    1 3
    3 4
    4 3

output:    
    -1
*/