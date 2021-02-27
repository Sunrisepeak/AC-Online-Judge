#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        hashValue.resize(board.size() * board[0].size(), false);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int index = 0;
                if (board[i][j] == word[0] && DFS(board, word, i, j, index)) return true;
            }
        }
        return false;
    }
private:
    vector<bool> hashValue;
    // Left, Up, Right, Down
    array<int, 4> moveX {0, -1, 0, 1};
    array<int, 4> moveY {-1, 0, 1, 0};

    bool DFS(const vector<vector<char>> &board, const string &word, int x, int y, int index) {
	//cout << string(index, '_') << x << " " << y << "  " << index << endl;
        // check border: hashValue Error from x + y to x * board[0].size() + y. spend 40min
        if (
	    x >= board.size() || x < 0 ||
	    y >= board[0].size() || y < 0 ||
	    hashValue[x * board[0].size() + y]
	) return false;
	
	cout << string(index, '~') << x << " " << y << "  " << index << endl;

        if (index + 1 == word.size()) return board[x][y] == word[index];    // exit
	

        hashValue[x * board[0].size() + y] = true;
        
	bool ans = false;
        if (board[x][y] == word[index]) {
            for (int i = 0; i < 4; i++) {
                ans |= DFS(board, word, x + moveX[i], y + moveY[i], index + 1);
		if (ans) break;
            }
        }

        hashValue[x * board[0].size() + y] = false;
        
        return ans;
    }
};

using vec = vector<char>;
vector<vector<char>> board = {
    vec{'A','B','C','E'},
    vec{'S','F','C','S'},
    vec{'A','D','E','E'}
};

string word = "ASFB";

int main() {
    Solution s;
    cout << s.exist(board, word) << endl;
    return 0;
}
