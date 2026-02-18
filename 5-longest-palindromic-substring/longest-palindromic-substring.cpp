class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int maxLen = 0, index = 0, secondIdx = 0;
        for (int diff = 0; diff < n; diff++) {
            for (int i = 0, j = i + diff; j < n; i++, j++) {
                if (i == j) {
                    dp[i][j] = 1;
                } 
                else if (diff == 1) {
                    // 2 chars, match 2, no match 0
                    if (s[i] == s[j]) {
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = 0;
                    }
                } 
                else {
                    // match -> get bottom left value + 2(ith and jth chars)
                    if (s[i] == s[j] 
                    && dp[i + 1][j - 1]
                    ) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }

                if (dp[i][j] > 0) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        index = i;
                        secondIdx = j;
                    }
                }
            }
        }

        cout << "Str, maxLen, i, j: " << s << ", " << maxLen << ", " << index
             << ", " << secondIdx << endl;
        return maxLen == 0 ? "" : s.substr(index, maxLen);
    }
};