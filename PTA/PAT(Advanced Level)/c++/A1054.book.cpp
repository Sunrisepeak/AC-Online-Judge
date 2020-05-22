// run time: 64ms

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    map<int, int> image;
    int M, N;
    cin >> M >> N;
    int max = 0, ans;
    for (int i = 0; i < M * N; i++) {
        int temp;
        cin >> temp;
        if (image.find(temp) != image.end()) {
            image[temp]++;
        } else {
            image[temp] = 1;
        }
        if (image[temp] > max) {
            ans = temp;
            max = image[temp];
        }
        //if (max >= M * N / 2) break;
    }
    cout << ans << endl;
    return 0;
}