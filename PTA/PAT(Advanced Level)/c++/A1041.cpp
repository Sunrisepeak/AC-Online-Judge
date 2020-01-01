#include <iostream>
#include <vector>
using namespace std;
int number_hash[11] = { 0 };

bool isUnique(int m) {
    while(m){
        if(number_hash[m % 10] != 1)
            return false;
        m /= 10;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    int temp;
    vector<int> mars;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        mars.push_back(temp);
        while(temp) {
            number_hash[temp % 10]++;
            temp /= 10;
        }
    }
    for(const auto v : mars) {
        if(isUnique(v)) {
            cout << v;
            break;
        }
    }
    return 0;
}
