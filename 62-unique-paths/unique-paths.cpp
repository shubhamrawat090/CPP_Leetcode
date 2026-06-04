class Solution {
public:
    int uniquePaths(int m, int n) {
        // return recursive(0, 0, m, n);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return memoized(0, 0, m, n, dp);
    }

    int memoized(int i, int j, int rows, int cols, vector<vector<int>>& dp) {
        if (i == rows || j == cols)
            return 0; // out of bounds
        if (i == rows - 1 && j == cols - 1)
            return 1; // reached end +1 possible path
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = memoized(i, j + 1, rows, cols, dp);
        int down = memoized(i + 1, j, rows, cols, dp);
        return dp[i][j] = right + down;
    }

    int recursive(int i, int j, int rows, int cols) {
        if (i == rows || j == cols)
            return 0; // out of bounds
        if (i == rows - 1 && j == cols - 1)
            return 1; // reached end +1 possible path
        int right = recursive(i, j + 1, rows, cols);
        int down = recursive(i + 1, j, rows, cols);
        return right + down;
    }
};