#include <iostream>

using namespace std;

int coins_hash[1010] = { 0 };

int main() {
    int N, M;
    cin >> N >> M;
    int x;
    for(int i = 0; i < N; i++) {
        cin >> x;
        coins_hash[x]++;
    }
    bool isOk = false;
    for(int i = 0; i <= M; i++) {
        if(coins_hash[i] && coins_hash[M - i]) {
            if(i == M - i && coins_hash[i] < 2) {
                continue;
            }
            cout << i << " " << M - i;
            isOk = true;
            break;
        }
    }
    if(!isOk) {
        cout << "No Solution";
    }
    return 0;
}
