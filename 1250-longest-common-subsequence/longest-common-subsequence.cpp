class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        // return recursive(text1, text2, m-1, n-1);
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoize(text1, text2, m-1, n-1, dp);
        return tabulate(text1, text2, m, n);
    }

    int tabulate(string text1, string text2, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }

    int memoize(string text1, string text2, int i, int j, vector<vector<int>>& dp) {
        int m = text1.size(), n = text2.size();
        if(i == m || j == n) return 0;

        if(i == -1 || j == -1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = memoize(text1, text2, i-1, j-1, dp) + 1;
        } else {
            ans = max(memoize(text1, text2, i-1, j, dp), memoize(text1, text2, i, j-1, dp));
        }

        return dp[i][j] = ans;
    }

    int recursive(string text1, string text2, int i, int j) {
        int m = text1.size(), n = text2.size();
        if(i == m || j == n) return 0;

        if(i == -1 || j == -1) return 0;

        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = recursive(text1, text2, i-1, j-1) + 1;
        } else {
            ans = max(recursive(text1, text2, i-1, j), recursive(text1, text2, i, j-1));
        }

        return ans;
    }
};