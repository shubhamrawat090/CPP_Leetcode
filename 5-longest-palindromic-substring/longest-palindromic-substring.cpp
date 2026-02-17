class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int maxLen = 0;
        string ans;
        for (int diff = 0; diff < n; diff++) {
            for (int i = 0, j = i + diff; j < n; i++, j++) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (diff == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = 0;
                    }
                } else {
                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }

                if (dp[i][j] > 0) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        ans = s.substr(i, maxLen);
                    }
                }
            }
        }

        return ans;
    }
};