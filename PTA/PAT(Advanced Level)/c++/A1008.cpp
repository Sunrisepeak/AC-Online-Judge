#include <iostream>

using namespace std;

int main() {
    int N, input;
    cin >> N;
    int up_time{ 0 }, down_time{ 0 };
    int current_floor = 0;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input > current_floor) {
            up_time += (input - current_floor) * 6;
        } else {
            down_time += (current_floor - input) * 4;
        }
        current_floor = input;
    }
    int stop_time = N * 5;
    int total_time = stop_time + up_time + down_time;
    cout << total_time;
    return 0;
}
