class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int sum = 0;
        for(int i=0; i<rows; i++) {
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        sum = 0;
        for(int j=0; j<cols; j++) {
            sum += grid[0][j];
            dp[0][j] = sum;
        }

        for(int i=1; i<rows; i++) {
            for(int j=1; j<cols; j++) {
                dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
            }
        }

        return dp[rows-1][cols-1];
    }
};