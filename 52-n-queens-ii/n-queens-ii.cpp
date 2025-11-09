class Solution {
public:
    int sol = 0;
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        func(board, n, 0);
        return sol;
    }

    void func(vector<vector<bool>>& board, int n, int row) {
        if(row == n) {
            sol++;
            return;
        }

        for(int col=0; col<n; col++) {
            board[row][col] = true;
            if(isValid(board, n, row, col)) {
                func(board, n, row+1);
            }
            board[row][col] = false;
        }
    }


    bool isValid(vector<vector<bool>>& board, int n, int row, int col) {
        for(int i=0; i<n; i++) {
            if(i != col && board[row][i]) return false;
        }
        for(int i=0; i<n; i++) {
            if(i != row && board[i][col]) return false;
        }
        int tr, tc;
        tr = row+1, tc = col+1;
        while(tr<n && tc <n) {
            if(board[tr][tc]) return false;
            tr++, tc++;
        }
        tr = row+1, tc = col-1;
        while(tr<n && tc >=0) {
            if(board[tr][tc]) return false;
            tr++, tc--;
        }
        tr = row-1, tc = col-1;
        while(tr>=0 && tc >=0) {
            if(board[tr][tc]) return false;
            tr--, tc--;
        }
        tr = row-1, tc = col+1;
        while(tr>=0 && tc <n) {
            if(board[tr][tc]) return false;
            tr--, tc++;
        }
        return true;
    }
};