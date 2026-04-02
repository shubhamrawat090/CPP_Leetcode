class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 0;
        string ans = "";
        for(int diff = 0; diff < n; diff++) {
            for(int i=0, j=i+diff; j<n; i++, j++) {
                // dp[i][j] --> substring between index i, j
                if(i == j) {
                    // 0 difference
                    dp[i][j] = 1;
                } else if(diff == 1) {
                    // 2 chars long string, i to j.
                    if(s[i] == s[j]) {
                        // if only 2 chars and both same then length = 2
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = 0;
                    }
                } else {
                    int isSmallerStrPalindrome = dp[i+1][j-1]; // i, i+1......j-1, j => i+1, j-1 is smaller substring
                    if(s[i] == s[j] && isSmallerStrPalindrome) {
                        dp[i][j] = 2 + dp[i+1][j-1]; 
                    }
                }

                if(dp[i][j] > 0) {
                    if(j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        ans = s.substr(i, maxLen); // substring is between i to j
                    }
                }
            }
        }
        return ans;
    }
};