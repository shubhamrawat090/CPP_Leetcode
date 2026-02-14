class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(m);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[j][i] == 1) {
                    dp[j] = 0;
                } else if(j > 0) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        return dp[m - 1];
    }
};