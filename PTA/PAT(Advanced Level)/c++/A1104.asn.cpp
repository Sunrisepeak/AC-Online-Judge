#include <iostream>

using namespace std;

/* Regular:
 * 1 2 3 4 5 ... n
 * 1 -> n
 * 2 -> (n - 1) + (n - 1) = 2 (n - 1)
 * 3 -> (n - 2) + (n - 1 - 1) + (n - 2) = 3 (n - 2)
 * ....
 * n -> i (n - i + 1)
 * */

int main() {
    double input, sum { 0.0 };
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> input;
        //int times = i * (N - i + 1); // overflow for int
        long long times = (long long)i * (N - i + 1);
        sum += input * times;
        //sum += input * i * (N - i + 1); // is ok becase of input * i improve to double
    }
    //cout << ans << endl;
    printf("%.2f", sum);
    return 0;
}
