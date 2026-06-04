class Solution {
public:
    int uniquePaths(int m, int n) {
        // return recursive(0, 0, m, n);
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return memoized(0, 0, m, n, dp);
        // return tabulate(m, n);
        return spaceOptimized(m, n);
    }

    int spaceOptimized(int rows, int cols) {
        vector<int> prev(cols, 1);
        vector<int> curr(cols);
        curr[0] = 1;
        for(int i=1; i<rows; i++) {
            for(int j=1; j<cols; j++) {
                curr[j] = prev[j] + curr[j-1];
            }
            prev = curr;
        }
        return prev[cols-1];
    }

    int tabulate(int rows, int cols) {
        vector<vector<int>> dp(rows, vector<int>(cols));
        for(int i=0; i<rows; i++) {
            dp[i][0] = 1;
        }
        for(int j=0; j<cols; j++) {
            dp[0][j] = 1;
        }

        for(int i=1; i<rows; i++) {
            for(int j=1; j<cols; j++) {
                int left = dp[i][j-1];
                int top = dp[i-1][j];
                dp[i][j] = left + top;
            }
        }

        return dp[rows-1][cols-1];
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