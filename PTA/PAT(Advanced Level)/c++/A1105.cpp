#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> SpiralMatrix;
int n = 1, m = 1, N;

int main() {
    cin >> N;
    bool isFind = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (i * j == N) {
                m = i, n = j;
                isFind = true;
                break;
            }
        }
        if (isFind) break;
    }
    SpiralMatrix.resize(m, vector<int>(n, -1));
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    int x { 0 }, y { -1 };
    int total = 0;
    while (total < N) {
        while (y + 1 < n && SpiralMatrix[x][y + 1] == -1) SpiralMatrix[x][++y] = nums[total++];
        while (x + 1 < m && SpiralMatrix[x + 1][y] == -1) SpiralMatrix[++x][y] = nums[total++];
        while (0 <= y - 1 && SpiralMatrix[x][y - 1] == -1) SpiralMatrix[x][--y] = nums[total++];
        while (0 <= x - 1 && SpiralMatrix[x - 1][y] == -1) SpiralMatrix[--x][y] = nums[total++];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << SpiralMatrix[i][j] << " ";
        }
        cout << SpiralMatrix[i][n - 1] << endl;
    }
    return 0;
}