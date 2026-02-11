class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        int maxVal = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(i == 0 || j == 0) {
                    if(matrix[i][j] == '1') {
                        dp[i][j] = 1;
                    } 
                } else {
                    if(matrix[i][j] == '1') {
                        dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    }
                }
                maxVal = max(maxVal, dp[i][j]);
            }
        }
        return maxVal * maxVal;
    }
};