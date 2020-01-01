#include <ios>
#include <iostream>

using namespace std;
int mark_hash[110] = {0};
int main() {
    std::ios::sync_with_stdio(false);
    int N, K;
    cin >> N;
    int input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        mark_hash[input]++;
    }
    cin >> K;
    cin >> input;
    cout << mark_hash[input];
    for(int i = 1; i < K; i++) {
        cin >> input;
        cout << " " << mark_hash[input];
    }
    return 0;
}
