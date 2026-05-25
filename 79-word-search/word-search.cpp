class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                vector<vector<int>> visited(rows, vector<int>(cols, false));
                if (helper(board, word, visited, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string& word,
                vector<vector<int>>& visited, int i, int j, int w) {
        if (w == word.size())
            return true;
            
        int rows = board.size(), cols = board[0].size();

        if (i < 0 || j < 0 || i >= rows || j >= cols)
            return false;
        if (visited[i][j])
            return false;

        if (board[i][j] != word[w])
            return false;

        visited[i][j] = true;

        bool sol1 = helper(board, word, visited, i + 1, j, w + 1);
        bool sol2 = helper(board, word, visited, i - 1, j, w + 1);
        bool sol3 = helper(board, word, visited, i, j + 1, w + 1);
        bool sol4 = helper(board, word, visited, i, j - 1, w + 1);

        visited[i][j] = false;

        return sol1 || sol2 || sol3 || sol4;
    }
};