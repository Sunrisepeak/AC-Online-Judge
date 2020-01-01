#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool callatz_hash[1010]{ false }; 
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    vector<int> input;
    int N, x;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x;
        input.push_back(x);
        while(x != 1) {
            if(x % 2 == 0) {
                x /= 2;
            } else {
                x = (3*x + 1) / 2;
            }
            callatz_hash[x] = true;
        }
    }

    sort(input.begin(), input.end(), cmp);
    bool is_first = true;
    for(auto v : input) {
        if(callatz_hash[v] == false) {
            if(is_first) {
                cout << v;
                is_first = false;
            }else {
                cout << " " << v;
            }
        }
    }
    return 0;
}
