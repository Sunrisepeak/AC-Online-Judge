#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> m = {
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
};

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) { 
    if (matrix.size() == 0) return false;
    int x = 0, y = matrix[0].size() - 1;
    while (y >= 0 && x < matrix.size() && matrix[x][y] != target) {
	//cout << x << " : " << y << endl;
        if (matrix[x][y] < target) x++;
        else y--;
    }
    //cout << x << " " << y << " : " << m[x][y] << endl;
    return y >= 0 && x < matrix.size() && matrix[x][y] == target;
}

int main() {
    for (int i = 0; i < m.size(); i++) {
	for (int j = 0; j < m[0].size(); j++) {
	    cout << " " << findNumberIn2DArray(m, m[i][j]);
	}
	cout << endl;
    }
    return 0;
}
