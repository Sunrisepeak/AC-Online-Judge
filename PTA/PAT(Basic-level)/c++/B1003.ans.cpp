#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        int num_p { 0 }, num_t{ 0 };
        int pos_p { -1 }, pos_t{ -1 };
        bool isNo = false;
        for (int j = 0; j < input.length(); j++) {
            if (input[j] == 'P') {
                num_p++;
                pos_p = j;
            } else if (input[j] == 'T') {
                num_t++;
                pos_t = j;
            } else if (input[j] != 'A') {
                isNo = true;
                break;
            }
        }
        if (isNo || num_p != 1 || num_t != 1 || pos_t - pos_p <= 1) {
            cout << "NO" << endl;
            continue;
        }
        int l_a = pos_p, mid_a = pos_t - pos_p - 1, r_a = input.size() - pos_t - 1;
        if (r_a == l_a * mid_a) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}
