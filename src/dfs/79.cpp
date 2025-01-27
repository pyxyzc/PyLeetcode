#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool inArea(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

bool dfs(vector<vector<char>>& board, string& word, int i, int x, int y) {
    if (i == word.length()) { return true; }
    int m = board.size();
    int n = board[0].size();

    // 先保存当前字符，并将其标记为访问过
    char temp   = board[x][y];
    board[x][y] = '#';

    for (auto& dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (inArea(nx, ny, m, n) && board[nx][ny] == word[i]) {
            if (dfs(board, word, i + 1, nx, ny)) { return true; }
        }
    }

    // 恢复格子的状态
    board[x][y] = temp;

    return false;
}

bool exist(vector<vector<char>>& board, string& word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0] && dfs(board, word, 1, i, j)) { return true; }
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::string                    word  = "ABCCED";
    std::cout << "Board: \n";
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Word: " << word << std::endl;

    std::cout << exist(board, word) << std::endl;
}
