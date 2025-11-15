class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        vector<vector<string>> ans;
        helper(board, n, ans, 0);
        return ans;
    }

    void helper(vector<vector<bool>>& board, int n, vector<vector<string>>& ans, int row) {
        if(row == n) {
            // build the answer board
            vector<string> ansBoard = buildStrBoard(board);
            ans.push_back(ansBoard);
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

    vector<string> buildStrBoard(vector<vector<bool>>& board) {
        vector<string> ans;
        for(vector<bool> row: board) {
            string str = "";
            for(bool val: row) {
                if(val == false) {
                    str.push_back('.');
                } else {
                    str.push_back('Q');
                }
            }
            ans.push_back(str);
        }
        return ans;
    }

    bool isSafe(vector<vector<bool>>& board, int n, int row, int col) {
        // top->bottom
        for(int r=0; r<n; r++) {
            if(r != row && board[r][col] == true) {
                return false;
            }
        }
        // left->right
        for(int c=0; c<n; c++) {
            if(c != col && board[row][c] == true) {
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
        //bottom-half
        r=row+1, c=col+1;
        while(r<n && c<n) {
            if(board[r][c] == true) {
                return false;
            }
            r++, c++;
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
        // bottom-half
        r=row+1, c=col-1;
        while(r<n && c>=0) {
            if(board[r][c] == true) {
                return false;
            }
            r++, c--;
        }

        return true; // None of the condition caught pre-existing queen
    }
};