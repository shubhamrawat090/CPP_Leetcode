class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<bool> dp(n, false);
        int start = 0, maxLen = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                if (s[i] == s[j] && (j - i <= 1 || dp[j - 1])) {
                    dp[j] = true;
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                } else {
                    dp[j] = false;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
