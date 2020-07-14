#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> coins, ans;

bool isOk = false;
void DFS(int begin, int sum) {
    if (sum == M) {
        isOk = true;
    } else if (sum < M) {
        for (int i = begin; i < coins.size(); i++) {
            ans.push_back(coins[i]);
            DFS(i + 1, sum + coins[i]);
            if (isOk) break;
            ans.pop_back();
        }
    }
}

void choiceSortOfRange(int range) {
    int j = 0; 
    for (int i = 0; i < range; i++) {
        int minIndex = i;
        for (int j = i; j < coins.size(); j++) {
            if (coins[j] < coins[minIndex]) {
                minIndex = j;
            }
        }
        swap(coins[i], coins[minIndex]);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    choiceSortOfRange(min(N, 100));
    DFS(0, 0);      // ---> TLE
    if (isOk == false) {
        cout << "No Solution";
    } else {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
    }
    return 0;
}

/**
 * score: 29
 * case 6: TLE 
*/