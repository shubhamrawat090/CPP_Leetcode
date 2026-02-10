class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxVal = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        bool hasOnes = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    if (matrix[i][j] != '0') {
                        dp[i][j] = 1;
                        hasOnes = true;
                    }
                } else {
                    if (matrix[i][j] != '0') {
                        hasOnes = true;
                        int minVal = min(dp[i - 1][j],
                                         min(dp[i][j - 1],
                                             dp[i - 1][j - 1]));
                        dp[i][j] = minVal + 1;
                    }
                }
                maxVal = max(maxVal, dp[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return maxVal * maxVal;
    }
};