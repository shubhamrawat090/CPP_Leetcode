class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string revS = s;
        reverse(revS.begin(), revS.end());
        int m = s.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1));
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=m; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if(s[i-1] == revS[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][m];
    }
};