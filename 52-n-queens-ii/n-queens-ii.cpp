class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        int ans = 0;
        helper(board, n, ans, 0);
        return ans;
    }

    void helper(vector<vector<bool>>& board, int n, int& ans, int row) {
        if(row == n) {
            ans++;
            return;
        }

        for(int col=0; col<n; col++) {
            board[row][col] = true;
            if(isSafe(board, n, row, col)) {
                helper(board, n, ans, row+1);
            }
            board[row][col] = false;
        }
    }

    bool isSafe(vector<vector<bool>>& board, int n, int row, int col) {
        // top->bottom
        for(int r=0; r<row; r++) {
            if(board[r][col] == true) {
                return false;
            }
        }
        // left->right
        for(int c=0; c<col; c++) {
            if(board[row][c] == true) {
                return false;
            } 
        }

        // left diagonal
        // top-half
        int r=row-1, c=col-1;
        while(r>=0 && c>=0) {
            if(board[r][c] == true) {
                return false;
            }
            r--, c--;
        }

        // right diagonal
        // top-half
        r=row-1, c=col+1;
        while(r>=0 && c<n) {
            if(board[r][c] == true) {
                return false;
            }
            r--, c++;
        }

        return true; // None of the condition caught pre-existing queen
    }
};