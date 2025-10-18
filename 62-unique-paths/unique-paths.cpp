class Solution {
public:
    int uniquePaths(int m, int n) {
        // return uniquePathsRecursive(0, 0, m, n);

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePathsMemoized(0, 0, m, n, dp);
    }

    int uniquePathsMemoized(int i, int j, int rows, int cols, vector<vector<int>>& dp) {
        if(i == rows - 1 && j == cols - 1) {
            return 1;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int downPaths = 0, rightPaths = 0;

        // Can I go down?
        if(i < rows - 1) {
            downPaths += uniquePathsMemoized(i+1, j, rows, cols, dp);
        }
        // Can I go right?
        if(j < cols - 1) {
            rightPaths += uniquePathsMemoized(i, j+1, rows, cols, dp);
        }

        return dp[i][j] = downPaths + rightPaths;
    }

    int uniquePathsRecursive(int i, int j, int rows, int cols) {
        if(i == rows - 1 && j == cols - 1) {
            return 1;
        }

        int downPaths = 0, rightPaths = 0;

        // Can I go down?
        if(i < rows - 1) {
            downPaths += uniquePathsRecursive(i+1, j, rows, cols);
        }
        // Can I go right?
        if(j < cols - 1) {
            rightPaths += uniquePathsRecursive(i, j+1, rows, cols);
        }

        return downPaths + rightPaths;
    }
};