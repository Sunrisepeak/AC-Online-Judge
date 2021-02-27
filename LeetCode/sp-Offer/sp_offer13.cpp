class Solution {
public:
    int movingCount(int m, int n, int k) {
        visited = new bool[m * n];
        fill(visited, visited + m * n, false);
        int cnt = walk(m, n, k, 0, 0);
        delete [] visited;
        return cnt;
    }

private:
    bool *visited;
    int moveX[4] = {0, 1, 0, -1};
    int moveY[4] = {1, 0, -1, 0};

    int xySum(int x, int y) {
        string s = to_string(x) + to_string(y);
        int sum = 0;
        for (auto c : s) {
            sum += c - '0';
        }
        return sum;
    }

    int walk(int m, int n, int k, int x, int y) {
        if (x >= m || x < 0 || y < 0 || y >= n || visited[x * n + y] || xySum(x, y) > k) return 0;
        visited[x * n + y] = true;
        int sum = 0;
        // only toRight and toDown
        for (int i = 0; i < 2; i++) {
            sum += walk(m, n, k, x + moveX[i], y + moveY[i]);
        }
        return 1 + sum;
    }
};
