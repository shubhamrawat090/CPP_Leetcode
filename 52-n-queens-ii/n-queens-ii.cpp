class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(board, n, 0, ans);
        return ans;
    }

    void solve(vector<vector<char>>& board, int n, int row, int& ans) {
        if (row == n) {
            ans++;
            return;
        }

        for (int col = 0; col < n; col++) {
            board[row][col] = 'Q';
            if (isSafe(row, col, board, n)) {
                solve(board, n, row + 1, ans);
            }
            board[row][col] = '.';
        }
    }

    bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
        // Same row
        for (int c = 0; c < n; c++) {
            if (c == col)
                continue;
            if (board[row][c] == 'Q')
                return false;
        }
        // upward
        for (int r = 0; r < row; r++) {
            if (board[r][col] == 'Q')
                return false;
        }

        // top-left diag
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // top-right diag
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
};