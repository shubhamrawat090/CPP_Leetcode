class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(board, n, 0, 0, ans);
        return ans;
    }

    void solve(vector<vector<char>>& board, int n, int row, int queens,
               vector<vector<string>>& ans) {
        if (row == n) {
            if (queens == n) {
                insertBoard(board, ans, n);
            }
            return;
        }

        for (int col = 0; col < n; col++) {
            board[row][col] = 'Q';
            if (isSafe(row, col, board, n)) {
                solve(board, n, row + 1, queens + 1, ans);
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

    void insertBoard(vector<vector<char>>& board, vector<vector<string>>& ans,
                     int n) {
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = 0; j < n; j++) {
                str.push_back(board[i][j]);
            }
            res.push_back(str);
        }
        ans.push_back(res);
    }
};