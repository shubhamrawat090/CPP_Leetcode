class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();

        // using # for visited
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int w) {
        int rows = board.size(), cols = board[0].size();

        if (i < 0 || j < 0 || i == rows || j == cols)
            return false;
        if (board[i][j] == '#')
            return false;
        if (board[i][j] != word[w])
            return false;
        // Might not need the below condition
        if (w == word.size() - 1 && word[w] == board[i][j])
            return true;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        bool result = dfs(board, i + 1, j, word, w + 1) ||
                      dfs(board, i - 1, j, word, w + 1) ||
                      dfs(board, i, j + 1, word, w + 1) ||
                      dfs(board, i, j - 1, word, w + 1);

        board[i][j] = temp; // Backtrack

        return result;
    }
};